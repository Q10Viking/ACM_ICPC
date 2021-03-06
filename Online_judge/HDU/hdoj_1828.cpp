#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <ctime>
#define lson step<<1
#define rson step<<1|1
#define mem(a,b) memset(a,b,sizeof(a))    
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef long long LL;
const int N = 5005;
struct Segtree{
    int left,right,cover,cnt,len;
    bool left_cover,right_cover;
}L[N<<3];
struct Line{
    int y,x1,x2,f;
    Line(){}
    Line(int _y,int _x1,int _x2,int _f=1):y(_y),x1(_x1),x2(_x2),f(_f){}
    bool operator<(const Line &l)const{
        return y<l.y;
    }
}line[N<<1];
int n,m,x[N<<1];
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].cover=L[step].cnt=L[step].len=0;
    L[step].left_cover=L[step].right_cover=false;
    if(l==r) return ;
    int m=(l+r)>>1;
    bulid(lson,l,m);
    bulid(rson,m+1,r);
}
void cal(int step){
    if(L[step].cover) L[step].len=x[L[step].right]-x[L[step].left-1],L[step].left_cover=L[step].right_cover=true;
    else if(L[step].left==L[step].right) L[step].len=0,L[step].left_cover=L[step].right_cover=false;
    else L[step].len=L[lson].len+L[rson].len,L[step].left_cover=L[lson].left_cover,L[step].right_cover=L[rson].right_cover;
    if(L[step].cover) L[step].cnt=1;
    else if(L[step].left==L[step].right) L[step].cnt=0;
    else L[step].cnt=L[lson].cnt+L[rson].cnt-(L[lson].right_cover&&L[rson].left_cover);
}
void update(int step,int l,int r,int f){
    if(L[step].left==l&&L[step].right==r){
        L[step].cover+=f;
        cal(step);
        return ;
    }
    int m=(L[step].left+L[step].right)>>1;
    if(r<=m) update(lson,l,r,f);
    else if(l>m) update(rson,l,r,f);
    else {
        update(lson,l,m,f);
        update(rson,m+1,r,f);
    }
    cal(step);
}
int main(){
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            line[i<<1]=Line(y1,x1,x2);
            line[i<<1|1]=Line(y2,x1,x2,-1);
            x[i<<1]=x1;x[i<<1|1]=x2;
        }
        int pre=0,ans=0;
        sort(x,x+(n<<1));
        sort(line,line+(n<<1));
        m=unique(x,x+(n<<1))-x;
        bulid(1,1,m-1);
        for(int i=0;i<(n<<1);i++){
            int l=lower_bound(x,x+m,line[i].x1)-x+1;
            int r=lower_bound(x,x+m,line[i].x2)-x+1;
            if(i) ans+=2*(line[i].y-line[i-1].y)*(L[1].cnt);
            update(1,l,r-1,line[i].f);
            ans+=abs(L[1].len-pre);
            pre=L[1].len;
        }
        printf("%d\n",ans);
    }
    return 0;
}