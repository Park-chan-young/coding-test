#include <stdio.h>
#include<string.h>
#define MAXN (100)
int N, M;//장기판 행의 수, 열의 수
int R, C, S, K;//말 행과 열, 졸 행과 열
int dh[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dw[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int map[MAXN + 10][MAXN + 10];
typedef struct {
	int h, w, t;
}QUE;
QUE que[MAXN * MAXN];
int wp, rp;
void push(int h, int w, int t) {
	if (map[h][w] == 1) return;
	map[h][w] = 1;
	que[wp].h = h; que[wp].w = w; que[wp].t = t; wp++;
}
QUE front() { return que[rp];}
void pop() { rp++;}
int empty() { return wp == rp;}
int BFS() {
	wp = rp = 0;
	memset(map, 0, sizeof(map));
	push(R, C, 0);
	while (!empty()) {
		QUE cur = front(); pop();
		if ((cur.h == S) && (cur.w == K)) return cur.t;
		for (int i = 0; i < 8; i++) {
			int Dh = cur.h + dh[i];
			int Dw = cur.w + dw[i];
			if ((Dh < 1)||(Dh > N)||(Dw < 1)||(Dw > M)) continue; //범위 따져주기 첫문제는 char, int 형이라 괜찮았지만 여긴 아님
			push(Dh, Dw, cur.t + 1);
		}
	}
}
void InputData(void) {
	scanf("%d %d", &N, &M);
	scanf("%d %d %d %d", &R, &C, &S, &K);
}

int main(void) {
	int ans = -1;
	InputData();//입력

	ans = BFS();//여기서부터 작성

	printf("%d\n", ans);//출력
	return 0;
}