#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>
#define LL long long 
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define pii pair<int,int>
#define sqr(a) ((double)(a)*(a))
#define pi acos(-1.0)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 505;
int way[4][2]={0,1,0,-1,1,0,-1,0};
int mat[N][N],n,m;
int match[N],vis[N];
int dfs(int u){
    for(int i=1;i<=n;i++){
        if(mat[u][i]&&!vis[i]){
            vis[i]=1;
            if(match[i]==-1||dfs(match[i])){
                match[i]=u;
                return true;
            }
        }
    }
    return false;
}
int hungry(){
    int ans=0;
    mem(match,-1);
    for(int i=1;i<=n;i++){
        mem(vis,0);
        if(dfs(i)) ans++;
    }
    return ans;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF&&n+m){
        mem(mat,0);
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            mat[u][v]=1;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    if(i!=j&&i!=k&&j!=k)
                        mat[j][k]|=(mat[j][i]&&mat[i][k]);
        printf("%d\n",n-hungry());
    }
    return 0;
}