#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int SG[1005],k,s[100];
int getSG(int x){
    if(SG[x]!=-1) return SG[x];
    int visit[100]={0};
    for(int i=0;i<k;i++){
        int temp=x-s[i];
        if(temp<0) break;
        if(SG[temp]==-1)
            SG[temp]=getSG(temp);
        visit[SG[temp]]=1;
    }
    for(int i=0;;i++)
        if(visit[i]==0) return i;
}
int n;
int main(){
    memset(SG,-1,sizeof(SG));
    SG[0]=0;
    s[0]=1;s[1]=2;
    for(k=2;s[k-1]<=1000;k++)
        s[k]=s[k-1]+s[k-2];
    for(int i=1000;i>=1;i--)
        if(SG[i]==-1)
            SG[i]=getSG(i);
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF&&a+b+c){    
        if((SG[a]^SG[b]^SG[c])!=0)
            printf("Fibo\n");
        else
            printf("Nacci\n");
    }
    return 0;
}


