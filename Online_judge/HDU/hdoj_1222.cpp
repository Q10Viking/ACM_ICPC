#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int t;
    int n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        if(gcd(n,m)==1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}