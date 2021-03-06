#include<iostream>
#include<iomanip>

using namespace std;

class zsl
{
    public:
        int j, f;
        double ratio;
}a[1001];

int m,n;

void kp(int L, int R)
{
    int i=L,j=R;
    double mid=a[L+R>>1].ratio;
    while(i<j)
    {
        while(a[i].ratio > mid) ++i;
        while(a[j].ratio < mid) --j;
        if(i<=j)
        {
            swap(a[i], a[j]);
            ++i;    --j;
        }
    }
   
    if(i<R) kp(i, R);
    if(L<j) kp(L, j);
}

void work()
{
    double ans=0;
    for(int i=1; i<=n; ++i)
    {
        if(m >= a[i].f)
        {
            m-=a[i].f;
            ans+=a[i].j;
        }
        else
        {
            ans+=(a[i].j*m+0.0)/a[i].f;
            break;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
   
    cout<<fixed<<setprecision(3);
    while(1)
    {
        cin>>m>>n;
        if(m==-1 && n==-1)  break;
       
        for(int i=1; i<=n; ++i)
        {
            cin>>a[i].j>>a[i].f;
            a[i].ratio = (a[i].j+0.0)/a[i].f;
        }
        kp(1, n);
        work();
    }
   
    return 0;
}

