#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
#define MAX 10000000
bool A[MAX];
long long int input;
void eratosthenes()
{
	memset(A,1,sizeof(A));
	A[0]=A[1]=false;
	for(long long int i=2;i<=sqrt(MAX);i++){
		if(A[i])
			for(long long int j=i*i;j<MAX;j+=i)
				A[j]=false;
	}
}
int main(){
	eratosthenes();
	while(1){
	cin >> input;
	if(input<0) return 0;
		for(long long int i=2;;i++){
			if(input==1) break;
			if(A[i]){	
				if(input%i==0){
				printf("    %lld\n",i);
				input=input/i;
				i--;
				continue;
				}	
			}
			if(i>1000000){
			printf("    %lld\n",input);
			break;
			}
		}
	printf("\n");
	}
}
