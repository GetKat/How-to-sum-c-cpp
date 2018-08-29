#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char s[512] = "#include <stdio.h>\nint main(){ ", aux[12];
	FILE *f;
	int a, b, result, count = 0;

	printf("Enter two integers: ");
	scanf("%d %d", &a, &b);

	sprintf(aux, "%d", a);
	strcat(s, "int x = ");
	strcat(s, aux);
	strcat(s, "; ");
	strcpy(aux, "");
	sprintf(aux, "%d", b);
	strcat(s, "for(int i = 0; i < ");
	strcat(s, aux);
	strcat(s, "; i++) x++; return x; }");

	f = fopen("sumfile.c", "w");
	if(f == NULL){ //if the file doesnt open properly
		printf("Error!\n");
		exit(-1);
	}

	fwrite(s, strlen(s) * sizeof(char), 1, f);
	fclose(f);

	system("gcc -std=c99 -o sumf -w sumfile.c");
	result = system("sumf");
	
	printf("Sum is %d\n", result);
	return 0;
}