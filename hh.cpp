
//  hh.cpp
//  Created on 2018-10-18 21:16

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

int main(){
	//freopen("hh.in","r",stdin);
	//freopen("hh.out","w",stdout);
	f(a,0,1) f(b,0,1) f(c,0,1) printf("%d %d\n",!(a&(!(b&c))),!((!(a&b))&c));
	return 0;
}

