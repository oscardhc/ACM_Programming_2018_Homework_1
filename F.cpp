
//  F.cpp
//  Created on 2018-10-16 14:42

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=1005;
int n,a[mx];bitset<(int)4e7+233> m,bk;

inline int sol(int cu){
	//printf("...%d\n",cu);
	if(bk[cu]) return (bool)m[cu];
	if(!cu) return 1;
	f(i,1,n){if(cu-a[i]>=0&&sol(cu-a[i])) return bk[cu]=1,m[cu]=1;}
	return bk[cu]=1,0;
}

int main(){
	//freopen("F.in","r",stdin);
	//freopen("F.out","w",stdout);
	n=read();
	f(i,1,n) a[i]=read();
	int t=read();while(t--){
		printf("%s\n",sol(read())?"YES":"NO");
	}
	return 0;
}

