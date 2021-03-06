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
#define inf 1<<28
#define M 6000005
#define N 500005
#define maxn 300005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
#define lson step<<1
#define rson step<<1|1
using namespace std;
struct Node
{
    int left,right;
    int mx;
} L[N*4];
int dp[N],a[N],b[N];
void Bulid(int step,int l,int r)
{
    L[step].left=l;
    L[step].right=r;
    L[step].mx=0;
    if(l==r) return ;
    int m=(l+r)>>1;
    Bulid(lson,l,m);
    Bulid(rson,m+1,r);
}
void Update(int step,int pos,int val)
{
    if(L[step].left==L[step].right)
    {
        L[step].mx=val;
        return;
    }
    int m=(L[step].left+L[step].right)>>1;
    if(pos<=m) Update(lson,pos,val);
    else Update(rson,pos,val);
    L[step].mx=max(L[lson].mx,L[rson].mx);
}
int Query(int step,int l,int r)
{
    if(L[step].left==l&&L[step].right==r)
        return L[step].mx;
    int m=(L[step].left+L[step].right)>>1;
    if(r<=m) return Query(lson,l,r);
    else if(l>m) return Query(rson,l,r);
    else return max(Query(lson,l,m),Query(rson,m+1,r));
}
int main()
{
    int n,d,cas=0;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            b[t1-1]=a[t1-1]=t2;
        }
        sort(b,b+n);
        int m=unique(b,b+n)-b;
        Bulid(1,0,m-1);
        int ans=0;
        for(int i=0; i<n; i++)
        {
            int r=upper_bound(b,b+m,a[i])-b-1;
     //       cout<<r<<endl;
            int q=Query(1,0,r);
            ans=max(ans,q+1);
            Update(1,lower_bound(b,b+m,a[i])-b,q+1);
        }
        if(ans==1) printf("Case %d:\nMy king, at most %d road can be built.\n\n",++cas ,ans );
        else printf("Case %d:\nMy king, at most %d roads can be built.\n\n",++cas ,ans );
    }
    return 0;
}
