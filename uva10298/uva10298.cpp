#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string A;
int main(){
	while(1){
		int pi[1000000];
		int cur_pos=-1;
		cin>>A;
		if(A[0]=='.') break;
		pi[0]=-1;
		for(int i=1;i<A.length();i++){
			while(~cur_pos&&A[i]!=A[cur_pos+1])
				cur_pos=pi[cur_pos];
			if(A[i]==A[cur_pos+1]) cur_pos++;
				pi[i]=cur_pos;
		}
		if(A.length()%(A.length()-pi[A.length()-1]-1)!=0)
			printf("1\n");
		else
			printf("%d\n",A.length()/(A.length()-pi[A.length()-1]-1));
	}
	return 0;
} 
