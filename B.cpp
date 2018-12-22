
//  B.cpp
//  Created on 2018-10-16 14:06

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=1e3+5,mod=1e9+7;
int f[mx];

int cal(int x){
	if(f[x]) return f[x];
	int re=1;
	for(int i=1;i+i<=x;i++){
		re=re+cal(i);
		if(re>=mod) re-=mod;
	}
	return f[x]=re;
}

int main(){
	//freopen("B.in","r",stdin);
	//freopen("B.out","w",stdout);
	printf("%d\n",cal(read()));
	return 0;
}

