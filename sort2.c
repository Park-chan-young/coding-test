/*N명의 점수가 주어질 때 상위 3명의 ID를 출력하는 프로그램을 작성하시오.*/
#include <stdio.h>
#include <stdlib.h>

#define MAXN ((int)3e4)
int N;//자료 개수
typedef struct{
	int id, score;//아이디, 점수
}ST;
ST A[MAXN + 10];//자료

void InputData(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i].score);
		A[i].id = i + 1;
	}
}
int comp(const void *a, const void *b){
	ST* x = (ST*)a;
	ST* y = (ST*)b;
	if (y->score == x->score) return x->id - y->id;/*이게 끝으로 가면 안됨 == 경우 먼저 해주기*/
	return y->score - x->score;
}

void OutputData(void) {
	for (int i = 0; i < 3; i++) {
		printf("%d ", A[i].id);
	}
	printf("\n");
}

int main(void) {
	InputData();//입력
	qsort(A, N, sizeof(A[0]), comp); 
	OutputData();
	return 0;
}