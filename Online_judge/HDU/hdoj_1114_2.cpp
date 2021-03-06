/*
ID:cxlove
PROB:Piggy-Bank 
DATA:2012.3.1
HINT:完全背包
*/
#include<iostream>
#include<cstdio>
#define inf 1<<30
using namespace std;
struct node{
    int v,w;
}a[1000];
int main(){
    int w1,w2,w,t,n,dp[10005];
    cin>>t;
    while(t--){
        cin>>w1>>w2>>n;
        w=w2-w1;
        for(int i=0;i<n;i++)
            cin>>a[i].v>>a[i].w;
        for(int i=0;i<=w;i++)
            dp[i]=inf;
        dp[0]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<=w-a[i].w;j++)
                dp[j+a[i].w]=min(dp[j+a[i].w],dp[j]+a[i].v);
        if(dp[w]==inf)
            cout<<"This is impossible."<<endl;
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[w]<<"."<<endl;
    }
    return 0;
}
/*
3
10 110
2
1 1
30 50
10 110
2
1 1
50 30
1 6
2
10 3
20 4
*/
