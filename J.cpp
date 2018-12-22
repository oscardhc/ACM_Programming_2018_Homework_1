
//  J.cpp
//  Created on 2018-10-16 15:11

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=1e6+233,mod=998244353;
ll n,s,d[mx];pair<ll,ll> m[mx];

inline ll pw(ll a,ll b,ll c=1){
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) c=1ll*c*a%mod;
	return c;
}

int main(){
	//freopen("J.in","r",stdin);
	//freopen("J.out","w",stdout);
	n=read();
	f(i,1,n) m[i].first=read(),m[i].second=i;
	s=read();
	sort(m+1,m+1+n);
	ll pa=0,pa2=0,pd=0;
	f(i,1,n){
		ll cu=m[i].first,cuid=i,prr=pw(i-1,mod-2);
		while(m[cuid+1].first==cu) cuid++;
		f(j,i,cuid){
			d[j]=(1ll*m[j].second*m[j].second%mod*(i-1)%mod-2ll*m[j].second*pa%mod+pa2+mod)%mod;
			d[j]=(d[j]+pd)%mod;
			d[j]=1ll*d[j]*prr%mod;
			if(m[j].second==s){
				printf("%lld\n",d[j]);
				return 0;
			}
		}
		f(j,i,cuid){
			pa+=m[j].second;
			if(pa>=mod) pa-=mod;
			pa2+=1ll*m[j].second*m[j].second%mod;
			if(pa2>=mod) pa2-=mod;
			pd+=d[j];
			if(pd>=mod) pd-=mod;
		}
		i=cuid;
	}
	return 0;
}

