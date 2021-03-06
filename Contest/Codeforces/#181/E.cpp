#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define LL long long
#define mp(a,b) make_pair(a,b)
using namespace std;
const int N = 10000005;
int cnt[N]={0};
int flag[N]={0};
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        cnt[k]++;
    }
    for(int i=N-2;i>=0;i--)
        cnt[i]+=cnt[i+1];
    LL ans=1,ret,low,high,mid;
    for(int i=2;i<N;i++){
        if(flag[i]) continue;
        //线性筛选
        for(int j=2;j*i<N;j++)
            flag[i*j]=1;
        LL t=0;
        //求出因子i的个数
        for(LL p=i;p<N&&p>0;p*=(LL)i)
            for(LL q=p;q<N;q+=(LL)p)
                t+=cnt[q];
        if(t==0) continue; 
        low=ans,high=(1LL<<61);
        while(low<=high){
            mid=(low+high)>>1;
            LL temp=mid,tot=0;
            while(temp){
                temp/=i;
                tot+=temp;
            }
            if(tot>=t) ans=mid,high=mid-1;
            else low=mid+1;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}