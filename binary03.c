/*이진탐색 upper, lower 사용한 문제*/
#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)1e3)
int N;//연잎수
int A[MAXN + 10];//연잎좌표
int comp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
void InputData(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	qsort(A, N, sizeof(A[0]), comp);
}
int upper(int s, int e, int d) {
	int sol = -1;
	while (s <= e) {
		int m = (s + e) / 2;
		if (A[m] <= d) {
			sol = m; /*이 거 조심!!*/
			s = m + 1;
		}
		else e = m - 1;
	}
	return sol;
}

int lower(int s, int e, int d) {
	int sol = -1;
	while (s <= e) {
		int m = (s + e) / 2;
		if (A[m] >= d) {
			sol = m;
			e = m - 1;
		}
		else s = m + 1;
	}
	return sol;
}

int solve() {
	int min; int max;
	int seq = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			int first = A[j] - A[i];
			min = lower(j, N - 1, A[j] + first);
			if (min == -1) break;
			max = upper(j, N - 1, A[j] + 2 * first);
			seq += (max - min + 1);
		}
	}
	return seq;
}

int main(void) {
	int ans = -1;
	InputData();//입력받는부분

	ans = solve();//여기서부터작성

	printf("%d\n", ans);//출력하는부분
	return 0;
}