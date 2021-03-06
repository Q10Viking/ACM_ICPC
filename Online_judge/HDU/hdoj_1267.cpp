#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL __int64
LL f[25][25];
using namespace std;
LL F(int n,int m){
    if(f[n][m]!=-1) return f[n][m];
    if(m>n) return f[n][m]=0;
    if(m==0) return f[n][m]=1;
    return f[n][m]=F(n-1,m)+F(n,m-1);
}
int main(){
    int n,m;
    memset(f,-1,sizeof(f));
    while(scanf("%d%d",&n,&m)!=EOF)
        printf("%I64d\n",F(n,m));
    return 0;
}