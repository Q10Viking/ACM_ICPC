/*
ID:cxlove
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 1<<25
using namespace std;
int path[101][101],dist[101][101];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j]=path[i][j]=inf;
        while(m--){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(w<path[u][v])
                dist[u][v]=dist[v][u]=path[u][v]=path[v][u]=w;
        }
        int ans=inf;
        for(int k=1;k<=n;k++){
            for(int i=1;i<k;i++)
                for(int j=i+1;j<k;j++)
                    ans=min(dist[i][j]+path[i][k]+path[k][j],ans);
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
        if(ans==inf)
            printf("It's impossible.\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
/*
3 3
1 2 1
2 3 1
1 3 1
3 3
1 2 1
1 2 3
2 3 1
*/