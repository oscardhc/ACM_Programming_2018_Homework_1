
//  G.cpp
//  Created on 2018-10-19 09:50

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=262144<<1;
int m;char str[15];
int t[mx<<1][6],hd=mx>>1,tl=hd-1,ans=0,flag=0,rev;

inline void pup(int p){
	t[p][0]=t[p<<1|1][1+t[p<<1][0]];
	t[p][1]=t[p<<1|1][1+t[p<<1][1]];
	t[p][2]=t[p<<1|1][1+t[p<<1][2]];
	t[p][3]=t[p<<1][4+t[p<<1|1][3]];
	t[p][4]=t[p<<1][4+t[p<<1|1][4]];
	t[p][5]=t[p<<1][4+t[p<<1|1][5]];
}
inline void upd(int p,int v){
	p+=mx;
	t[p][0]=t[p][3]=v;
	t[p][1]=t[p][4]=1;
	t[p][2]=t[p][5]=!(v&1);
	for(p>>=1;p;p>>=1) pup(p);
}
inline void qry(int cu,int l,int r,int ql,int qr){
	if(l==ql&&r==qr){
		if(flag) flag=0,ans=t[cu][0+rev*3];
		else ans=t[cu][1+ans+rev*3];
		return;
	}
	int md=(l+r)>>1;
	if(!rev){
		if(ql<=md) qry(cu<<1,l,md,ql,min(qr,md));
		if(qr>md) qry(cu<<1|1,md+1,r,max(md+1,ql),qr);
	}else{
		if(qr>md) qry(cu<<1|1,md+1,r,max(md+1,ql),qr);
		if(ql<=md) qry(cu<<1,l,md,ql,min(qr,md));
	}
}

int main(){
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
	m=read();
	f(i,1,m){
		scanf("%s",str);
		if(str[0]=='Q'){
			if(hd>tl) printf("Invalid.\n");
			else flag=1,qry(1,0,mx-1,hd,tl),printf("%d\n",ans);
		}else if(str[0]=='R'){
			rev^=1;
		}else if(str[1]=='U'){
			if(rev) upd(++tl,read());
			else upd(--hd,read());
		}else{
			if(hd<=tl){
				if(rev) tl--;
				else hd++;
			}
		}
	}
	return 0;
}

