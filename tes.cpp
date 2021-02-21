#include <stdio.h>

int main()
{
    int a, b, i, j;
    scanf("%d %d",&a, &b);
    if(a>=2 && a<=100 && b>=0 && b<=50)
    {
        for(i=1; i<=a; i++)
        {
            for(j=1; j<=b; j++)
            {
                printf(" ");
            }
            for(j=1; j<=a; j++)
            {
                if(j==i)
                {
                    printf("\\");
                }
                else
                    printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}