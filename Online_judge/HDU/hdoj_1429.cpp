#include<stdio.h>
int move[4][2]= {{0,1},{0,-1},{1,0},{-1,0}};
int queue[2000000][3];
int n,m,t;
int flag;
int head,tail;
char a[25][25];
int b[25][25][1100];
void bfs(int i0,int i1,int i2)
{
    int i;
    int huan,cot;
    int j0,j1,j2;
    for(i=0; i<4; i++)
    {
        j0=i0+move[i][0];
        j1=i1+move[i][1];
        if(j0>n||j0<0)continue;
        if(j1>m||j1<0)continue;
        if(a[j0][j1]=='*')continue;
        if(b[i0][i1][i2]>=t){flag=1;break;}
        //cout<<j0<<" "<<j1<<endl;
        if(!b[j0][j1][i2]&&(a[j0][j1]=='.'||a[j0][j1]=='@'))
        {
            b[j0][j1][i2]=b[i0][i1][i2]+1;
            queue[tail][0]=j0;
            queue[tail][1]=j1;
            queue[tail][2]=i2;
            tail++;
            continue;
        }
        if(a[j0][j1]>='a'&&a[j0][j1]<='j')
        {
            huan=a[j0][j1]-'a';
            cot=1;
            cot=cot<<huan;
            j2=i2|cot;
            if(b[j0][j1][j2]>b[i0][i1][i2]+1||b[j0][j1][j2]==0)
            {
                b[j0][j1][j2]=b[i0][i1][i2]+1;
                queue[tail][0]=j0;
                queue[tail][1]=j1;
                queue[tail][2]=j2;
                tail++;
            }
            continue;
        }
        if(a[j0][j1]>='A'&&a[j0][j1]<='J')
        {
            huan=a[j0][j1]-'A';
            cot=i2>>huan;
            if(cot%2==0)continue;
            if(b[j0][j1][i2]>b[i0][i1][i2]+1||b[j0][j1][i2]==0)
            {
                b[j0][j1][i2]=b[i0][i1][i2]+1;
                queue[tail][0]=j0;
                queue[tail][1]=j1;
                queue[tail][2]=i2;
                tail++;
            }
            continue;
        }
        if(a[j0][j1]=='^')
        {
            b[j0][j1][1]=b[i0][i1][i2]+1;
            flag=1;
            break;
        }
    }
}
int main()
{
    int x0,x1,y0,y1;
    int i,j,k;
    //freopen("input.txt","r",stdin);
    while(scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
        //getchar();
        n=n-1;
        m=m-1;
        for(i=0; i<=n; i++)
        {
            scanf("%s",a[i]);
            for(j=0; j<=m; j++)
            {
               //scanf("%c",&a[i][j]);
                if(a[i][j]=='@')
                {
                    x0=i;
                    y0=j;
                }
                if(a[i][j]=='^')
                {
                    x1=i;
                    y1=j;
                }
            }
        }
        for(i=0; i<25; i++)
            for(j=0; j<25; j++)
                for(k=0; k<1025; k++)
                    b[i][j][k]=0;
        flag=0;
        head=0;
        tail=0;
        b[x0][y0][0]=1;
            //printf("%d %d\n",head,tail);
        bfs(x0,y0,0);
        while(head!=tail&&flag==0)
        {
            bfs(queue[head][0],queue[head][1],queue[head][2]);
            head++;
        }
        b[x1][y1][1]=b[x1][y1][1]-1;
        if(b[x1][y1][1]<t)
            printf("%d\n",b[x1][y1][1]);
        else printf("-1\n");
    }
    return 0;
}
