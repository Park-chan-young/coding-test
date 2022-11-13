#include <stdio.h>
#include <string.h>
#define MAXN (30)
int L, R, C;//층, 행, 열
char map[MAXN+2][MAXN+2][MAXN+2];//[층][행][열]=('#':장애물, '.':빈공간, 'S':출발, 'E':도착, 0:범위 벗어남)
int sl, sr, sc, el, er, ec;//출발층행열, 도착 층행열
//linear queue
typedef struct{
    int l, r, c, t;//층,행,열,시간
}QUE;
QUE que[MAXN*MAXN*MAXN+10];
int wp, rp;
QUE front() { return que[rp]; }
void pop() { rp++; }
int empty() { return wp==rp; }
void push(int l, int r, int c, int t){
    if (map[l][r][c] != '.') return;//빈공간 아님('#':장애물, 0:범위 벗어남, '@':이미 방문 했음)
    map[l][r][c]='@';//방문표시
    que[wp].l=l; que[wp].r=r; que[wp].c=c; que[wp].t=t; wp++;
}
int BFS(){
    int dl[] = {0, 0, 0, 0, -1, 1};//층
    int dr[] = {-1, 1, 0, 0, 0, 0};//행
    int dc[] = {0, 0, -1, 1, 0, 0};//열
    QUE cur;
    //1.초기화
    wp = rp = 0;
    //2.시작위치 큐에 저장
    push(sl, sr, sc, 0);
    //3.반복문
    while(!empty()){
        cur = front(); pop();
        if ((cur.l==el)&&(cur.r==er)&&(cur.c==ec)) return cur.t;//도착 성공
        for (int i=0; i<6; i++){
            push(cur.l+dl[i], cur.r+dr[i], cur.c+dc[i], cur.t+1);
        }
    }
    //4.실패
    return -1;
}
int InputData(){
    scanf("%d %d %d", &L, &R, &C);
    if ((L==0)&&(R==0)&&(C==0)) return 0;
    memset(map, 0, sizeof(map));
    for (int l=1; l<=L; l++){
        for (int r=1; r<=R; r++){
            scanf("%s", &map[l][r][1]);
            for (int c=1; c<=C; c++){
                if (map[l][r][c] == 'S'){//출발 좌표
                    sl=l; sr=r; sc=c;
                    map[l][r][c] = '.';
                }
                else if (map[l][r][c] == 'E'){//도착 좌표
                    el=l; er=r; ec=c;
                    map[l][r][c] = '.';
                }
            }
        }
    }
    return 1;
}
int main(){
    for(;;){
        if (!InputData()) break;
        int ans = BFS();
        if (ans < 0) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", ans);
    }
    return 0;
}