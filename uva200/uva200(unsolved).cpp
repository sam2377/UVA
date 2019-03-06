#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
void backtrack(int);
string a[100];
vector<char> ans;
bool check[26];
int count,longest=0;
int main(){
	for(int i=0;;i++){
		getline(cin,a[i]);
		if(a[i]=="#"){
		count = i;
		break;
		}
	}
	printf("%d\n",count);
	memset(check,false,26);
	for(int i=0;i<count;i++){
		if(a[i].length()>longest)
		longest=a[i].length();
	}
	
	backtrack(0);
	for(int i=0;i<ans.size();i++)
	printf("%c",ans[i]);
	
	printf("\n");
} 
void backtrack(int x){
	if(x>=longest) return;
	for(int i=0;i<count;i++){
		if(x==0||(a[i].length()==a[i+1].length()&&a[i][x]==a[i+1][x])&&x<a[i].size()){
			if(check[a[i][x]-'A']==false){
			ans.push_back(a[i][x]);
			check[a[i][x]-'A']=true;
			}
		}
	}
	backtrack(x+1);
}
