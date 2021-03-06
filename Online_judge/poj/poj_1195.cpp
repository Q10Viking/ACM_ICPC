#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<algorithm>  
#include<set>  
#include<string>  
#include<queue>  
#define inf 1600005  
#define M 40  
#define N 500005  
#define maxn 300005  
#define eps 1e-7
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL long long  
#define MOD 2012  
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#define test puts("OK");  
#define pi acos(-1.0)
#define lowbit(x) ((x)&(-(x)))
#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;  
LL a[1025][1025];
int k,n;
void Update(int x,int y,int val){
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=n;j+=lowbit(j))
            a[i][j]+=val;
}
LL sum(int x,int y){
    LL ret=0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
            ret+=(LL)a[i][j];
    return ret;
}
int main(){
    while(scanf("%d",&k)!=EOF&&k!=3){
        if(k==0){scanf("%d",&n);mem(a,0);}
        else if(k==1) {int x,y,val;scanf("%d%d%d",&x,&y,&val);Update(x+1,y+1,val);}
        else{
            int l,r,b,t;
            scanf("%d%d%d%d",&l,&b,&r,&t);
            printf("%lld\n",sum(r+1,t+1)+sum(l,b)-sum(l,t+1)-sum(r+1,b));
        }
    }
    return 0;
}
