#include <stdio.h>
#define MAXN (100)
#define INF (1<<30)//1*2^30
int N, M;//지하철역수, 목적역
int S[MAXN + 2][MAXN + 2];//[s][e]=시간
int path[MAXN + 10];
int visited[MAXN + 10];
int que[MAXN * MAXN + 10];
int wp, rp;
void push(int a) {
	que[wp++] = a;
}
int front() {
	return que[rp];
}
void pop() { rp++; }
int empty() { return wp == rp; }
int BFS() {
	wp = rp = 0;
	for (int i = 1; i <= N; i++) {
		path[i] = 0;
		visited[i] = INF;
	}
	push(1);
	visited[1] = 0;
	path[1] = 0;
	while (!empty()) {
		int cur = front(); pop();
		for (int e = 2; e <= N; e++) {
			int ntime = visited[cur] + S[cur][e];
			if (ntime >= visited[e]) continue;
			push(e);
			path[e] = cur;
			visited[e] = ntime;
		}
	}
	return visited[M];
}
void PRT(int m) {
	if (m == 0)return;
	PRT(path[m]);
	printf("%d ", m);
}
void InputData(void) {
	scanf("%d %d", &N, &M);
	for (int s = 1; s <= N; s++) {
		for (int e = 1; e <= N; e++) {
			scanf("%d", &S[s][e]);
		}
	}
}

int main(void) {
	int ans = 0;
	InputData();//입력

	ans = BFS();//여기서부터 작성
	printf("%d\n", ans);
	PRT(M);
	printf("\n");
	return 0;
}
