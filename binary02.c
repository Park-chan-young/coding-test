#include <stdio.h>
#define MAX ((int)2e5)
int N;
int A[MAX + 10];
int M;
int B[MAX + 10];

void InputData(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &B[i]);
	}
}

int upper(int s, int e, int d) {
	int seq = -1;
	while (s <= e) {
		int m = (s + e) / 2;
		if (A[m] == d) {
			seq = m;
			s = m + 1;
		}
		else if (A[m] < d) s = m + 1;
		else  e = m - 1;
	}
	return seq;
}
int lower(int s, int e, int d) {
	int seq = -1;
	while (s <= e) {
		int m = (s + e) / 2;
		if (A[m] == d) {
			seq = m;
			e = m - 1;
		}
		else if (A[m] > d) e = m - 1;
		else s = m + 1;
	}
	return seq;
}

void ssovle() {
	for (int i = 0; i < M; i++) {
		int min = lower(0, N - 1, B[i]);
		if (min != -1) {
			int max = upper(0, N - 1, B[i]);
			B[i] = max - min + 1;
		}
		else B[i] = 0;
	}

}
void OutputData(void) {
	for (int i = 0; i < M; i++) {
		printf("%d ", B[i]);
	}
}

int main(void) {
	// 입력받는 부분
	InputData();

	ssovle();// 여기서부터 작성


	// 출력하는 부분
	OutputData();
	return 0;
}