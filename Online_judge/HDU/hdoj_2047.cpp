#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL __int64
LL f[50];
using namespace std;
int main(){
    f[1]=3;f[2]=8;
    for(int i=3;i<=40;i++)
        f[i]=2*(f[i-1]+f[i-2]);
    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%I64d\n",f[n]);
    return 0;
}