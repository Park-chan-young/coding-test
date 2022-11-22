#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)5e3)
int N;
int A[MAXN + 10];

int comp(const void* a, const void* b) {
	return *(int*)a - *(int*)b; /*이거 포인터 변수가 아니라 포인터가 가리키는 변수*/
}
void InputData(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
}

int solve() {
	int sum = 0;
	for(int i = 0; i < N - 1; i++) {
		qsort(&A[i], N - i, sizeof(A[0]), comp);
		A[i + 1] = A[i + 1] + A[i];
		sum += A[i+1];
	}

	return sum;
}

int main() {
	int ans = -1;
	InputData();//입력

	ans = solve();//여기서부터 작성

	printf("%d\n", ans);//출력
	return 0;
}