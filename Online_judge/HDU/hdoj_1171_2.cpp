/*
ID:cxlove
PROB:Big Event in HDU 
DATA:2012.3.1
HINT:多重背包
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Node{
    int val,cnt;
}a[1005];
int m,dp[250005];
void completepack(int cost,int val){
    for(int i=0;i<=m-cost;i++)
        dp[i+cost]=max(dp[i+cost],dp[i]+val);
}
void zeroonepack(int cost,int val){
    for(int i=m;i>=cost;i--)
        dp[i]=max(dp[i],dp[i-cost]+val);
}
void multpack(int cost,int val,int count){
    if(cost*count>m){
        completepack(cost,val);
        return;
    }
    int k=1;
    while(count>k){
        zeroonepack(k*cost,k*val);
        count-=k;
        k<<1;
    }
    zeroonepack(count*cost,count*val);
}
int main(){
    int n,sum;
    while(scanf("%d",&n)!=EOF){
        if(n<=0)
            break;
        sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i].val>>a[i].cnt;
            sum+=a[i].val*a[i].cnt;
        }
        m=sum/2;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            multpack(a[i].val,a[i].val,a[i].cnt);
        if(dp[m]>sum-dp[m])
             printf("%d %d\n",dp[m],sum-dp[m]);
        else
            printf("%d %d\n",sum-dp[m],dp[m]);
    }
    return 0;
}
/*
2
10 1
20 1
3
10 1 
20 2
30 1
*/
