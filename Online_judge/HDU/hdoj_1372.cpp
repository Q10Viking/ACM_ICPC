#include<stdio.h>
int x1,x2,y1,y2,x,y,a[9][9],b[90][2];
int k[8][2]={-1,-2,-2,-1,-2,1,-1,2,1,-2,2,-1,2,1,1,2};
int main()
{
    int fbs();
    char c1[5],c2[5];
    int p,i,j,y3;
    while(scanf("%s %s",&c1,&c2)!=EOF)
    {
        // getchar();
        y1=c1[1]-'0';
        y2=c2[1]-'0';
        x1=c1[0]-'a'+1;
        x2=c2[0]-'a'+1;
        y3=y1;
        if(x1==x2&&y1==y2)
            printf("To get from %c%d to %c%d takes 0 knight moves.\n",c1[0],y1,c2[0],y2);
        else
        {
           for(i=1;i<9;i++)
               for(j=1;j<9;j++)
                   a[i][j]=0;
           p=fbs();
           printf("To get from %c%d to %c%d takes %d knight moves.\n",c1[0],y3,c2[0],y2,p);
        }
    }
    return 0;
}
int tru(int n,int m)
{
    if(n>0&&n<9&&m>0&&m<9)
        return 0;
    else
        return 1;
}
int fbs()
{
    int head,tail,l;
    head=0;tail=1;
    b[0][0]=x1;b[0][1]=y1;
    while(head!=tail)
    {
        x1=b[head][0];
        y1=b[head++][1];
        for(l=0;l<8;l++)
        {
            x=x1+k[l][0];
            y=y1+k[l][1];
            if(tru(x,y))
                continue;
            if(a[x][y])
                continue;
            b[tail][0]=x;
            b[tail++][1]=y;
            a[x][y]=a[x1][y1]+1;
            if(x==x2&&y==y2)
                return a[x][y];
        }
    }
}