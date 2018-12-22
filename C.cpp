
//  C.cpp
//  Created on 2018-10-16 14:13

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int mx=105;
int n,m,a[mx],b[mx];char s[10000];

inline int work(){
	n=read(),m=read();
	mem(a,0),mem(b,0);
	f(i,1,m){
		fgets(s+1,5000,stdin);
		int l=strlen(s+1),x=0,flag=0;
		f(j,1,l){
			if(s[j]=='-'||(s[j]>='0'&&s[j]<='9')){
				if(s[j]=='-') flag=1,j++;
				while(s[j]>='0'&&s[j]<='9') x=x*10+s[j]-'0',j++;
				if(flag) b[i]|=(1<<(x-1));
				else a[i]|=(1<<(x-1));
				x=0,flag=0;
			}
		}
	}
	for(register int i=0;i<(1<<n);i++){
		int flag=1;
		f(j,1,m){
			if(!((i&a[j])||(~i&b[j]))){
				flag=0;
				break;
			}
		}
		if(flag) return 1;
	}
	return 0;
}

int main(){
	//freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	int t=read();while(t--) printf("%s\n",work()?"Bingo!":"Sigh...");
	return 0;
}

