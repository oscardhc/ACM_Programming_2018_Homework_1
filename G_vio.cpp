
//  G_vio.cpp
//  Created on 2018-10-19 14:09

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

vector<int> v;
char str[15];

int main(){
	freopen("G.in","r",stdin);
	freopen("G_vio.out","w",stdout);

	int m=read();
	m=1000;
	f(i,1,m){
		scanf("%s",str);
		if(str[0]=='Q'){
			if(!v.size()) printf("Invalid.\n");
			else{
				int ret=v[v.size()-1];
				fd(j,v.size()-2,0) ret=!(ret&v[j]);
				printf("%d\n",ret);
			}
		}else if(str[0]=='R'){
			reverse(v.begin(),v.end());
		}else if(str[1]=='U'){
			v.push_back(read());
		}else{
			v.pop_back();
		}
	}
	
	return 0;
}

