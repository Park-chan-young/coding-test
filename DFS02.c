#include <stdio.h>
#define MAXN (20)
int N, K;//자연수 개수, 만들값
int A[MAXN + 10];//자연수 값
char* msg[] = { "NO", "YES" };
int prefixsum[MAXN + 10]; // 구간합;

void Mak_Pre(void) {
	prefixsum[0] = 0;
	for (int i = 1; i <= N; i++) {
		prefixsum[i] = prefixsum[i - 1] + A[i];
	}
}

int DFSB(int n, int sum) {  //인덱스 두개 이상도 가능**
	if (sum > prefixsum[N] - prefixsum[n - 1]) return 0;/*나머지 최대값이 sum보다 작으면 아무리 더해도 sum == 0에 도달할 수 없다*/
	if (sum == 0) return 1;
	if (sum < 0) return 0;
	if (n > N) return 0;
	if (DFSB(n + 1, sum - A[n])) return 1; //주의
	if (DFSB(n + 1, sum)) return 1; //주의
	return 0;
}

int DFSM(int n, int sum) {  //추후 다시 보기
	if (sum > prefixsum[N] - prefixsum[n - 1]) return 10;
	if (sum == 0)return 1;
	if (sum < 0)return 0;
	for (int i = n; i <= N; i++) {
		if (DFSmulti(i + 1, sum - A[i])) return 1;//성공
	}
	return 0;//실패
	
}

void InputData(void) {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
}




int main(void) {
	int T, t, ans;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		InputData();//입력
		Mak_Pre();
		ans= DFSB(1, K);
		//여기서부터 작성

		printf("%s\n", msg[ans]);//출력
	}
	return 0;
}