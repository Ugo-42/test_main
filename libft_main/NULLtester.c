#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

static void	ft_test_ascii_functions(void)
{
	int	i;
	int	validity_mask;

	validity_mask = 0b1111111;
	for (i = -1; i < 256; i++)
	{
		if (!!ft_isalpha(i) != !!isalpha(i))
			validity_mask &= ~(1 << 0);
		if (!!ft_isdigit(i) != !!isdigit(i))
			validity_mask &= ~(1 << 1);
		if (!!ft_isalnum(i) != !!isalnum(i))
			validity_mask &= ~(1 << 2);
		if (!!ft_isascii(i) != !!isascii(i))
			validity_mask &= ~(1 << 3);
		if (!!ft_isprint(i) != !!isprint(i))
			validity_mask &= ~(1 << 4);
		if (ft_toupper(i) != toupper(i))
			validity_mask &= ~(1 << 5);
		if (ft_tolower(i) != tolower(i))
			validity_mask &= ~(1 << 6);
	}
	printf(" ft_isalpha : %s\n", (validity_mask & (1 << 0)) ? "OK" : "KO");
	printf(" ft_isdigit : %s\n", (validity_mask & (1 << 1)) ? "OK" : "KO");
	printf(" ft_isalnum : %s\n", (validity_mask & (1 << 2)) ? "OK" : "KO");
	printf(" ft_isascii : %s\n", (validity_mask & (1 << 3)) ? "OK" : "KO");
	printf(" ft_isprint : %s\n", (validity_mask & (1 << 4)) ? "OK" : "KO");
	printf(" ft_toupper : %s\n", (validity_mask & (1 << 5)) ? "OK" : "KO");
	printf(" ft_tolower : %s\n", (validity_mask & (1 << 6)) ? "OK" : "KO");
}

static void	ft_test_mem_functions(void)
{
	char	mem1[20];
	char	mem2[20];
	int	 	validity_mask;
	int		i;

	validity_mask = 0b111111;
	ft_memset(mem1, 'A', 10);
	memset(mem2, 'A', 10);
	if (memcmp(mem1, mem2, 10))
		validity_mask &= ~(1 << 0);
	//
	ft_bzero(mem1, 10);
	bzero(mem2, 10);
	if (memcmp(mem1, mem2, 10))
		validity_mask &= ~(1 << 1);
	//
	ft_memcpy(mem1, "Hello", 5);
	memcpy(mem2, "Hello", 5);
	if (memcmp(mem1, mem2, 5))
		validity_mask &= ~(1 << 2);
	//
	if (ft_memcmp("HE\0\x80HAAA", "HE\0\x80O", 4)
		!= memcmp("HE\0\x80HAAA", "HE\0\x80O", 4))
		validity_mask &= ~(1 << 3);
	//
	ft_memmove(mem1, mem1 + 3, 5);
	memmove(mem2, mem2 + 3, 5);
	if (memcmp(mem1, mem2, 5))
		validity_mask &= ~(1 << 4);
	ft_memmove(mem1 + 3, mem1, 5);
	memmove(mem2 + 3, mem2, 5);
	if (memcmp(mem1, mem2, 5))
		validity_mask &= ~(1 << 4);
	//
	i = -1;
	while (i < 256)
	{
		if (ft_memchr("Hello, World!", i, 13)
			!= memchr("Hello, World!", i, 13))
			validity_mask &= ~(1 << 5);
		i++;
	}
	printf(" ft_memset   : %s\n", (validity_mask & (1 << 0)) ? "OK" : "KO");
	printf(" ft_bzero    : %s\n", (validity_mask & (1 << 1)) ? "OK" : "KO");
	printf(" ft_memcpy   : %s\n", (validity_mask & (1 << 2)) ? "OK" : "KO");
	printf(" ft_memcmp   : %s\n", (validity_mask & (1 << 3)) ? "OK" : "KO");
	printf(" ft_memmove  : %s\n", (validity_mask & (1 << 4)) ? "OK" : "KO");
	printf(" ft_memchr   : %s\n", (validity_mask & (1 << 5)) ? "OK" : "KO");
}

static void	ft_test_substr(void)
{
	int	ko;

	ko = 0;
	write(1, " ft_substr    : ", 16);
	if (ft_substr(NULL, 0, 0)) ko = 1;
	if (!ft_substr("e", 0, 0)) ko = 2;
	if (!ft_substr("e", -1, -1)) ko = 3;
	if (!ft_substr("Hello, World!", 7, -1)) ko = 4;
	if (!ko) printf("OK\n"); else printf("KO (%d)\n", ko);
}

static void	ft_test_strjoin(void)
{
	int	ko;

	ko = 0;
	write(1, " ft_strjoin   : ", 16);
	ft_strjoin(NULL, "");
	ft_strjoin("", NULL);
	if (ft_strjoin(NULL, NULL)) ko = 1;
	if (strcmp(ft_strjoin("", ""), "")) ko = 2;
	if (strcmp(ft_strjoin("e", "a"), "ea")) ko = 3;
	if (!ko) printf("OK\n"); else printf("KO (%d)\n", ko);
}

static void	ft_test_strtrim(void)
{
	int	ko;

	ko = 0;
	write(1, " ft_strtrim   : ", 16);
	ft_strtrim("test", NULL);
	if (ft_strtrim(NULL, "t")) ko = 1;
	if (ft_strtrim(NULL, NULL)) ko = 2;
	if (strcmp(ft_strtrim("  test  ", " "), "test")) ko = 3;
	if (strcmp(ft_strtrim("xxHello Worldxx", "x"), "Hello World")) ko = 4;
	if (!ko) printf("OK\n"); else printf("KO (%d)\n", ko);
}

static void	ft_test_split(void)
{
	write(1, " ft_split     : ", 16);
	ft_split(NULL, ' ');
	printf("OK\n");
}

static void	ft_test_itoa(void)
{
	int	ko;

	ko = 0;
	write(1, " ft_itoa      : ", 16);
	if (strcmp(ft_itoa(0), "0")) ko = 1;
	if (strcmp(ft_itoa(-42), "-42")) ko = 2;
	if (strcmp(ft_itoa(123), "123")) ko = 3;
	if (strcmp(ft_itoa(2147483647), "2147483647")) ko = 4;
	if (strcmp(ft_itoa(-2147483648), "-2147483648")) ko = 5;
	if (!ko) printf("OK\n"); else printf("KO (%d)\n", ko);
}

static char	ft_fstrmapi(unsigned int i, char c)
{
	return (c + i);
}

static void	ft_test_strmapi(void)
{
	write(1, " ft_strmapi   : ", 16);
	ft_strmapi(NULL, ft_fstrmapi);
	ft_strmapi("", NULL);
	ft_strmapi(NULL, NULL);
	printf("OK\n");
}

static void	ft_fstriteri(unsigned int i, char *c)
{
	*c = i;
}

static void	ft_test_striteri(void)
{
	write(1, " ft_striteri  : ", 16);
	ft_striteri(NULL, ft_fstriteri);
	ft_striteri("", NULL);
	ft_striteri(NULL, NULL);
	printf("OK\n");
}

static void	ft_test_putstr_fd(void)
{
	write(1, " ft_putstr_fd : ", 16);
	ft_putstr_fd(NULL, 1);
	printf("OK\n");
}

static void	ft_test_putendl_fd(void)
{
	write(1, " ft_putendl_fd: ", 16);
	ft_putendl_fd(NULL, 1);
	printf("OK\n");
}

int	main(void)
{
	printf("Character-Functions:\n");
	ft_test_ascii_functions();
	printf("\nMemory----Functions:\n");
	ft_test_mem_functions();
	printf("\nPart_II---Functions:\n");
	ft_test_substr();
	ft_test_strjoin();
	ft_test_strtrim();
	ft_test_split();
	ft_test_itoa();
	ft_test_strmapi();
	ft_test_striteri();
	ft_test_putstr_fd();
	ft_test_putendl_fd();
	return (0);
}
