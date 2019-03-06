#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define INF 999999
using namespace std;

struct Node{
	int vmin;
	Node *l,*r;
	
	void update(int v){
		vmin = v;
	}
	void pull(){
		vmin = min(l->vmin,r->vmin);
	}
};

Node * build(int,int);
int querymin(Node *now,int,int,int,int);
void modify(Node *now,int,int,int,int);

int s[100010];

int main(){
	int n,q;
	string str;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	Node *root = build(1,n);
	for(int i=1;i<=q;i++){
		cin >> str;
		if(str[0]=='q'){
			int l=0,r=0;
			bool check = true;
			for(int j=6;j<str.length();j++){
				if(str[j]>='0'&&str[j]<='9'){
					if(check){
						l = l*10 + (str[j]-'0');
					}
					else r = r*10 + (str[j]-'0');
				}
				else if(str[j]==',') check = false;
			}
//			printf("l = %d r = %d\n",l,r);
			printf("%d\n",querymin(root,1,n,l,r));
		}
		else{
			int ind = 0,first = 0,pre = 0;
			for(int k=6;k<str.length();k++){
				if(str[k]>='0'&&str[k]<='9'){
					ind = ind*10 + (str[k]-'0');
				}
				else if(str[k]==','){
					if(!pre){
						first = s[ind];
						pre = ind;
						ind = 0;
						continue;
					}
					modify(root,1,n,pre,s[ind]);
					pre = ind;
					ind=0;
				}
				else if(str[k]==')'){
					modify(root,1,n,pre,s[ind]);
					modify(root,1,n,ind,first);
					break;
				}
			}
		}
	}
}	

Node* build(int L,int R){
	Node *now = new Node();
	if(L==R){
		now->update(s[L]);
		return now;
	}
	int mid = (L+R)/2;
	now->l = build(L,mid);
	now->r = build(mid+1,R);
	now->pull();
	return now;
}

int querymin(Node *now,int L,int R,int x,int y){
	if(x>R || y<L) return INF;
	if(x<=L && y>=R) return now->vmin;
	int mid = (L+R)/2;
	return min( querymin(now->l,L,mid,x,y),querymin(now->r,mid+1,R,x,y));
}

void modify(Node *now,int L,int R,int x,int v){
	if(L==R){
		now->update(v);
		s[x] = v;
		return;
	}
	int mid = (L+R)/2;
	if(x<=mid){
		modify(now->l,L,mid,x,v);
	}
	else{
		modify(now->r,mid+1,R,x,v);
	}

	now->pull();
}
