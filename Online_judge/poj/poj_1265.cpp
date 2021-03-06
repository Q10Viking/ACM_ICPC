#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<cassert>
#define LL long long
#define eps 1e-7
#define inf 1<<30
using namespace std;
struct Point{
    int x,y;
}p[105];
int n;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int xmul(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int get_area(){
    int area=0;
    for(int i=1;i<n-1;i++)
        area+=xmul(p[0],p[i],p[i+1]);
    return (area<0?-area:area);
}
int get_inedge(){
    int ans=0;
    for(int i=0;i<n;i++){
        int xx=abs(p[i].x-p[i+1].x);
        int yy=abs(p[i].y-p[i+1].y);
        if(xx==0&&yy==0) ans+=0;
        else if(xx==0) ans+=yy-1;
        else if(yy==0) ans+=xx-1;
        else ans+=gcd(xx,yy)-1;
    }
    return ans+n;
}
int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        p[0].x=0;p[0].y=0;
        for(int i=1;i<=n;i++){
            int xx,yy;
            scanf("%d%d",&xx,&yy);
            p[i].x=p[i-1].x+xx;
            p[i].y=p[i-1].y+yy;
        }
        int area=get_area();
        int edge=get_inedge();
        int in=(area+2-edge)/2;
        printf("Scenario #%d:\n%d %d %.1f\n\n",++cas,in,edge,area/2.0);
    }
    return 0;
}


