#include <stdio.h>

int main(){
	int A[3][2] = {1,2,3,4,5,6};
	int B[2][3][2] = {{{12,11},{10,9}, {8,7}}, {{6,5}, {4,2}, {2,1}}};
	
	printf("A. %d\n", A[2][0]);
	printf("B. %d\n", B[1][1][1]);
	
	return 0;
}
