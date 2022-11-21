/*Q정렬 기초*/
#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)5e3)
int N;
int A[MAXN + 10];

/*오름차수*/
int comp(const void *a, const void *b) {
	int num1 = *(int *)a; int num2=  *(int *)b;
	if (num1 > num2) return 1;
	if (num1 < num2) return -1;
	return 0;
}

int comp2(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

void InputData() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
}

void main(void) {
	InputData();
	qsort(A, N, sizeof(A[0]), comp2);
	for (int j = 0; j < N; j++) {
		printf("%d ", A[j]);
	}
}