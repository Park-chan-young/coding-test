#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)1e4)
int N, M;
int A[MAXN + 10];
int comp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
void InputData(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &M);
	qsort(A, N, sizeof(A[0]), comp);
}

int IsPossible(int m) {
	int sum = M;
	for (int i = 0; i < N; i++) {
		if (m >= A[i]) sum -= A[i];
		else sum -= m;
	}
	if (sum <0) return -1; /*주의 나중에  upper에서 참 거짓 따질때는 0, 1로 하기 때문에 주의*/
	return 1;
}

int upper(int s, int e) {
	int sol = -1;
	while (s <= e) {
		int m = (s + e) / 2;
		if (IsPossible(m)) {
			sol = m;
			s = m + 1;
		}
		else e = m - 1;
	}
	return sol;
}

int main(void) {
	int ans = -1;

	InputData();// 입력받는 부분
	for (int i = 0; i < N; i++) {
		printf("%d\n", A[i]);
	}
	ans = upper(0, A[N - 1]);// 여기서부터 작성

	printf("%d\n", ans);// 출력하는 부분
	return 0;
}