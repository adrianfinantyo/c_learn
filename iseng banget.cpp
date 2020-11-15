#include <iostream>
using namespace std;

int main()
{
	int i;
	char a[5];
	gets(a);
	
	
	for(i = 4; i >= 0; i--)
	{
		cout<<a[i]<<"\n";
	}
	
	return 0;
}
