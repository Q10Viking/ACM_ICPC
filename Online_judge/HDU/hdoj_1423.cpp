#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <ctime>
#define lson step<<1
#define rson step<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
using namespace std;
const int N = 505;
int a[N],b[N],dp[N];
int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
            scanf("%d",&b[i]);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            int p=0;
            for(int j=0;j<m;j++){
                if(b[j]<a[i]&&dp[j]+1>dp[p]) p=j;
                if(b[j]==a[i]&&dp[p]+1>dp[j]) dp[j]=dp[p]+1;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
            ans=max(ans,dp[i]);
        printf("%d\n",ans);
        if(t) puts("");
    }
    return 0;
}