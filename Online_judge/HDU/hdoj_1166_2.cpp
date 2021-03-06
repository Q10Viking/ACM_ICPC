#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
struct line
{
    int left,right,mid,num;
}L[150010];
int num[50001];
int sum;
int  bulid(int step,int l,int r)
{
    L[step].left=l;
    L[step].right=r;
    L[step].mid=(l+r)/2;
    if(l==r)
        return L[step].num=num[l];
    return L[step].num=bulid(2*step,l,(l+r)/2)+bulid(2*step+1,(l+r)/2+1,r);
}
void add(int step,int a,int b)
{
    L[step].num+=b;
    if(L[step].left==L[step].right)
        return;
    if(L[step].mid<a)
        add(2*step+1,a,b);
    else  
        add(2*step,a,b);
}
int query(int step,int a,int b)
{
    if(L[step].left==a&&L[step].right==b)
        return L[step].num;
    if(L[step].mid<a)
        return query(2*step+1,a,b);
    else
        if(L[step].mid>=b)
            return query(2*step,a,b);
        else
            return query(2*step,a,L[step].mid)+query(2*step+1,L[step].mid+1,b);
}
int main()
{
    int t;
    scanf("%d",&t);
    int Case=0;
    while(t--)
    {
        int n;
        Case++;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        bulid(1,1,n);
        printf("Case %d:\n",Case);
        string str;
        while(str.clear(),cin>>str,str!="End")
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(str=="Add")
                add(1,a,b);
            else  if(str=="Sub")
                add(1,a,-b);
            else
                printf("%d\n",query(1,a,b));
        }
    }
    return 0;
}