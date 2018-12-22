
//  I_2.cpp
//  Created on 2018-10-21 15:24

#include <bits/stdc++.h>
#define f(i,st,ed) for(int i=st;i<=ed;i++)
#define fd(i,st,ed) for(int i=st;i>=ed;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
inline int read(){char ch=getchar();int ret=0,f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();return ret*f;}

const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
const int mx=105,inf=0x3f3f3f3f;
int n,m,sx,sy,tx,ty,px,py,a[mx][mx],d[mx][mx][4],ok[mx][mx][4][4],bk[mx][mx],bbk[mx][mx][4];
char str[mx];

queue< pair<int,int> > q;
queue< pair<pair<int,int>,int> > qq;

inline int bfs(int x,int y,int d1,int flag=0){
	if(a[x][y]) return -1;
	int ax=x+dx[d1],ay=y+dy[d1],cnt=0;
	if(flag) ax=px,ay=py;
	if(ax<0||ax>=n||ay<0||ay>=m) return -1;
	if(a[ax][ay]) return -1;
	while(!q.empty()) q.pop();
	mem(bk,0);
	q.push(make_pair(ax,ay));
	bk[ax][ay]=1;
	f(k,0,3){
		int nx=x+dx[k],ny=y+dy[k];
		if(nx<0||nx>=n||ny<0||ny>m) continue;
		if(a[nx][ny]) continue;
		cnt++;
	}
	while(!q.empty()){
		int cx=q.front().first,cy=q.front().second;
		if((cx==x&&abs(cy-y)==1)||(cy==y&&abs(cx-x)==1)) cnt--;
		if(!cnt) return 0;
		q.pop();
		f(k,0,3){
			int nx=cx+dx[k],ny=cy+dy[k];
			if(nx<0||nx>=n||ny<0||ny>=m) continue;
			if(a[nx][ny]) continue;
			if(bk[nx][ny]) continue;
			if(nx==x&&ny==y) continue;
			q.push(make_pair(nx,ny));
			bk[nx][ny]=1;
		}
	}
	return 0;
}

int main(){
	freopen("I.in","r",stdin);
	//freopen("I_2.out","w",stdout);
	n=read(),m=read();
	f(i,0,n-1){
		scanf("%s",str);
		f(j,0,m-1){
			if(str[j]=='S') a[i][j]=1;
			else if(str[j]=='w') a[i][j]=0;
			else if(str[j]=='M') px=i,py=j;
			else if(str[j]=='P') sx=i,sy=j;
			else tx=i,ty=j;
		}
	}
	f(i,0,n-1) f(j,0,m-1) f(k,0,3){
		if(bfs(i,j,k)==0){
			f(l,0,3){
				int cx=i+dx[l],cy=j+dy[l];
				if(cx<0||cx>=n||cy<0||cy>=m) continue;
				if(a[cx][cy]) continue;
				if(bk[cx][cy]) ok[i][j][k][l]=1;
			}
		}
	}
	bfs(sx,sy,0,1);
	mem(d,inf);
	f(k,0,3){
		if(bk[sx+dx[k]][sy+dy[k]]){
			qq.push(make_pair(make_pair(sx,sy),k));
			bbk[sx][sy][k]=1;
			d[sx][sy][k]=0;
		}
	}
	while(!qq.empty()){
		int cx=qq.front().first.first,cy=qq.front().first.second,cd=qq.front().second;
		bbk[cx][cy][cd]=0;
		qq.pop();
		int nx=cx-dx[cd],ny=cy-dy[cd];
		if(nx>=0&&nx<n&&ny>=0&&ny<m){
			if(!a[nx][ny]){
				if(d[nx][ny][cd]>d[cx][cy][cd]+1){
					d[nx][ny][cd]=d[cx][cy][cd]+1;
					if(!bbk[nx][ny][cd]){
						qq.push(make_pair(make_pair(nx,ny),cd));
						bbk[nx][ny][cd]=1;
					}
				}
			}
		}
		f(k,0,3) if(k^cd){
			if(ok[cx][cy][cd][k]){
				if(d[cx][cy][k]>d[cx][cy][cd]){
					d[cx][cy][k]=d[cx][cy][cd];
					if(!bbk[cx][cy][k]){
						qq.push(make_pair(make_pair(cx,cy),k));
						bbk[cx][cy][k]=1;
					}
				}
			}
		}
	}
	int ans=inf;
	f(k,0,3) ans=min(ans,d[tx][ty][k]);
	if(ans^inf) printf("%d\n",ans);
	else printf("NO\n");
	return 0;
}

