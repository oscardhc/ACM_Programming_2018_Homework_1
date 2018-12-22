
//  E.cpp
//  Created on 2018-10-08 14:36

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=131072;
int n,t2[mx<<1],q;ll t1[mx<<1];

inline ll ts(ll s,ll ret=1){
	for(;s;s/=10) ret*=(s%10+1);
	return ret-1;
}

inline ll qry(int l,int r,ll ret=0){
	for(l=l+mx-1,r=r+mx+1;l^r^1;l>>=1,r>>=1){
		if(l&1^1) ret+=t1[l^1];
		if(r&1)   ret+=t1[r^1];
	}
	return ret;
}
inline void upd(int cu,int l,int r,int lr,int rr){
	if(t2[cu]) return;
	if(cu>=mx){
		ll tp=ts(t1[cu]);
		t2[cu]=t1[cu]==tp;t1[cu]=tp;
		return;
	}
	int m=(l+r)>>1;
	if(lr<=m) upd(cu<<1,l,m,lr,min(rr,m));
	if(rr>m) upd(cu<<1|1,m+1,r,max(lr,m+1),rr);
	t1[cu]=t1[cu<<1]+t1[cu<<1|1];
	t2[cu]=min(t2[cu<<1],t2[cu<<1|1]);
}

int main(){
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	n=read();
	f(i,1,n) t1[i+mx]=read(),t2[i+mx]=t1[i+mx]==ts(t1[i+mx]);
	fd(i,mx-1,1) t1[i]=t1[i<<1]+t1[i<<1|1],t2[i]=min(t2[i<<1],t2[i<<1|1]);
	q=read();
	while(q--){
		int a=read(),b=read(),c=read();
		if(a) printf("%lld\n",qry(b,c));
		else upd(1,0,mx-1,b,c);
	}
	return 0;
}

