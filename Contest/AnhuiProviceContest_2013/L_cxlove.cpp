//author:cxlove

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100005;
struct Edge{
    int v,next;
}e[N<<1];
int start[N],tot;
int n,deg[N];
double up[N],down[N],sum[N];
void _add(int u,int v){
    e[tot].v=v;e[tot].next=start[u];
    start[u]=tot++;
}
void add(int u,int v){
    _add(u,v);
    _add(v,u);
}
void Up(int u,int pre){
    if(pre==-1) up[u]=0;   //�����Ǹ���û��up 
    else up[u]=1.0/deg[u];  //�Լ�����ѡ��up
    sum[u]=0;
    for(int i=start[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pre) continue;
        Up(v,u);
        up[u]+=up[v]/(deg[u]-1.0);  //����������
        sum[u]+=up[v];
    }
}
void Down(int u,int pre){
    for(int i=start[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pre) continue;
        down[v]=1.0/deg[u];  //�Լ�����ѡ��down
        down[v]+=down[u]/(deg[u]-1.0);  //����down�����ڵ㣬����down
        down[v]+=(sum[u]-up[v])/(deg[u]-1.0); //Ҳ������up�����ڵ㣬��down
        Down(v,u);
    }
}
int main(){
    while(scanf("%d",&n)!=EOF&&n){
        memset(start,-1,sizeof(start));
        memset(deg,0,sizeof(deg));
        tot=0;
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            deg[u]++;deg[v]++;
            add(u,v);
        }
        Up(1,-1);
        down[1]=0.0;
        Down(1,-1);
        double ans=0;
        //��Ҳ��Ҷ��
        if(deg[1]==1){
            ans=max(ans,up[e[start[1]].v]);
        }
        for(int i=2;i<=n;i++)
            if(deg[i]==1)
                ans=max(ans,down[i]);
        printf("%.3f\n",ans);
    }
    return 0;
}



