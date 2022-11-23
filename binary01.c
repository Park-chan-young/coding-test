/*basic binary*/
#include <stdio.h>
#define MAXN ((int)5e4)
#define MAXT ((int)1e4)
int N;
int A[MAXN + 10];
int T;
int B[MAXT + 10];

void InputData(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &B[i]);
	}
}

int solve(int s, int e, int d) {
	while (s <= e) {
		int m = (s + e) / 2;
		if (A[m] == d) return m;
		else if (A[m] < d) {
			s = m + 1;
		}
		else e = m - 1;
	}
	return 0;
}

void SSolve() {
	for (int t = 0; t < T; t++) {
		B[t] = solve(1, N, B[t]);
	}
}


void OutputData(void) {
	for (int i = 0; i < T; i++) {
		printf("%d\n", B[i]);
	}
}
int main(void) {
	InputData();// 입력받는 부분

	SSolve();// 여기서부터 작성

	OutputData();// 출력하는 부분
	return 0;
}