
//  D.cpp
//  Created on 2018-10-08 14:26

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

int n;
double l,p,ans;

int main(){
	//freopen("D.in","r",stdin);
	//freopen("D.out","w",stdout);
	n=read();
	f(i,1,n) scanf("%lf",&p),ans+=p*(2*l+1),l=(l+1)*p;
	printf("%lf",ans);
	return 0;
}

