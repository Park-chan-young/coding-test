/*N장의 카드로 구성 된 카드 덱(Deck)이 있다. 이 카드는 1번 카드가 가장 위에, N번 카드가 가장 아래쪽에 있는 형태로 놓여져 있다. 이제 이 카드를 아래의 규칙에 따라서 수행하면서 한 장씩 상대방에게 전달할 것이다.
 
1) 가장 아래 카드 번호를 2로 나눈 몫의 정수만큼 반복하여 제일 위에 올라와 있는 카드부터 한 장씩 순서대로 가장 밑으로 옮긴다.
2) 옮긴 후 가장 위에 올라와 있는 카드 한 장을 상대에게 넘긴다.
위 1)~2) 행동을 N-1번 수행하고 마지막에는 남은 카드 한 장을 넘긴다.
위 규칙대로 카드를 넘겼을 때, 상대방에게 넘긴 카드 번호를 넘긴 순서대로 출력하시오. 
주의 wp 빈공간, rp 차있는 공간
기타 주의 x++ 이번 명령어에서는 +1안하고 적용 ++x 이번 명령어에서 +1한 값적용*/
#include <stdio.h>
#define MAXN (100)
int N;
int sol[MAXN + 10];//출력된는 배열

void InputData(void) {
    scanf("%d", &N);
}
void OutputData(void) {
    for (int i = 0; i < N; i++) {
        printf("%d ", sol[i]);
    }
}
int que[MAXN * 10];
int wp, rp;

void push(int d) { que[wp++] = d;}
void pop() { rp++;}
int front() { return que[rp];}
int empty() { return wp == rp; }
int size() { return wp - rp; }
int back() { return que[wp - 1];}

void solve(void) {
    int k = 0;
    wp = rp = 0;
    for (int i = 0; i < N; i++) {
        push(i);
    }
    for (int j = 0; j < N - 1; j++) {
        int cnt = back() / 2;
        for (int z = 0; z < cnt; z++) {
            int r = front(); pop();
            push(r);
        }
        sol[k++] = front(); pop();
    }
    sol[k++] = front(); pop();
}
  

int main(void) {
    InputData();//입력
    //여기서부터 작성
    OutputData();//출력
    return 0;
}
