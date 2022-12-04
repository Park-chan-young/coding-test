#include <stdio.h>
#include <string.h>
#define MAXN ((int)1e3) // 주의
int M, N;//상자의 가로, 세로 칸 수
int map[MAXN + 10][MAXN + 10];//토마토 정보
int dh[] = { -1, 1, 0, 0 };
int dw[] = { 0, 0, -1, 1 };
typedef struct {
	int h, w, t;
}QUE;
QUE que[MAXN * MAXN + 10];
int wp, rp;
void push(int h, int w, int t) {
	que[wp].h = h; que[wp].w = w; que[wp].t = t;
	wp++;
}
QUE front() { return que[rp]; }
void pop() { rp++; };
int empty() { return wp == rp;}
int BFS() {
	wp = rp = 0;
	int count = 0;  // 다 읶은 경우
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) push(i, j, 0);
			else if (map[i][j] == 0) count++;
		}
	}
	if (count == 0) return 0;
	while (!empty()) {
		QUE cur = front(); pop();
		for (int k = 0; k < 4; k++) {
			int hh = cur.h + dh[k];
			int ww = cur.w + dw[k];
			if (hh < 0 || hh >= N || ww < 0 || ww >= M)continue;
			if (map[hh][ww] != 0)continue;
			map[hh][ww] = 1;
			push(hh, ww, cur.t + 1);
			count--;
			if (count == 0) return cur.t + 1;
		}
	}
	return -1;  // 못 읶은게 남은경우
}
void InputData(void) {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

int main(void) {
	int ans = -1;
	InputData();//입력

	ans = BFS();//여기서부터 작성

	printf("%d\n", ans);//출력
	return 0;
}