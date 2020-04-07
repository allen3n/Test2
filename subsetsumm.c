
#include <stdio.h>
#include <stdint.h>
#define true 1
#define false 0

int subsetSum(int a[],int len, int k, int v) {
	if (v == 0 && k == 0) {//we did it!
		return true;
	}
	if (k <= 0) { //They all subtracted away the original too much its bad
		return false;
	}
	//The two below will go through and will essentially check every subset of size k!
	int find = v - a[0];
	if (find >= 0) {
		if (subsetSum(&a[1], len - 1, k - 1, find)) {
			return true;
		}
		if (subsetSum(&a[1], len - 1, k, v)) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

int main(void) {
	int a[] = { 1,8,6,4,3 };
	int len = 5;
	int k = 2;
	for (int v = 0; v != 22; v++) {
		if (subsetSum(a, len, k, v)) {
			printf("YES! There are %d numbers in 'a' that will add up to %d.\n", k, v);
		}
		else {
			printf("NO! There are NO %d numbers in 'a' that will add up to %d.\n", k, v);
		}
	}

}
