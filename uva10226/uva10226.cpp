#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<map>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
struct Trie{
	Trie* A[2000];
	bool isword;
	int cnt;	
	Trie(){
		memset(A,0,sizeof(A));
		isword=false;
		cnt=0;
	}
};
Trie *root,*p;
vector<char> ans;
int ch(char);
void insert(string);
void print(Trie *,int);
int main(){
	int input;
	string no_use1,no_use2;
	scanf("%d",&input);
	string str;
	getline(cin,no_use1);
	getline(cin,no_use2);
	for(int i=0,num=0,a=1;i<input;i++,a=1,num=0){
		if(i>0) printf("\n");
		Trie start;
		root = &start;
		p = root;
		while(a){
			getline(cin,str);
			if(str!="\0") {
				num++;
				insert(str);			
		 	}
			else{
				a--;
			}
		}
		print(p,num);
		while(!ans.empty()) ans.erase(ans.begin());
//		for(int i=0;i<V.size();i++)
//			printf("%c ",V[i]);
	}
}

void insert(string s){
	Trie *ptr = root;
	for(int i=0;i<s.length();i++){
		if(ptr->A[ch(s[i])]==NULL)
			ptr->A[ch(s[i])]=new Trie();
		ptr=ptr->A[ch(s[i])];
	}
	ptr->cnt++;
	ptr->isword=true;
}
int ch(char a){
	return a-'\0';
}
void print(Trie *p,int num){
	if(p->cnt!=0&&p->isword==true) {
		for(int i=0;i<ans.size();i++)
			printf("%c",ans[i]);
		printf(" %.4f\n",(float)p->cnt/num*100);
		p->isword==false;
		return;
	}
	for(int i=0;i<2000;i++){
		if(p->A[i]!=NULL){
			ans.push_back('\0'+i);
			Trie *s;
			s=p->A[i];
			print(s,num);
			ans.pop_back();
		}
	}
}
