#include<stdio.h>
int way[8][2]={{2,1},{1,2},{-1,2},{-2,1},{2,-1},{1,-2},{-2,-1},{-1,-2}};
int count[9][9];
typedef struct
{
    int x,y;
}point ;
int bfs(point s,point e)
{
    int i;
    point que[70];
    int head=0,tail=0,flag[9][9];
    point tt;
    memset(flag,0,sizeof(flag));
    que[tail++]=s;
    count[s.x][s.y]=0;
    flag[s.x][s.y]=1;
    while(head<tail)
    {
        s=que[head++];        
        for(i=0;i<8;i++)
        {
            tt.x=s.x+way[i][0];
            tt.y=s.y+way[i][1];
            if(tt.x>=1&&tt.x<=8&&tt.y>=1&&tt.y<=8&&flag[tt.x][tt.y]==0)
            {
                que[tail++]=tt;
                flag[tt.x][tt.y]=1;
                count[tt.x][tt.y]=count[s.x][s.y]+1;
                if(tt.x==e.x&&tt.y==e.y)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}    

int main()
{
    char str1[3],str2[3];
    point s,e;
    while(scanf("%s%s",str1,str2)!=EOF)
    {
        s.x=str1[1]-'0';
        s.y=str1[0]-'a'+1;
        e.x=str2[1]-'0';
        e.y=str2[0]-'a'+1;
        bfs(s,e);
        printf("To get from %s to %s takes %d knight moves.\n",str1,str2,count[e.x][e.y]);
    }
    return 0;
}
         
        
