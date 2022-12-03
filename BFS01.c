#include <stdio.h>
#include <string.h>
#define MAXN (100)
int W, H;//가로, 세로 크기
int sw, sh, ew, eh;//출발 가로세로, 도착 가로세로 좌표
char map[MAXN + 10][MAXN + 10];//지도정보
int visited[MAXN + 10][MAXN + 10];//방문정보
typedef struct {
	int h, w, t;
}QUE;
QUE que[MAXN * MAXN];
int wp, rp;
int dh[] = { -1, 1, 0, 0 };
int dw[] = { 0, 0, -1, 1 };
void push(int h, int w, int t) {
	if (map[h][w] != '0') return;
	if (visited[h][w] == 1) return;
	visited[h][w] = 1;
	que[wp].h = h; que[wp].w = w; que[wp].t = t; wp++;
}
QUE front(){ return que[rp];}
void pop(){rp++;}
int empty() { return wp == rp;}
int BFS() {
	wp = rp = 0;
	memset(visited, 0, sizeof(visited)); //초기화 반드시 TC여러개 주어질 수 있어
	push(sh, sw, 0); //초기값 대입
	while (!empty()) {
		QUE cur = front(); pop();
		if ((cur.h == eh) && (cur.w == ew)) return cur.t;
		for (int i = 0;i<4;i++) {
			int Dh = cur.h + dh[i];
			int Dw = cur.w + dw[i];
			push(Dh, Dw, cur.t + 1);
		}
	}
	return -1;

}
void InputData(void) {
	scanf("%d %d", &W, &H);
	scanf("%d %d %d %d", &sw, &sh, &ew, &eh);
	for (int i = 1; i <= H; i++) {
		scanf("%s", &map[i][1]);    //Tip 
	}
}



int main(void) {
	int ans = -1;
	InputData();//입력

	ans = BFS();//여기서부터 작성

	printf("%d\n", ans);//출력
	return 0;
}