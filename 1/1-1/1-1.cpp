#include <stdio.h>
int conversie(char s[]) {
	int nr = 0;
	for (int i = 0; s[i] >= '0' && s[i] <='9'; i++)
		nr = 10 * nr + s[i] - '0';
	return nr;


}
int main()
{
	FILE* f;
	f = fopen("in.txt", "r");
	if (f == NULL)
		return 1;
	char s[250];
	int x=0;
	while (fgets(s, 250, f))
		x = x + conversie(s);
	printf("%d", x);
	fclose(f);
	return 0;

}

