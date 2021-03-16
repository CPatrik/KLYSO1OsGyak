#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/wait.h>

int main(void)
{
	char parancs[20];
	printf("Adjon meg egy parancsot(max 20 karakter!): ");
	scanf("%s", parancs);
	system(parancs);

	return 0;
}
