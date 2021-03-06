#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 100015
#define inf 1<<29
#define LL long long
#define Key_value ch[ch[root][1]][0]
using namespace std;
int pre[N],ch[N][2],root,tot1;  //分别表示父结点，键值，左右孩子(0为左孩子，1为右孩子),根结点，结点数量
int size[N];    //分别表示子树规模，内存池，内存池容量
int rev[N];
int n,q;
inline void NewNode(int &r,int father,int k){
    r=k;
    pre[r]=father;
    rev[r]=0;
    size[r]=1;
    ch[r][0]=ch[r][1]=0;  //左右孩子为空
}
//将延迟标记更新到孩子结点
inline void Push_Down(int r){
    if(rev[r]){
        rev[ch[r][0]]^=1;
        rev[ch[r][1]]^=1;
        swap(ch[r][0],ch[r][1]);
        rev[r]=0;
    }
}
//通过孩子结点更新父结点
inline void Push_Up(int r){
    size[r]=size[ch[r][0]]+size[ch[r][1]]+1;
}
//旋转，kind为1为右旋，kind为0为左旋
inline void Rotate(int x,int kind){
    int y=pre[x];
    Push_Down(y);
    Push_Down(x);
    //类似SBT，要把其中一个分支先给父节点
    ch[y][!kind]=ch[x][kind]; 
    pre[ch[x][kind]]=y;
    //如果父节点不是根结点，则要和父节点的父节点连接起来
    pre[x]=pre[y];
    if(pre[x])
        ch[pre[y]][ch[pre[y]][1]==y]=x;
    ch[x][kind]=y;
    pre[y]=x;
    Push_Up(y);
}inline void zig(int x){
    int y=pre[x], z=pre[y];
    ch[y][1]=ch[x][0]; pre[ch[x][0]]=y;
    ch[x][0]=y; pre[y]=x;
    pre[x]=z;
    if(z) ch[z][ch[z][1]==y]=x;
    Push_Up(y);
}
inline void zag(int x){
    int y=pre[x], z=pre[y];
    ch[y][0]=ch[x][1]; pre[ch[x][1]]=y;
    ch[x][1]=y; pre[y]=x;
    pre[x]=z;
    if(z) ch[z][ch[z][1]==y]=x;
    Push_Up(y);
}
inline void zigzig(int x){
    int y=pre[x], z=pre[y], fz=pre[z];
    ch[z][1]=ch[y][0]; pre[ch[y][0]]=z;
    ch[y][1]=ch[x][0]; pre[ch[x][0]]=y;
    pre[z]=y; ch[y][0]=z;
    pre[y]=x; ch[x][0]=y;
    pre[x]=fz;
    if(fz) ch[fz][ch[fz][1]==z]=x;
    Push_Up(z); Push_Up(y);
}
inline void zagzag(int x){
    int y=pre[x], z=pre[y], fz=pre[z];
    ch[z][0]=ch[y][1]; pre[ch[y][1]]=z;
    ch[y][0]=ch[x][1]; pre[ch[x][1]]=y;
    pre[z]=y; ch[y][1]=z;
    pre[y]=x; ch[x][1]=y;
    pre[x]=fz;
    if(fz) ch[fz][ch[fz][1]==z]=x;
    Push_Up(z); Push_Up(y);
}
inline void zigzag(int x){
    int y=pre[x], z=pre[y], fz=pre[z];
    ch[y][1]=ch[x][0]; pre[ch[x][0]]=y;
    ch[z][0]=ch[x][1]; pre[ch[x][1]]=z;
    pre[y]=pre[z]=x;
    ch[x][0]=y; ch[x][1]=z;
    pre[x]=fz;
    if(fz) ch[fz][ch[fz][1]==z]=x;
    Push_Up(z); Push_Up(y);
}
inline void zagzig(int x){
    int y=pre[x], z=pre[y], fz=pre[z];
    ch[y][0]=ch[x][1]; pre[ch[x][1]]=y;
    ch[z][1]=ch[x][0]; pre[ch[x][0]]=z;
    pre[y]=pre[z]=x;
    ch[x][1]=y; ch[x][0]=z;
    pre[x]=fz;
    if(fz) ch[fz][ch[fz][1]==z]=x;
    Push_Up(z); Push_Up(y);
}
void Splay(int x, int goal){
    int y, z;
    Push_Down(x);
    while(pre[x]!=goal){
        if(pre[pre[x]]==goal){
            y=pre[x]; Push_Down(y); Push_Down(x);
            if(ch[y][1]==x) zig(x);
            else zag(x);
        }
        else{
            y=pre[x]; z=pre[y];
            Push_Down(z); Push_Down(y); Push_Down(x);
            if(ch[z][1]==y){
                if(ch[y][1]==x) zigzig(x);
                else zagzig(x);
            }
            else{
                if(ch[y][0]==x) zagzag(x);
                else zigzag(x);
            }
        }
    }
    Push_Up(x);
    if(pre[x]==0) root=x;
}
//Splay调整，将根为r的子树调整为goal
/*inline void Splay(int r,int goal){
    Push_Down(r);
    while(pre[r]!=goal){
        //父节点即是目标位置，goal为0表示，父节点就是根结点
        if(pre[pre[r]]==goal)
            Rotate(r,ch[pre[r]][0]==r);
        else{
            int y=pre[r];
            int kind=(ch[pre[y]][0]==y);
            //两个方向不同，则先左旋再右旋
            if(ch[y][kind]==r){
                Rotate(r,!kind);
                Rotate(r,kind);
            }
            //两个方向相同，相同方向连续两次
            else{
                Rotate(y,kind);
                Rotate(r,kind);
            }
        }
    }
    Push_Up(r);
    //更新根结点
    if(goal==0) root=r;
}
*/
inline int Get_Max(int r){  
    Push_Down(r);
    while(ch[r][1]){
        r=ch[r][1];
        Push_Down(r); 
    }
    return r;  
}  
inline void Remove(){ // erase the root
    if(ch[root][0]==0){
        root=ch[root][1];
        pre[root]=0;
    }
    else{
        int m=Get_Max(ch[root][0]);
            Splay(m,root);
        ch[m][1]=ch[root][1];
        pre[ch[root][1]]=m;
        root=m;
        pre[root]=0;
        Push_Up(root);
    }
}
inline void BulidTree(int &x,int l,int r,int father){
    if(l>r)
        return;
    int mid=(l+r)>>1;
    NewNode(x,father,mid);
    BulidTree(ch[x][0],l,mid-1,x);
    BulidTree(ch[x][1],mid+1,r,x);
    Push_Up(x);
}
 
struct Node{
    int idx,num;
}a[N];
inline bool cmp(Node n1,Node n2){
    return n1.num!=n2.num?n1.num<n2.num:n1.idx<n2.idx;
}
inline void Init(){
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].num);
        a[i].idx=i;
    }
    sort(a+1,a+1+n,cmp);
    ch[0][0]=ch[0][1]=pre[0]=size[0]=rev[0]=0;
    root=tot1=0;
    BulidTree(root,1,n,0); 
}
int main(){
//freopen("d.out","r",stdin);
    while(scanf("%d",&n)!=EOF&&n){
        Init();
        for(int i=1;i<n;i++){        
            Splay(a[i].idx,0);
            rev[ch[root][0]]^=1;            
            printf("%d ",i+size[ch[root][0]]);            
            Remove();            
        }
        printf("%d\n",n);
    }
    return 0;
}