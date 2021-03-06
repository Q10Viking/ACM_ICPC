#include<stdio.h>
#include<string.h>
//大数加法：
void add(char *a,char *b,char *c)
{
    int carry,i,tem,alen=strlen(a)-1,blen=strlen(b)-1,k;
    k=(alen>blen?alen:blen)+1;
    i=carry=0;
    c[k+1]='\0';
    while(alen>=0&&blen>=0)
    {
        tem=a[alen--]-'0'+b[blen--]-'0'+carry;
        if(tem>9)
        {
            carry=1;
            tem=tem%10;
        }
        else
            carry=0;
        c[k--]=tem+'0';
    }
    while(alen>=0)
    {
        tem=carry+a[alen--]-'0';
        if(tem>9)
        {
            carry=1;
            tem=tem%10;
        }
        else
            carry=0;
        c[k--]=tem+'0';
    }
    while(blen>=0)
    {
        tem=carry+b[blen--]-'0';
        if(tem>9)
        {
            carry=1;
            tem=tem%10;
        }
        else
            carry=0;
        c[k--]=tem+'0';
    }
    if(carry)
        c[k]='1';
    else
        strcpy(c,c+1);
}
//大数乘法：
void mul(char *a,char *b,char *c)
{
    int i,j,alen=strlen(a),blen=strlen(b),t[20000];
    if(a[0]=='0'||b[0]=='0')
    {
        c[0]='0';
        c[1]='\0';
        return;
    }
    for(i=0;i<alen+blen;i++)
        t[i]=0;
    for(i=0;i<alen;i++)
        for(j=0;j<blen;j++)
            t[i+j+1]+=(a[i]-'0')*(b[j]-'0');
    for(i=alen+blen-1;i>0;i--)
    {
        t[i-1]+=t[i]/10;
        t[i]%=10;
    }
    if(t[0]==0)
        i=1;
    else
        i=0;
    for(j=0;i<alen+blen;i++)
        c[j++]=t[i]+'0';
    c[j]='\0';
}
//大数除以整形数（返回余数）：
int d(char *a,int b,char *c)
{
    int r=0,i,alen=strlen(a),tem;
    if(b==0)
    {
        printf("0不能作为除数!!\n");
        return 0;
    }
    for(i=0;i<alen;i++)
    {
        tem=a[i]-'0'+r*10;
        c[i]=tem/b+'0';
        r=tem%b;
    }
    i=0;
    while(c[i]=='0')
        i++;
    if(c[i]!='\0')
        strcpy(c,c+i);
    else
        strcpy(c,"0");
    return r;
}
void cal(char *a,char *b,int c)
{
int i;
for(i=0;i<c;i++)
   mul(a,b,b);
}
char s[31][31][2000],t1[2000],t2[2000],t3[2000],t4[2000];
int main(void)
{
int n,j,i;
char t[2000],flag[31][31];
for(i=0;i<31;i++)
   for(j=0;j<31;j++)
    flag[i][j]=0;
while(scanf("%d%d",&n,&j)!=EOF)
{
   if(flag[n][j])
   {
    printf("%s\n",s[n][j]);
    continue;
   }
   sprintf(t,"%d",j);
   strcpy(s[n][j],"0");
   if(n%2)
   {
    strcpy(t2,"1");
    cal(t,t2,(n+1)/2);
    strcpy(t3,"1");
    cal(t,t3,n);
    strcpy(t1,"1");
    cal(t3,t1,n);
    add(t1,s[n][j],s[n][j]);
    strcpy(t1,"1");
    cal(t2,t1,(n-1)/2);
    mul(t,t1,t1);
    mul("2",t1,t1);
    add(t1,s[n][j],s[n][j]);
    strcpy(t1,"1");
    cal(t,t1,(n*n+1)/2);
    add(t1,s[n][j],s[n][j]);
    strcpy(t1,"1");
    cal(t3,t1,(n+1)/2);
    mul("4",t1,t1);
    add(t1,s[n][j],s[n][j]);
    d(s[n][j],8,s[n][j]);
    printf("%s\n",s[n][j]);
   }
   else
   {
    strcpy(t2,"1");
    cal(t,t2,n/2);
    strcpy(t3,t2);
    mul(t3,t2,t2);
    strcpy(t1,"1");
    cal(t2,t1,n);
    add(t1,s[n][j],s[n][j]);
    strcpy(t1,"1");
    cal(t3,t1,n/2);
    mul("2",t1,t1);
    add(t1,s[n][j],s[n][j]);
    strcpy(t1,"1");
    cal(t3,t1,n);
    strcpy(t4,t1);
    mul("3",t1,t1);
    add(t1,s[n][j],s[n][j]);
    mul(t3,t4,t4);
    mul("2",t4,t4);
    add(t4,s[n][j],s[n][j]);
    d(s[n][j],8,s[n][j]);
    printf("%s\n",s[n][j]);
   }
   flag[n][j]=1;
}
}