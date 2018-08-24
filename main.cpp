#include <cstdio>
#include <string>

int main(){
	std::string s = "#include <stdio.h>\nint main(){ ";
	FILE *f;
	int a, b;
	printf("Enter two integers: ");
	scanf("%d %d", &a, &b);
	s += "int x = " + std::to_string(a) + "; ";
	s += "for(int i = 0; i < " + std::to_string(b) + "; i++) x++; ";
	s += "return x; }";
	f = fopen("sumfile.c", "w");
	fprintf(f, "%s", s.c_str());
	fclose(f);
	system("gcc -std=c99 -o sumf sumfile.c");
	int result = system("sumf");
	printf("Sum is %d\n", result);
	return 0;
}
