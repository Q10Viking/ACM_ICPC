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
#include<ctime>
#include<cassert>
#define LL long long
#define eps 1e-8
#define inf 999999.0
#define zero(a) abs(a)<eps
#define N 20
#define pi acos(-1.0)
using namespace std;
struct Point{
    int x,y;
}p[50005];
int n;
vector<Point >s;
int dist(Point p1,Point p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
int xmul(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//Graham_scan求凸包
bool cmp(Point p1,Point p2){
    if(xmul(p[0],p1,p2)>eps)  return true;
    else if(zero(xmul(p[0],p2,p1))&&dist(p[0],p1)<dist(p[0],p2))  return true;
    return false;
}
void Graham_scan(){
    for(int i=1;i<n;i++)
        if(p[i].y<p[0].y||(p[i].y==p[0].y&&p[i].x<p[0].x))
            swap(p[i],p[0]);
    sort(p+1,p+n,cmp);
    s.clear();
    s.push_back(p[0]);s.push_back(p[1]);
    for(int i=2;i<n;i++){
        while(s.size()>=2&&xmul(s[s.size()-2],s[s.size()-1],p[i])<eps) s.pop_back();
        s.push_back(p[i]);
    }
}
void Rotating_Calipers(){
    int ans=0,len=s.size();
    s.push_back(s[0]);
    for(int i=0;i<len;i++){
        int k=i;
        for(int j=i+1;j<len;j++){
            while(abs(xmul(s[i],s[j],s[k+1]))>abs(xmul(s[i],s[j],s[k])))
                k=(k+1)%len;
            ans=max(ans,max(abs(xmul(s[i],s[j],s[k+1])),abs(xmul(s[i],s[j],s[k]))));
        }
    }
    printf("%.2f\n",ans/2.0);
}
int main(){
    //freopen("f.in","r",stdin);
    while(scanf("%d",&n)!=EOF&&n!=-1){
        for(int i=0;i<n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        Graham_scan();
        Rotating_Calipers();
    }
    return 0;
}



