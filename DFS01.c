#include <stdio.h> /*DFS 종결조건 for문 동작 그 때 주의할 점 조건으로 처 내기 다음 재귀로 넘어 갈 수 있게*/
#define MAXN (5)
int N;//던진횟수
int M;//출력모양
int A[MAXN + 10];
int B[MAXN + 10];//사용 체크용 배열
void InputData(void) {
	scanf("%d %d", &N, &M);
}

void DFS1(int n) {  //중복순열
	if (n >= N) {   //종결 조건
		for (int i = 0; i < N; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= 6; i++) {
		A[n] = i;
		DFS1(n+1);  //재귀함수 특징
	}	
	
}
void DFS2(int n, int s) { //중복 조합
	if (n >= N) {
		for (int i = 0; i < N; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
		return;
	}

	for (int i = s; i <= 6; i++) {
		A[n] = i;
		DFS2(n + 1, i); //조합인 경우 DF2(n+1, i+1)
	}

}

void DFS3(int n) { //순열
	if (n >= N) {
		for (int i = 0; i < N; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= 6; i++) {
		if (B[i] == 1) continue;
		B[i] = 1;
		A[n] = i;
		DFS3(n + 1);
		B[i] = 0;
	}
}

void solve(void) {
	if (M == 1) DFS1(0);
	else if (M == 2) DFS2(0,1);
	else DFS3(0);
}


int main(void) {
	InputData();//입력

	solve();//여기서부터 작성

	return 0;
}