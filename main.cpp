#include <cstdio>
#include <string>

int main(){
	std::string s = "#include <stdio.h>\nint main(){ ";
	FILE *f;
	int a, b, result;

	printf("Enter two integers: ");
	scanf("%d %d", &a, &b);
	s += "int x = " + std::to_string(a) + "; ";
	s += "for(int i = 0; i < " + std::to_string(b) + "; i++) x++; ";
	s += "return x; }";

	f = fopen("sumfile.c", "w");
	if(f == NULL){ //if the file doesnt open properly
		printf("Error!\n");
		exit(-1);
	}

	fputs(s.c_str(), f);
	fclose(f);

	system("gcc -std=c99 -o sumf sumfile.c");
	result = system("sumf");
	
	printf("Sum is %d\n", result);
	return 0;
}
