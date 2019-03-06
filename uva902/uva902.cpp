#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
int input;
string word;
map<string,int> M;
int main(){
	while(scanf("%d",&input)!=EOF){
		int max=0;
		cin>>word;
		for(int i=0;i<word.length()-input+1;i++){
			string temp;
			for(int j=0;j<input;j++)
				temp.push_back(word[j+i]);
//			cout<< temp<<endl;
			M[temp]++;
			if(M[temp]>max) max=M[temp];
		}
		for(map<string,int>::iterator iter=M.begin();iter!=M.end();iter++)
			if(iter->second==max) cout<<iter->first<<endl;
	}
}
 
