#include <stdio.h>

int fak(int n)
{
 if(n>=1)
 {
  if(n==1)
  {
   return 1;
  }
  else
  {
   return (n * fak(n-1));
  }
 }
}

int pangkat(int i, int n)
{
 n = i;
 if(i>=1)
 {
  if(i==1)
  {
   return 1;
  }
  else
  {
   return (i * pangkat(i, n-1));
  }
 }
}

float hasil(float x, int n, int i)
{
 fak(n) / pangkat(i,n);
 return (hasil(x+1));
}

int main()
{
 int n, i;
 float x;
 scanf("%d",&n);
 printf("%f",hasil(x, n, i));
 return 0;
}
