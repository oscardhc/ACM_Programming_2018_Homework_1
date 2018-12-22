
//  A.cpp
//  Created on 2018-10-08 11:04

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <bitset>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=1005;
int n,ans;
char c[mx];
bitset<mx> s[mx],a;

int main(){
	//freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	n=read();
	f(i,1,n){
		scanf("%s",c+1);
		f(j,1,n) (c[j]=='1')?s[j].set(i):s[j].reset(i);
	}
	f(i,1,n){
		a.set();
		f(j,i,n){
			a&=s[j];
			ans=max(ans,(int)a.count()*(j-i+1));
		}
	}
	printf("%d\n",ans);
	return 0;
}
