#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#define eps 1e-10
#define LL long long
#define LD long double
#define pi acos(-1.0)
#define inf 1LL<<60
using namespace std;
struct Node{
    int j,f;
    double p;
}a[1000];
int n,m;
bool cmp(Node n1,Node n2){
    return n1.p>n2.p;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF&&(n!=-1&&m!=-1)){
        for(int i=0;i<m;i++){
            scanf("%d%d",&a[i].j,&a[i].f);
            a[i].p=a[i].j*1.0/a[i].f;
        }
        sort(a,a+m,cmp);
        double ans=0;
        int tmp=0;
        for(int i=0;i<m;i++){
            if(a[i].f+tmp>=n){
                if(a[i].f+tmp==n)
                    ans+=a[i].j;
                else
                    ans+=a[i].p*(n-tmp);
                break;
            }
            else{
                ans+=a[i].j;
                tmp+=a[i].f;
            }
        }
        printf("%.3f\n",ans);
    }
    return 0;
}