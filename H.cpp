
//  H.cpp
//  Created on 2018-10-19 14:40

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=1e6+233,inf=0x1f1f1f1f;
struct E{int t,nx,id;}e[mx<<1];
int n,m,eee[mx][4],fa[mx],tot,id[mx],idtt,fir[mx],l[mx],ok[mx];
long long ans;
pair< int,pair<int,int> > ee[mx];

void dfs(int cu,int fa){
	id[cu]=l[cu]=++idtt;
	for(int j=fir[cu];j;j=e[j].nx){
		if(!id[e[j].t]){
			dfs(e[j].t,e[j].id);
			l[cu]=min(l[cu],l[e[j].t]);
			if(l[e[j].t]>id[cu]) ok[e[j].id]=1;
		}else if(e[j].id^fa){
			l[cu]=min(l[cu],id[e[j].t]);
		}
	}
}
inline void ade(int a,int b,int i,int &_t,E* _e,int* _f){
	_e[++_t].t=b,_e[_t].nx=_f[a],_e[_t].id=i,_f[a]=_t;
	_e[++_t].t=a,_e[_t].nx=_f[b],_e[_t].id=i,_f[b]=_t;
}
inline int gtf(int x){return fa[x]==x?x:fa[x]=gtf(fa[x]);}

int main(){
	//freopen("H.in","r",stdin);
	//freopen("H.out","w",stdout)
	n=read(),m=read();
	f(i,1,m) f(j,0,3) eee[i][j]=read();
	f(i,1,m) ade(eee[i][0],eee[i][1],i,tot,e,fir);
	dfs(1,0);
	f(i,1,n) fa[i]=i;
	f(i,1,m){
		if(ok[i]) ee[i]=make_pair(eee[i][3],make_pair(eee[i][0],eee[i][1]));
		else ee[i]=make_pair(eee[i][2],make_pair(eee[i][0],eee[i][1]));
	}
	sort(ee+1,ee+1+m);
	f(i,1,m){
		if(gtf(ee[i].second.first)^gtf(ee[i].second.second)){
			fa[gtf(ee[i].second.first)]=gtf(ee[i].second.second);
			ans+=ee[i].first;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

