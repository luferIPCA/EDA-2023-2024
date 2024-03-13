#include "..\Libs\Header.h"
#pragma comment(lib,"..\\Libs\\Folha1-Lib.lib")

#include<stdio.h>

int main() {

	int x = 34;
	int y = x * 2;

	int a = SomaII(&x, &y);
	printf("A=%d\n", a);
}
