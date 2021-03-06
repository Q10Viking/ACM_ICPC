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
struct Node{
    int val,cnt;
}a[10];
int c[15][15];
int c1[105],c2[105];
int main(){
    int t,n,m;
    scanf("%d",&t);
    for(int i=0;i<=10;i++){
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
            scanf("%d%d",&a[i].val,&a[i].cnt);
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=0;i<=a[0].cnt*a[0].val&&i<=n;i+=a[0].val)
            c1[i]=1;
        for(int i=1;i<m;i++){
            for(int j=0;j<=n;j++)
                for(int k=0;k<=a[i].cnt*a[i].val;k+=a[i].val)
                    if(j+k<=n)
                        c2[j+k]+=c1[j];
            for(int j=0;j<=n;j++){
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        printf("%d\n",c1[n]);
    }
    return 0;
}