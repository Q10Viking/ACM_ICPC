#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<map>
#define inf 1<<30
#define N 155
using namespace std;
struct Node{
       int u,v,w,next;
}edge[100005];
struct Pos{
     string s;
}name[155];
map<string,int>m;
int start[155],cnt,n,mm,a,b,tot;
void addedge(int u,int v,int w){
     edge[cnt].u=u;edge[cnt].v=v;
     edge[cnt].w=w;edge[cnt].next=start[u];
     start[u]=cnt++;
}
int spfa(){
     bool flag[155];
     int dist[155];
     for(int i=0;i<N;i++)
        dist[i]=inf;
     memset(flag,false,sizeof(flag));
     queue<int>que;
     dist[a]=0;
     que.push(a);
     flag[a]=true;
     while(!que.empty()){
          int u=que.front();
          que.pop();
          flag[u]=false;
          for(int i=start[u];i!=-1;i=edge[i].next){
              int v=edge[i].v,w=edge[i].w;
              if(dist[v]>dist[u]+w){
                   dist[v]=dist[u]+w;
                   if(!flag[v]){
                        flag[v]=true;
                        que.push(v);
                   }
              }
          }
     }
     return dist[b]==inf?-1:dist[b];
}      
int main(){
    while(scanf("%d",&mm)!=EOF){        
           if(mm==-1) break;
           m.clear();
           char u[36],v[36];
           string tu,tv;
           cnt=0;tot=0;
           memset(start,-1,sizeof(start));
           scanf("%s%s",u,v);
           tu=string(u);
           tv=string(v);
           if(!m.count(tu)) m[tu]=tot++;
           if(!m.count(tv)) m[tv]=tot++;      
           a=m[tu];b=m[tv];   
           for(int i=1;i<=mm;i++){
                int w;  
                scanf("%s%s%d",u,v,&w);      
           //     scanf("%d",&w);
                tu=string(u);
                tv=string(v);
                if(!m.count(tu)) m[tu]=tot++;
                if(!m.count(tv)) m[tv]=tot++;   
                addedge(m[tu],m[tv],w);
                addedge(m[tv],m[tu],w);
           }   
           if(a==b)
               printf("0\n");
           else                 
           printf("%d\n",spfa());
    }
    return 0;
}
/*
6
xiasha westlake
xiasha station 60
xiasha ShoppingCenterofHangZhou 30
station westlake 20
ShoppingCenterofHangZhou supermarket 10
xiasha supermarket 50
supermarket westlake 10
    
*/
