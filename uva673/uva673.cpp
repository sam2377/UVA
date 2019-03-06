#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
int main()
{
	int input;
	char data;
	scanf("%d%*c",&input);
	for(int i=0;i<input;i++){
		stack<char> stk;
		while(scanf("%c",&data) && data!='\n'){
			if(data==')'){
				if(stk.empty()==true) {
				stk.push(data);
				continue;
				}
				if(stk.top()=='('){
				stk.pop();
				} 
				continue;
			}	
			if(data==']'){
				if(stk.empty()==true) {
				stk.push(data);
				continue;
				}
				if(stk.top()=='['){
				stk.pop();
				}
				continue;
			}
			stk.push(data);
		}
		if(stk.empty()==false)
  		printf("No\n");
  		else
  		printf("Yes\n");
	}
}
