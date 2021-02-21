#include <stdio.h>

int main()
{
	int w, b;
	scanf ("%d", &w);
	switch (w)
	{
		case 15 : b = 125;
			break;
		case 25 : b = 215;
			break;
		case 40 : b = 500;
			break;
		case 60 : b = 880;
			break;
		case 75 : b = 1000;
			break;
		case 100 : b = 1675;
			break;
		default : b = -1;
			break;
	}
	printf ("%d", b);
	return 0;
}
