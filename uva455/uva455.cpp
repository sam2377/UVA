#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int input;
string B;
int main(){
	scanf("%d",&input);
	for(int cases=0;cases<input;cases++){
		int pi[1000];
		int index=0;
		pi[0]=-1;
		cin>>B;
		int cur_pos=-1;
		for(int i=1;i<B.length();i++){
			while(~cur_pos&&B[i]!=B[cur_pos+1])
				cur_pos=pi[cur_pos];
			if(B[i]==B[cur_pos+1]) cur_pos++;
			pi[i]=cur_pos;
		}
		for(int i=B.length()-1;i>=0;i--){
			if(pi[i]==-1) {
				index=i;
				break;
			}
		}
//		for(int i=0;i<B.length();i++)
//			printf("%d ",pi[i]);
//		printf("\n");
		if(cases>0) printf("\n");
		if(B.length()%(B.length()-pi[B.length()-1]-1)!=0)
			printf("%d\n",B.length());
		else
			printf("%d\n",B.length()-pi[B.length()-1]-1);
	}

}
