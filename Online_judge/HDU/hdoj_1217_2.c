#include<stdio.h>
#include<string.h>
double e[31];
int n,m;
struct map
{
    int a,b;
    double c;
}
d[901];
int bf(int u)
{
    int flag,i;
    while(1)
    {
        flag=0;
        for(i=1;i<=m;i++)
        {
            if(e[d[i].a]*d[i].c>e[d[i].b])
            {
                flag=1;
                e[d[i].b]=e[d[i].a]*d[i].c;
            }
        }
        if(e[u]>1)  return 1;
        if(flag==0)  return 0;
    }
    return 0;
}
int main()
{
    int i,j,num=0;

    char str[31][100],str1[100],str2[100];
    while(scanf("%d",&n),n!=0)
    {
        num++;
    
        for(i=1;i<=n;i++)
        {
            scanf("%s",str[i]);
        }        
        scanf("%d",&m);
        for(j=1;j<=m;j++)
        {
            scanf("%s%lf%s",str1,&d[j].c,str2);
         
            for(i=1;i<=n;i++)
            {
                if(strcmp(str1,str[i])==0)
                {
                    d[j].a=i;
                    break;
                }
            }
            for(i=1;i<=n;i++)
            {
                if(strcmp(str2,str[i])==0)
                {
                    d[j].b=i;
                    break;
                }
            }
                    
        }
        printf("Case %d: ",num);
                for(j=1;j<=n;j++)
                e[j]=0;
                    e[1]=1;
            if(bf(1)==1)
            {
                printf("Yes\n");
                }
            else     printf("No\n");
        }
    return 0;
}

            






    
