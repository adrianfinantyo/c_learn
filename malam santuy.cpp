#include <iostream>
using namespace std;

int main()
{
	int x,y,z;
	cout<<"Masukan panjang sisi segitiga : ";
	cin>>x,y,z;
	if (x+y>z || y+z>x || x+z>y)
	{
		cout<<"bisa membentuk segitiga";
	}
	else
	{
		cout<<"tidak bisa membentuk segitiga";
	}
	
	return 0;
}
