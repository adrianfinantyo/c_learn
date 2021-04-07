#include <stdio.h>

int f(int x, int *py){
	int y;
	*py += 2;
	y = *py;
	x += 3;
	return x + y;
}

int main(){
	int d, c, *b;
	d = 1;
	c = 4;
	b = &c;
	printf( "%d\n", *b);
	printf( "%d\n", f(c,b));
	b = &d;
	printf( "%d\n", c);
	printf( "%d\n", *b);
	printf( "%d\n", f(d,b));
	return 0;
}

