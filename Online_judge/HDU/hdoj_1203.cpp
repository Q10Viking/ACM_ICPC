/*
ID:cxlove
PROB:I NEED A OFFER
DATA:2012.2.29
HINT:01背包
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int t,n,w,a[1005];
    double b[1005],dp[10005];
    while(cin>>w>>n){    
        if(w==0&&n==0)
            break;
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
            b[i]=1-b[i];
        }
        for(int i=0;i<=w;i++)
            dp[i]=1;
        for(int i=0;i<n;i++)
            for(int j=w;j>=a[i];j--)
                dp[j]=min(dp[j],dp[j-a[i]]*b[i]);
        printf("%.1lf%%\n",(1-dp[w])*100);
    }
    return 0;
}
/*
10 3
4 0.1
4 0.2
5 0.3
*/