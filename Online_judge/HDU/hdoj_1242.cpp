#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define LL long long
using namespace std;
struct Node{
    int x,y,step;
    bool operator<(const Node &n1)const{
        return step>n1.step;
    }
}s,e,u,v;
int n,m;
char str[205][205];
int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int bfs(){
    priority_queue<Node>que;
    bool flag[205][205];
    memset(flag,0,sizeof(flag));
    s.step=0;
    que.push(s);
    flag[s.x][s.y]=1;
    while(!que.empty()){
        u=que.top();
        que.pop();
        for(int i=0;i<4;i++){
            v.x=u.x+way[i][0];
            v.y=u.y+way[i][1];
            if(v.x>=0&&v.y>=0&&v.x<n&&v.y<m&&flag[v.x][v.y]==0&&str[v.x][v.y]!='#'){
                flag[v.x][v.y]=1;
                if(str[v.x][v.y]=='x')
                    v.step=u.step+2;
                else
                    v.step=u.step+1;
                if(v.x==e.x&&v.y==e.y)
                    return v.step;
                que.push(v);
            }
        }
    }
    return -1;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
            for(int j=0;j<m;j++)
                if(str[i][j]=='a'){
                    s.x=i;
                    s.y=j;
                }
                else if(str[i][j]=='r'){
                    e.x=i;
                    e.y=j;
                }
        }
        int ans=bfs();
        if(ans==-1)
            printf("Poor ANGEL has to stay in the prison all his life.\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}

    
