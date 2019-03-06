#include<map>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int main()
{
	map<string,int> M;
	map<string,int>::iterator iter;
	int input;
	scanf("%d%*c",&input);
		for(int i=0;i<input;i++){
			char A[75];
			gets(A);
			char token[] = " ",*ptr; 
			ptr=strtok(A,token);
			M[ptr]++;
		}	
	for(map<string,int>::iterator iter=M.begin();iter!=M.end();iter++)
		cout << iter->first << " " <<iter->second<<endl;
		
}	
