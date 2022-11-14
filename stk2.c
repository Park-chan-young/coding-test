#include <stdio.h>
#define MAXN ((int)1e5)
int N;//빌딩수
int H[MAXN + 10];//빌딩높이
int sol[MAXN + 10];//각 빌딩에서 보이는 빌딩 번호
int stk[MAXN + 100];
int sp;
void InputData(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &H[i]);
	}
}
void OutputData(void) {
	for (int i = 1; i <= N; i++) {
		printf("%d\n", sol[i]);
	}
}
void push(int n) { stk[++sp] = n; }
void pop() { sp--; }
int top() { return stk[sp];}
int empty() { return sp == 0;}
int size() { return sp;}
void solve(void) {
	sp = 0;
	for (int i = 1; i <= N; i++){
		while (!empty() && H[top()] < H[i]) {
			sol[top()] = i;
			pop();
		}
		push(i);
	}
}


int main(void) {
	InputData();//입력받는 부분

	solve();//여기서부터 작성

	OutputData();//출력하는 부분
	return 0;
}