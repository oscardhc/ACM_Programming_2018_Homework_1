
//  I.cpp
//  Created on 2018-10-21 11:15

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mmx=100,inf=30000;
const int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int n,m,sx,sy,tx,ty,mx,my,a[mmx][mmx];char str[mmx];
struct S{
	int x,y,mx,my;
	friend bool operator  < (const S &s1,const S &s2);
	friend bool operator == (const S &s1,const S &s2);
};

priority_queue<S> q;
map<S,short> f;
inline bool operator  < (const S &s1,const S &s2){return f[s1]>f[s2];}
inline bool operator == (const S &s1,const S &s2){return s1.x==s2.x&&s1.y==s2.y&&s1.mx==s2.mx&&s1.my==s2.my;}

inline int chk(S s){
	if(s.x<0||s.x>=n||s.y<0||s.y>=m) return 0;
	if(s.mx<0||s.mx>=n||s.my<0||s.my>=m) return 0;
	if(s.x==s.mx&&s.y==s.my) return 0;
	if(a[s.x][s.y]) return 0;
	if(a[s.mx][s.my]) return 0;
	return 1;
}

int main(){
	freopen("I.in","r",stdin);
	//freopen("I.out","w",stdout);
	n=read(),m=read();
	f(i,0,n-1){
		scanf("%s",str);
		f(j,0,m-1){
			if(str[j]=='S') a[i][j]=1;
			else if(str[j]=='w') a[i][j]=0;
			else if(str[j]=='M') mx=i,my=j;
			else if(str[j]=='P') sx=i,sy=j;
			else tx=i,ty=j;
		}
	}
	S st=S{sx,sy,mx,my};
	f.insert({st,1});
	printf("%d\n",f.size());
	printf("%d %d %d %d\n",st.x,st.y,st.mx,st.my);
	f.find(st);
	q.push(st);
	while(!q.empty()){
		S cu=q.top();q.pop();
		printf("%d %d %d %d\n",cu.x,cu.y,cu.mx,cu.my);
		f.find(cu);
		return 0;
		short cud=f.find(cu)->second;
		printf("%d %d %d %d  %d\n",cu.x,cu.y,cu.mx,cu.my,cud);
		if(cu.x==tx&&cu.y==ty) return printf("%d\n",cud),0;
		f(k,0,3){
			cu.mx+=dx[k],cu.my+=dy[k];
			if(chk(cu)&&f.find(cu)==f.end()){
				f.insert({cu,cud});
				q.push(cu);
			}
			cu.mx-=dx[k],cu.my-=dy[k];
		}
		/*
		if(cu.y==cu.my&&cu.x==cu.mx+1){
			cu.x++,cu.mx++;
			if(chk(cu)&&!f[cu]){
				f[cu]=cud+1;
				q.push(cu);
			}
			cu.x--,cu.mx--;
		}
		if(cu.y==cu.my&&cu.x==cu.mx-1){
			cu.x--,cu.mx--;
			if(chk(cu)&&!f[cu]){
				f[cu]=cud+1;
				q.push(cu);
			}
			cu.x++,cu.mx++;
		}
		if(cu.x==cu.mx&&cu.y==cu.my+1){
			cu.y++,cu.my++;
			if(chk(cu)&&!f[cu]){
				f[cu]=cud+1;
				q.push(cu);
			}
			cu.y--,cu.my--;
		}
		if(cu.x==cu.mx&&cu.y==cu.my-1){
			cu.y--,cu.my--;
			if(chk(cu)&&!f[cu]){
				f[cu]=cud+1;
				q.push(cu);
			}
			cu.y++,cu.my++;
		}
		*/
	}
	printf("NO\n");
	return 0;
}
