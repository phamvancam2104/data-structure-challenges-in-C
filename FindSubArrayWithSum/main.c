#include <stdio.h>
#include <stdlib.h>

int findArraysWithSum(int* a, int size, int givenSum) {
	int i = 0;
	int j = 0;
	for(i = 0; i < size; i++) {
		int sum = 0;
		for (j = i; j < size; j++) {
			sum += a[j];
			if (sum == givenSum) {
				printf("Subarray [%d..%d]", i, j);
			}
		}
	}
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[] = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
	int size = sizeof(a)/sizeof(a[0]);
	findArraysWithSum(a, size, 1);
	return 0;
}
