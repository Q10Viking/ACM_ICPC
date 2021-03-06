#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int str[55][55][55];
int n,m,q,flag[55][55][55],T;
int way[6][3]={{0,1,0},{0,-1,0},{0,0,1},{0,0,-1},{1,0,0},{-1,0,0}};
struct Node{
    int x,y,z,step;
    bool check(){
        if(x>=0&&x<n&&y>=0&&y<m&&z>=0&&z<q)
            return true;
        return false;
    }
}s,e,u,v;
int bfs(){
    queue<Node>que;
    memset(flag,0,sizeof(flag));
    flag[s.x][s.y][s.y]=1;
    que.push(s);
    while(!que.empty()){
        u=que.front();
        que.pop();
        if(u.step>=T)
            continue;
        for(int i=0;i<6;i++){
            v=u;
            v.x+=way[i][0];
            v.y+=way[i][1];
            v.z+=way[i][2];
            if(v.check()&&flag[v.x][v.y][v.z]==0&&str[v.x][v.y][v.z]==0){
                flag[v.x][v.y][v.z]=1;
                v.step++;
                if(v.x==e.x&&v.y==e.y&&v.z==e.z&&v.step<=T)
                    return v.step;
                que.push(v);
            }
        }
    }
    return -1;
}                
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&m,&q,&T);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)        
                for(int k=0;k<q;k++)
                    scanf("%d",&str[i][j][k]);
        s.x=s.y=s.z=s.step=0;
        e.x=n-1;e.y=m-1;e.z=q-1;
        printf("%d\n",bfs());
    }
    return 0;
}

