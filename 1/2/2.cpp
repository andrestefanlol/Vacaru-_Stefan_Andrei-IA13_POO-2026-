#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char s[250];
	char p[50][50];
	scanf("%[^\n]", s);
	char* t = strtok(s, " ");
	int n = 0;
	while (t != NULL)
	{
		strcpy(p[n++], t);
		t = strtok(NULL, " ");
	}
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			int leni = strlen(p[i]);
			int lenj = strlen(p[j]);
			if (leni < lenj || (leni == lenj && strcmp(p[i], p[j]) > 0))
			{
				char aux[50];
				strcpy(aux, p[i]);
				strcpy(p[i], p[j]);
				strcpy(p[j], aux);
			}
		}
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", p[i]);
	}
	return 0;
}