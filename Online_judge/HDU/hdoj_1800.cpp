#include<iostream>#include<cstdio>#include<cstring>#include<cmath>#include<algorithm>using namespace std;int a[3005];bool cmp(int a,int b){    return a>b;}int main(){    int n;    while(scanf("%d",&n)!=EOF){        for(int i=0;i<n;i++)            scanf("%d",&a[i]);        sort(a,a+n,cmp);        int ans=0;        for(int i=0;i<n;i++){            if(a[i]==-1)                continue;            ans++;            int t=a[i];            for(int j=i+1;j<n;j++)                if(a[j]!=-1&&t>a[j]){                    t=a[j];                    a[j]=-1;                }        }        printf("%d\n",ans);    }    return 0;}