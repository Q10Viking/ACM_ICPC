#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 30
#define inf 1<<29
#define MOD 2007
#define LL long long
using namespace std;
int couple,malelike[N][N],femalelike[N][N];
int malechoice[N],femalechoice[N];
int malename[N],femalename[N];
char str[N];
queue<int>freemale;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&couple);
        while(!freemale.empty())
            freemale.pop();
        for(int i=0;i<couple;i++){
            scanf("%s",str);
            malename[i]=str[0]-'a';
            freemale.push(malename[i]);
        }
        sort(malename,malename+couple);
        for(int i=0;i<couple;i++){
            scanf("%s",str);
            femalename[i]=str[0]-'A';
        }
        for(int i=0;i<couple;i++){
            scanf("%s",str);
            for(int j=0;j<couple;j++)
                malelike[i][j]=str[j+2]-'A';
        }
        for(int i=0;i<couple;i++){
            scanf("%s",str);
            for(int j=0;j<couple;j++)
                femalelike[i][str[j+2]-'a']=couple-j;
            femalelike[i][couple]=0;
        }
        memset(malechoice,0,sizeof(malechoice));
        for(int i=0;i<couple;i++)
            femalechoice[i]=couple;
        while(!freemale.empty()){
            int male=freemale.front();
       //     freemale.pop();
            int female=malelike[male][malechoice[male]];
            if(femalelike[female][male]>femalelike[female][femalechoice[female]]){
            freemale.pop();
                if(femalechoice[female]!=couple){
                    freemale.push(femalechoice[female]);
                    malechoice[femalechoice[female]]++;
                }
                femalechoice[female]=male;
            }
            else //if(femalelike[female][male]<femalelike[female][femalechoice[female]])
                malechoice[male]++;
        }
        for(int i=0;i<couple;i++)
            printf("%c %c\n",malename[i]+'a',malelike[malename[i]][malechoice[malename[i]]]+'A');
        if(t) puts("");
    }
    return 0;
}





