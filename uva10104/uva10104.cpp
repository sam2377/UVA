#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int a,b,X,Y;
int exGCD(int a,int b,int &X,int &Y){
	if(b==0){
		X=1;
		Y=0;
		return a;
	}
	else{
		int gcd =exGCD(b,a%b,X,Y);
		int tmp=X;
		X=Y;
		Y=tmp-(a/b)*Y;
		return gcd; 	
	}
}
int main(){
	while(scanf("%d%d",&a,&b)!=EOF){
		printf("%d %d %d\n",X,Y,exGCD(a,b,X,Y));
	}	
}
