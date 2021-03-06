#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#define LL long long
#define lowbit(i) (i&(-i))
using namespace std;
const int N = 200005;
int s[N];
int n,p[N];
int sum(int x){
    int ret=0;
    for(int i=x;i;i-=lowbit(i))
        ret+=s[i];
    return ret;
}
void add(int x){
    for(int i=x;i<=2*n;i+=lowbit(i))
        s[i]+=1;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        p[u]=v;p[v]=u;
    }
    LL a=0,b=0;
    for(int i=1;i<=2*n;i++){
        if(p[i]>i) continue;
        LL x=sum(i)-sum(p[i]-1);
        LL y=(i-p[i]-1)-2*x;   //区间内，除了两端都在，剩下的都为相交
        LL z=n-1-x-y;
        add(p[i]);
        a+=x*z;
        b+=y*(x+z);
    }
    cout<<(LL)n*(n-1)*(n-2)/6-a-b/2<<endl;
    return 0;
}