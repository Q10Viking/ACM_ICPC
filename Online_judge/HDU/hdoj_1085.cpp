#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#define LL  long long
#define MOD 29
#define eps 1e-6
#define N 100010
#define zero(a)  fabs(a)<eps
using namespace std;
int val[3]={1,2,5},cnt[3];
int c1[10005],c2[10005];
int main(){
    while(scanf("%d%d%d",&cnt[0],&cnt[1],&cnt[2])!=EOF&&cnt[0]+cnt[1]+cnt[2]){
        int mmax=0;
        for(int i=0;i<3;i++)
            mmax+=cnt[i]*val[i];
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=0;i<=cnt[0];i++)
            c1[i]=1;
        for(int i=1;i<3;i++){
            for(int j=0;j<=mmax;j++)
                for(int k=0;k<=val[i]*cnt[i];k+=val[i])
                    if(j+k<=mmax&&c1[j])
                         c2[j+k]=c1[j];
            for(int j=0;j<=mmax;j++){
                c1[j]=c2[j];
            //    cout<<c1[j]<<endl;
                c2[j]=0;
            }
        }
        int i;
        for(i=0;i<=mmax+1;i++)
            if(c1[i]==0)
                break;
        printf("%d\n",i);
    }
    return 0;
}
