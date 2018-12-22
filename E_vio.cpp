
//  E_vio.cpp
//  Created on 2018-10-08 14:55

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=1e5+233;
int n,m;ll t[mx];

inline ll ts(ll s,ll ret=1){
	for(;s;s/=10) ret*=(s%10+1);
	return ret-1;
}
int main(){
	freopen("E.in","r",stdin);
	freopen("E_vio.out","w",stdout);
	n=read();f(i,1,n) t[i]=read();
	m=read();
	while(m--){
		int a=read(),b=read(),c=read();
		if(a){
			ll ret=0;
			f(i,b,c) ret+=t[i];
			printf("%lld\n",ret);
		}else{
			f(i,b,c) t[i]=ts(t[i]);
		}
	}
	return 0;
}
