#!/bin/bash

# Check if required arguments are provided
if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Usage: $0 <number_of_iterations> <num_values>"
    exit 1
fi

iterations=$1
num_values=$2
highest=0
lowest=9999999
total=0
timeout_limit=60  # Max total script runtime (seconds)
start_time=$(date +%s)  # Capture start time
completed=0

# Hide the cursor
tput civis

# Function to print results before exiting
print_results() {
    echo -e "\n\nBenchmark complete!"
    echo "Iterations completed: $completed"
    echo "Highest count: $highest"
    echo "Lowest count: $lowest"
    if [[ "$completed" -gt 0 ]]; then
        average=$((total / completed))
        echo "Average count: $average"
    else
        echo "Average count: N/A (All runs timed out)"
    fi
    # Restore the cursor
    tput cnorm
    exit 0
}

# Trap termination signals to print results on timeout
trap print_results SIGTERM SIGINT

# Start background timeout process
(
    sleep $timeout_limit
    printf "\n\nTimeout reached! Last iteration..."
    kill -TERM $$  # Send termination signal to trigger print_results
) &
timeout_pid=$!

# Run benchmark
echo "Running benchmark for $iterations iterations with $num_values unique numbers per test..."
for ((i=1; i<=iterations; i++)); do
    # Check if total time exceeded
    current_time=$(date +%s)
    elapsed_time=$((current_time - start_time))
    if [ "$elapsed_time" -ge "$timeout_limit" ]; then
        echo -e "\nTotal timeout reached! Ending benchmark."
        break
    fi

    # Generate unique random numbers
    numbers=$(shuf -i 0-20000 -n $num_values)

    # Run push_swap
    count=$(echo "$numbers" | xargs ./push_swap | wc -l)

    # If push_swap fails, handle it
    if [[ "$count" =~ ^[0-9]+$ ]]; then
        if (( count > highest )); then
            highest=$count
        fi
        if (( count < lowest )); then
            lowest=$count
        fi
        total=$((total + count))
    fi

    # Increment completed iterations
    ((completed++))

    # Display progress
    printf "\rProgress: %d/%d (Current: %s ops, Time: %ds)" "$completed" "$iterations" "$count" "$elapsed_time"
done

# Stop the timeout process
kill $timeout_pid 2>/dev/null

# Print final results
print_results
