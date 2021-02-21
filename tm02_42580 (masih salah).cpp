#include <stdio.h>

int main()
{
	int x1, x2, x3, y1, y2, y3;
	scanf ("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	if (x1+x2<x3 || x2+x3<x1 || x1+x3<x2)
	{
		if (y1+y2<y3 || y2+y3<y1 || y1+y3<y2)
		{
			printf ("bisa membentuk segitiga");
		}
		else
		{
			printf ("tidak bisa membentuk segitiga");
		}
	}
	else
	{
		printf ("tidak bisa membentuk segitiga");
	}
		
	return 0;
}
