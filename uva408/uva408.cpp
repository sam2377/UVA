#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int gcd(int a,int b){
	if(a==0) return b;
	return gcd(b%a,a);
}
int a,b;
int main(){
	
	int ans;
	while(scanf("%d%d",&a,&b)!=EOF){
	ans=gcd(a,b);
	printf("%10d%10d",a,b);
	printf("    ");
	if(ans==1)
		printf("Good Choice\n\n");
	else
		printf("Bad Choice\n\n");
	}
	return 0; 
}
