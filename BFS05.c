#include <stdio.h>
#include<string.h>
#define MAXN (100)
int N;//가로, 세로 크기
char map[MAXN + 10][MAXN + 10];//지도정보
int visited[MAXN + 10][MAXN + 10]; //가중치 저장
int dh[] = { -1, 1, 0, 0 };
int dw[] = { 0, 0, -1, 1 };
typedef struct {
	int h, w;
}QUE;
QUE que[MAXN * MAXN + 10];
int wp, rp;
void push(int h, int w, int t) {
	if (visited[h][w] <= t)return;
	visited[h][w] = t;
	que[wp].h = h; que[wp].w = w; wp++;
}
void pop() { rp++;}
QUE front() { return que[rp];}
int empty() { return wp == rp;}

int BFS() {
	wp = rp = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = 10000000;
		}
	}
	push(1, 1, 0);
	while (!empty()) {
		QUE cur = front(); pop();
		//if (cur.h == N && cur.w == N)return visited[cur.h][cur.w]; 그 도착하는 경로 여러가지 봐서 해야해서 끝내면 완됨
		for (int i = 0; i < 4; i++) {
			int hh = cur.h + dh[i];
			int ww = cur.w + dw[i];
			if (hh<1 || hh>N || ww<1 || ww>N)continue;
			push(hh, ww, visited[cur.h][cur.w] + map[hh][ww] - '0');
		}
	}
	return visited[N][N];
}

void InputData(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%s", &map[i][1]);
	}
}

int main(void) {
	int ans = -1;
	InputData();//입력

	ans = BFS();//여기서부터 작성

	printf("%d\n", ans);//출력
	return 0;
}