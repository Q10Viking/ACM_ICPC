#include<stdio.h>
int main()
{
    int i,a,b,n,f[1000],m;
    
    while(scanf("%d%d%d",&a,&b,&n),a!=0||b!=0||n!=0)
    {f[1]=1;
    f[2]=1;
        for(i=3;i<=50;i++)    
        {        
            f[i]=(f[i-1]*a+f[i-2]*b)%7;        
            if(f[i]==1&&f[i-1]==1)
                break;
        }
        m=i-2;
        f[0]=f[i-2];
        printf("%d\n",f[n%m]);
    }
    return 0;
}


        

