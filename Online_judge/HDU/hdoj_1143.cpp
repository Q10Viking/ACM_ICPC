#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
LL f[50];
void Init(){
     f[0]=1;
     f[2]=3;
     for(int i=4;i<=30;i+=2){
         f[i]=f[2]*f[i-2];
         for(int j=i-4;j>=0;j-=2)
              f[i]+=2*f[j];
     }
}
int main(){
    Init();
    int n;
    while(scanf("%d",&n)!=EOF&&n!=-1)
         printf("%I64d\n",f[n]);
    return 0;
}
