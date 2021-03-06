#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#define inf 1<<30
#define LL long long
#define maxn 1<<24
using namespace std;
struct Point{
    int x,y;
    bool check(){
        if(x<8&&x>=0&&y<8&&y>=0)
            return true;
        return false;
    }
};
struct Node{
    Point pos[4];
    int step;
}s,e;
map<int,int>m;
map<int,int>::iterator it;
int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool cmp(Point n1,Point n2){
    return n1.x!=n2.x?n1.x<n2.x:n1.y<n2.y;
}
int get_hash(Point *tmp){
    int res=0;
    sort(tmp,tmp+4,cmp);
    for(int i=0;i<4;i++){
        res|=(tmp[i].x<<(6*i));
        res|=(tmp[i].y<<(6*i+3));
    }
    return res;
}
void debug(Point *tmp){
    for(int i=0;i<4;i++)
        cout<<tmp[i].x<<" "<<tmp[i].y<<endl;
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
}
bool bfs(int kind,Node u){
    Node v;
    queue<Node>que;
    u.step=0;
    if(kind==2){
        it=m.find(get_hash(u.pos));
        if(it!=m.end())
            return true;
    }
    m[get_hash(u.pos)]=kind;
    que.push(u);
    while(!que.empty()){
        u=que.front();
        que.pop();
        if(u.step>=4)
            continue;
        for(int i=0;i<4;i++){                
            for(int j=0;j<4;j++){
                v=u;v.step++;
            //    cout<<v.step<<endl;
                v.pos[j].x+=way[i][0];
                v.pos[j].y+=way[i][1];            
                int k;
                if(!v.pos[j].check())
                    continue;
                for(k=0;k<4;k++)
                    if(k!=j&&v.pos[k].x==v.pos[j].x&&v.pos[k].y==v.pos[j].y)
                        break;
                if(k==4){
                    int HASH=get_hash(v.pos);
                    it=m.find(HASH);
                    if(kind==1){            
                        if(it==m.end()){
                            m[HASH]=1;
                            que.push(v);
                        }
                    }
                    else{
                        if(it==m.end()){
                            m[HASH]=2;
                            que.push(v);
                        }
                        else if((*it).second==1)
                            return true;
                    }
                }
                else{
                    v.pos[j].x+=way[i][0];
                    v.pos[j].y+=way[i][1];
                    if(!v.pos[j].check())
                        continue;
                    for(k=0;k<4;k++)
                        if(k!=j&&v.pos[k].x==v.pos[j].x&&v.pos[k].y==v.pos[j].y)
                            break;
                    if(k==4){
                        int HASH=get_hash(v.pos);
                        it=m.find(HASH);
                        if(kind==1){
                            if(it==m.end()){
                                m[HASH]=1;
                                que.push(v);
                            }
                        }
                        else{
                            if(it==m.end()){
                                m[HASH]=2;
                                que.push(v);
                            }
                            else if((*it).second==1)
                                return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
int main(){
    while(scanf("%d%d",&s.pos[0].x,&s.pos[0].y)!=EOF){
        m.clear();
        for(int i=1;i<4;i++)
            scanf("%d%d",&s.pos[i].x,&s.pos[i].y);
        for(int i=0;i<4;i++)
            scanf("%d%d",&e.pos[i].x,&e.pos[i].y);
        for(int i=0;i<4;i++){
            s.pos[i].x--;s.pos[i].y--;
            e.pos[i].x--;e.pos[i].y--;
        }
        bfs(1,s);
        printf("%s\n",bfs(2,e)?"YES":"NO");
    }
    return 0;
}
/*
2 1 8 8 7 8 1 1
1 5 8 7 7 7 2 4

6 5 5 7 5 1 7 1
7 7 6 5 5 7 6 3

4 6 5 6 5 5 5 2
2 2 7 6 5 3 5 2

4 4 5 5 3 4 7 2
2 7 7 2 6 5 4 8

4 2 3 4 5 5 6 6
2 7 4 4 3 5 4 5

3 3 5 3 6 2 6 6
6 3 8 3 6 6 6 8

3 2 5 3 6 2 6 6
6 3 8 3 6 6 6 8

3 4 4 5 5 5 7 5
3 3 4 3 5 3 6 3
*/