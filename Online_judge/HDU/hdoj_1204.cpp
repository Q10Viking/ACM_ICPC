#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#define LL long long
#define MOD 1000000007
#define eps 1e-6
#define zero(a)  fabs(a)<eps
using namespace std;
int n,m,num[105],cnt,tot;
double a[105][105];
void debug(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++)
           printf("%.2f ",a[i][j]);
        printf("\n");
    }
}
int get(int x){
    if(x<0) x=-x;
    if(x>tot) x=m-x;
    return x;
}
void dfs(int x){
    num[x]=cnt++;
    int t=get(x-2);
    if(num[t]==-1) dfs(t);
    t=get(x+2);
    if(num[t]==-1) dfs(t);
}
bool gauss(int n){
    int i,j;
    for(i=0,j=0;i<n&&j<n;j++){
        int k;
        for(k=i;k<n;k++)
            if(!zero(a[k][j]))
                break;
        if(k<n){
            if(i!=k)
            for(int r=j;r<=n;r++) swap(a[i][r],a[k][r]);
            double tt=1/a[i][j];
            for(int r=j;r<=n;r++)
                a[i][r]*=tt;
            for(int r=0;r<n;r++)
                if(r!=i){
                    for(int t=n;t>=j;t--)
                        a[r][t]-=a[r][j]*a[i][t];
                }
            i++;
        }
    }
    for(int r=i;r<n;r++)
        if(!zero(a[r][n]))
            return false;
    return true;
}
int main(){
    int n,m;
    double p,q;
    while(scanf("%d%d%lf%lf",&n,&m,&p,&q)!=EOF){
        double x=p*(1-q);
        double y=q*(1-p);
        double z=1-x-y;
        memset(a,0,sizeof(a));
        int tot=n+m+1;
        for(int i=0;i<tot;i++){
            if(i==0) a[i][i]=1;
            else if(i==n+m) a[i][i]=1,a[i][tot]=1;
            else a[i][i-1]=y,a[i][i+1]=x,a[i][i]=z-1;
        }
      //  debug(tot);
        gauss(tot);
     //   debug(tot);
        printf("%.2f\n",a[n][tot]);
    }
    return 0;
}

