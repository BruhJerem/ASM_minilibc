/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test
*/

#include <stdio.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern int my_strcmp(char *, char *);
extern int my_strcasecmp(char *, char *);
extern int my_strncmp(char *, char *, size_t);
extern int my_strlen(char const *);
extern char *my_strchr(char const *, char);
extern void my_memset(void *, int, size_t);
extern void *my_memmove(void *, void *, size_t);
extern void my_memcpy(void *, void *, size_t);
extern char *my_strstr(const char *haystack, const char *needle);
extern char *my_rindex(const char *s, int c);
extern char *my_strpbrk(const char *s, const char *accept);
extern size_t my_strcspn(const char *s, const char *reject);


void test_cmp()
{
	printf("my_strcmp : %d\n", my_strcmp("TOP", "TOP"));
	printf("sys strcmp : %d\n", strcmp("TOP", "TOP"));
	printf("my_strcmp : %d\n", my_strcmp("TOP", "TAP"));
	printf("sys strcmp : %d\n", strcmp("TOP", "TAP"));
	printf("my_strcmp : %d\n", my_strcmp("TOP", "TOZ"));
	printf("sys strcmp : %d\n", strcmp("TOP", "TOZ"));
	printf("my_strcmp : %d\n", my_strcmp("TAP", "TOP"));
	printf("sys strcmp : %d\n", strcmp("TAP", "TOP"));
	printf("my_strcmp : %d\n", my_strcmp("TOZ", "TOP"));
	printf("sys strcmp : %d\n", strcmp("TOZ", "TOP"));
}

void test_len()
{
	char *str = "courge";

	printf("%s: %d\n", str, my_strlen(str));
	printf("%s: %d\n", str, strlen(str));
	if (my_strlen(str) != strlen(str))
		exit(84);
}

void test_chr()
{
	char *test = "AZERTYUIOP";
	void *a = 0;
	void *b = 0;

	a = my_strchr(test, 'A');
	b = strchr(test, 'A');
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("a %s\n", a);
		printf("b %s\n", b);
		exit(84);

	}
	a = my_strchr(test, 'Q');
	b = strchr(test, 'Q');
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("a %s\n", a);
		printf("b %s\n", b);
		exit(84);
	}
}


void test_memset()
{
	int size = 100;
	int *test1 = malloc(size * sizeof(int));
	int *test2 = malloc(size * sizeof(int));

	memset(test1, 1, sizeof(int) * size);
	my_memset(test2, 1, sizeof(int) * size);
	for (int i = 0; i < size * sizeof(int); i++) {
		if (((char *)test1)[i] != ((char *)test2)[i]) {
			printf("ERREUR MEMSET\n");
			exit(84);
		}
	}
	printf("Memset: OK\n");
}

void test_memcpy()
{
	int size = 100;
	int *test1 = malloc(size * sizeof(int));
	int *test2 = malloc(size * sizeof(int));

	memset(test1, 1, sizeof(int) * size);
	my_memcpy(test2, test1, sizeof(int) * size);
	for (int i = 0; i < size * sizeof(int); i++) {
		if (((char *)test1)[i] != ((char *)test2)[i]) {
			printf("ERREUR MEMCPY\n");
			exit(84);
		}
	}
	printf("Memcpy : OK\n");
}

void test_ncmp()
{
	printf("my_strncmp : %d\n", my_strncmp("TOP", "TOP", 3));
	printf("sys strncmp : %d\n", strncmp("TOP", "TOP", 3));
	printf("my_strncmp : %d\n", my_strncmp("TOP", "TAP", 3));
	printf("sys strncmp : %d\n", strncmp("TOP", "TAP", 3));
	printf("my_strncmp : %d\n", my_strncmp("TOP", "TOZ", 3));
	printf("sys strncmp : %d\n", strncmp("TOP", "TOZ", 3));
	printf("my_strncmp : %d\n", my_strncmp("TAP", "TOP", 3));
	printf("sys strncmp : %d\n", strncmp("TAP", "TOP", 3));
	printf("my_strncmp : %d\n", my_strncmp("TOZ", "TOP", 3));
	printf("sys strncmp : %d\n", strncmp("TOZ", "TOP", 3));

	printf("my_strncmp : %d\n", my_strncmp("TOP", "TOP", 2));
	printf("sys strncmp : %d\n", strncmp("TOP", "TOP", 2));
	printf("my_strncmp : %d\n", my_strncmp("TOP", "TAP", 2));
	printf("sys strncmp : %d\n", strncmp("TOP", "TAP", 2));
	printf("my_strncmp : %d\n", my_strncmp("TOP", "TOZ", 2));
	printf("sys strncmp : %d\n", strncmp("TOP", "TOZ", 2));
	printf("my_strncmp : %d\n", my_strncmp("TAP", "TOP", 2));
	printf("sys strncmp : %d\n", strncmp("TAP", "TOP", 2));
	printf("my_strncmp : %d\n", my_strncmp("TOZ", "TOP", 2));
	printf("sys strncmp : %d\n", strncmp("TOZ", "TOP", 2));

	printf("my_strncmp : %d\n", my_strncmp("TOP", "TOP", 1));
	printf("sys strncmp : %d\n", strncmp("TOP", "TOP", 1));
	printf("my_strncmp : %d\n", my_strncmp("TOP", "TAP", 1));
	printf("sys strncmp : %d\n", strncmp("TOP", "TAP", 1));
	printf("my_strncmp : %d\n", my_strncmp("TOP", "TOZ", 1));
	printf("sys strncmp : %d\n", strncmp("TOP", "TOZ", 1));
	printf("my_strncmp : %d\n", my_strncmp("TAP", "TOP", 1));
	printf("sys strncmp : %d\n", strncmp("TAP", "TOP", 1));
	printf("my_strncmp : %d\n", my_strncmp("TOZ", "TOP", 1));
	printf("sys strncmp : %d\n", strncmp("TOZ", "TOP", 1));

	printf("my_strncmp : %d\n", my_strncmp("TOP", "TOP", 4));
	printf("sys strncmp : %d\n", strncmp("TOP", "TOP", 4));
	printf("my_strncmp : %d\n", my_strncmp("TOP", "TAP", 4));
	printf("sys strncmp : %d\n", strncmp("TOP", "TAP", 4));
	printf("my_strncmp : %d\n", my_strncmp("TOP", "TOZ", 4));
	printf("sys strncmp : %d\n", strncmp("TOP", "TOZ", 4));
	printf("my_strncmp : %d\n", my_strncmp("TAP", "TOP", 4));
	printf("sys strncmp : %d\n", strncmp("TAP", "TOP", 4));
	printf("my_strncmp : %d\n", my_strncmp("TOZ", "TOP", 4));
	printf("sys strncmp : %d\n", strncmp("TOZ", "TOP", 4));

	printf("my_strncmp : %d\n", my_strncmp("", "", 4));
	printf("sys strncmp : %d\n", strncmp("", "", 4));
}

void test_strstr()
{
	char *test = "AZERTYUIOP";
	char *a = 0;
	char *b = 0;
	b = strstr(test, "");
	a = my_strstr(test, "");
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}


	test = "AZERTYUIOP";
	a = my_strstr(test, "UIOP");
	b = strstr(test, "UIOP");
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}

	test = "AZERTYUIOP";
	a = my_strstr(test, "UIOP1");
	b = strstr(test, "UIOP1");
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}

	test = "AZERTY";
	a = my_strstr(test, "UIOP1");
	b = strstr(test, "UIOP1");
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}

	test = "AZERTYUIOP";
	a = my_strstr(test, "");
	b = strstr(test, "");
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}
}
void test_casecmp()
{
	printf("my_strcasecmp : %d\n", my_strcasecmp("TOP", "TOP"));
	printf("sys strcasecmp : %d\n", strcasecmp("TOP", "TOP"));
	printf("my_strcasecmp : %d\n", my_strcasecmp("TOP", "TAP"));
	printf("sys strcasecmp : %d\n", strcasecmp("TOP", "TAP"));
	printf("my_strcasecmp : %d\n", my_strcasecmp("TOP", "TOZ"));
	printf("sys strcasecmp : %d\n", strcasecmp("TOP", "TOZ"));
	printf("my_strcasecmp : %d\n", my_strcasecmp("TAP", "TOP"));
	printf("sys strcasecmp : %d\n", strcasecmp("TAP", "TOP"));
	printf("my_strcasecmp : %d\n", my_strcasecmp("TOZ", "TOP"));
	printf("sys strcasecmp : %d\n", strcasecmp("TOZ", "TOP"));

	printf("my_strcasecmp : %d\n", my_strcasecmp("TOP", "top"));
	printf("sys strcasecmp : %d\n", strcasecmp("TOP", "top"));
	printf("my_strcasecmp : %d\n", my_strcasecmp("TOP", "tap"));
	printf("sys strcasecmp : %d\n", strcasecmp("TOP", "tap"));
	printf("my_strcasecmp : %d\n", my_strcasecmp("TOP", "toz"));
	printf("sys strcasecmp : %d\n", strcasecmp("TOP", "toz"));
	printf("my_strcasecmp : %d\n", my_strcasecmp("tap", "TOP"));
	printf("sys strcasecmp : %d\n", strcasecmp("tap", "TOP"));
	printf("my_strcasecmp : %d\n", my_strcasecmp("toz", "TOP"));
	printf("sys strcasecmp : %d\n", strcasecmp("toz", "TOP"));


	printf("1my_strcasecmp : %d\n", my_strcasecmp("TOP1", "top"));
	printf("sys strcasecmp : %d\n", strcasecmp("TOP1", "top"));
	printf("my_strcasecmp : %d\n", my_strcasecmp("TOP", "tap1"));
	printf("sys strcasecmp : %d\n", strcasecmp("TOP", "tap1"));
	printf("my_strcasecmp : %d\n", my_strcasecmp("TOP1", "toz"));
	printf("sys strcasecmp : %d\n", strcasecmp("TOP1", "toz"));
	printf("my_strcasecmp : %d\n", my_strcasecmp("tap", "TOP1"));
	printf("sys strcasecmp : %d\n", strcasecmp("tap", "TOP1"));
	printf("my_strcasecmp : %d\n", my_strcasecmp("toz1", "TOP"));
	printf("sys strcasecmp : %d\n", strcasecmp("toz1", "TOP"));
}

void test_rindex()
{
	char *test;
	char *b = 0;
	char *a = 0;

	test = "AZERTYUIOP";
	b = rindex(test, 'A');
	a = my_rindex(test, 'A');
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}

	test = "AZERTYUIAOP";
	b = rindex(test, 'A');
	a = my_rindex(test, 'A');
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}

	test = "ZERTYUIOP";
	b = rindex(test, 'A');
	a = my_rindex(test, 'A');
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}

	test = "AZERTYUIOP";
	b = rindex(test, 0);
	a = my_rindex(test, 0);
	printf("cmp %s : %d\n", test, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}
}

void test_strpbrk()
{
	char *str;
	char *accept;
	char *b = 0;
	char *a = 0;

	str = "AZERTYUIOP";
	accept = "POIUYTREZA";
	b = strpbrk(str, accept);
	a = my_strpbrk(str, accept);
	printf("cmp %s : %d\n", str, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}

	str = "AZERTYUIOP";
	accept = "";
	b = strpbrk(str, accept);
	a = my_strpbrk(str, accept);
	printf("cmp %s : %d\n", str, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}

	str = "AZERTYUIOP";
	accept = "QSDFGHJKLM";
	b = strpbrk(str, accept);
	a = my_strpbrk(str, accept);
	printf("cmp %s : %d\n", str, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}

	str = 0;
	accept = "";
	b = strpbrk(str, accept);
	a = my_strpbrk(str, accept);
	printf("cmp %s : %d\n", str, a == b);
	if (a != b) {
		printf("b %s\n", b);
		printf("a %s\n", a);
		exit(84);
	}
}

void test_cspn()
{
	char *str;
	char *accept;
	size_t b = 0;
	size_t a = 0;

	str = "AZERTYUIOP";
	accept = "POIUYTREZA";
	b = strcspn(str, accept);
	a = my_strcspn(str, accept);
	printf("cmp %s : %d\n", str, a == b);
	if (a != b) {
		printf("sys b %d\n", b);
		printf("my a %d\n", a);
		exit(84);
	}

	str = "AZERTYUIOP";
	accept = "A";
	b = strcspn(str, accept);
	a = my_strcspn(str, accept);
	printf("cmp %s : %d\n", str, a == b);
	if (a != b) {
		printf("b %d\n", b);
		printf("a %d\n", a);
		exit(84);
	}

	str = "AZERTYUIOP";
	accept = "AZ";
	b = strcspn(str, accept);
	a = my_strcspn(str, accept);
	printf("cmp %s : %d\n", str, a == b);
	if (a != b) {
		printf("sys b %d\n", b);
		printf("my a %d\n", a);
		exit(84);
	}
}


static void test_memmove()
{
	char data1[50];
	char data2[50];
	size_t size = 50;

	memset(data1, 0, size);
	memset(data2, 0, size);
	memset(data1, 1, 20);
	memset(data2, 1, 20);
	memmove(data1, data1 + 30, 0);
	my_memmove(data2, data2 + 30, 0);
	for (int i = 0; i < size; i++) {
		if (((char *)data1)[i] != ((char *)data2)[i]) {
			printf("%d %d\n", ((char *)data1)[i], ((char *)data2)[i]);
			printf("ERREUR MEMMOVE\n");
			exit(84);
		}
	}

	memset(data1, 0, size);
	memset(data2, 0, size);
	memset(data1, 1, 25);
	memset(data2, 1, 25);
	memmove(data1 + 25, data1 + 15, 25);
	my_memmove(data2 + 25, data2 + 15, 25);
	for (int i = 0; i < size; i++) {
		if (((char *)data1)[i] != ((char *)data2)[i]) {
			printf("%d %d\n", ((char *)data1)[i], ((char *)data2)[i]);
			printf("ERREUR MEMMOVE\n");
			exit(84);
		}
	}

	memset(data1, 0, size);
	memset(data2, 0, size);
	memset(data1, 1, 25);
	memset(data2, 1, 25);
	memmove(data1 + 15, data1 + 25, 25);
	my_memmove(data2 + 15, data2 + 25, 25);
	for (int i = 0; i < size; i++) {
		if (((char *)data1)[i] != ((char *)data2)[i]) {
			printf("%d %d\n", ((char *)data1)[i], ((char *)data2)[i]);
			printf("ERREUR MEMMOVE\n");
			exit(84);
		}
	}
	printf("Test Memmove : OK\n");
}


int main()
{
	printf("------------ %s ---------------\n", "strchr");
	test_chr();
	printf("------------ %s ---------------\n", "strcmp");
	test_cmp();
	printf("------------ %s ---------------\n", "strlen");
	test_len();
	printf("------------ %s ---------------\n", "memcpy");
	test_memcpy();
	printf("------------ %s ---------------\n", "memset");
	test_memset();
	printf("------------ %s ---------------\n", "strncmp");
	test_ncmp();
	printf("------------ %s ---------------\n", "strcasecmp");
	test_casecmp();
	printf("------------ %s ---------------\n", "rindex");
	test_rindex();
	printf("------------ %s ---------------\n", "strstr");
	test_strstr();
	printf("------------ %s ---------------\n", "strpbrk");
	test_strpbrk();
	printf("------------ %s ---------------\n", "strcspn");
	test_cspn();
	printf("------------ %s ---------------\n", "memmove");
	test_memmove();
	return (0);
}



/*int main(int ar, char **av)
{
*//*	extern char *strchr(const char *s, int c);
	char *s = strdup(av[1]);
	extern int strlen(const char *);


	// Fonctionne pas
	//extern void *memset(void *s, int c, size_t n);

	printf("Strlen check\n");
	int i = strlen(av[1]);
	printf("Strchr check\n");
	char *str = strdup(strchr(s, '.'));

	printf("LEN : %d\n", i);
	printf("CSMN %s\n", str);*//*
	extern size_t strcspn(const char *str1, const char *str2);

	int len;
	const char str1[] = "ABCDEF4960910";
	const char str2[] = "013";
	printf("Check strcspn\n");
	len = strcspn(str1, str2);
	printf("Function done\n");
	printf("First matched character is at %d\n", len + 1);
	return(0);


}*/
