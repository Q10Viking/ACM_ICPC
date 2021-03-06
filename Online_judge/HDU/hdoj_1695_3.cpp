/*
ID:cxlove
PROB:hdu 1695 GCD
DATA:2012.4.6
HINT:欧拉函数+容斥原理
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100005
#define LL long long
using namespace std;
LL eular[N];
int prime[N][10],num[N];
void Prime(){
    eular[1]=1;
    for(int i=2;i<N;i++){
        if(eular[i]==i){
            eular[i]=i-1;
            for(int j=2;j*i<N;j++){
                eular[i*j]=eular[i*j]*(i-1)/i;
                prime[i*j][num[i*j]++]=i;
            }
        }
        eular[i]+=eular[i-1];
    }
}
void Init(){
    for(int i=1;i<N;i++)
        eular[i]=i;
    memset(prime,0,sizeof(prime));
    memset(num,0,sizeof(num));
    Prime();
}
LL dfs(int idx,int b,int now){
    LL ret=0;
    for(int i=idx;i<num[now];i++)
        ret+=b/prime[now][i]-dfs(i+1,b/prime[now][i],now);
    return ret;
}
int main(){
    Init();
    int t,a,b,c,d,k,cas=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        printf("Case %d: ",cas++);
        if(k==0){
            printf("0\n");
            continue;
        }
        a=b/k;b=d/k;
        if(a<b)
            swap(a,b);
        LL ans=eular[b];          //1-b中互质个数和，即欧拉函数和
        for(int i=b+1;i<=a;i++)    //1-b中与a互质的个数
            ans+=b-dfs(0,b,i);
        printf("%I64d\n",ans);
    }
    return 0;
}