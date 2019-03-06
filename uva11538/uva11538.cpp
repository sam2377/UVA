#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
long long int n,m,ans;
int main(){
	while(1){
		long long int temp,temp1;
		ans=0;
		scanf("%lld%lld",&n,&m);
		if(n==0&&m==0) return 0;
		else{
		ans+=(n*(n-1)/2)*m;
		ans+=(m*(m-1)/2)*n;
		temp = min(n,m);
		temp1 =max(n,m);
		ans+=(temp*(temp-1)/2)*(temp1-temp+1)*2;
		for(long long int i=2;i<=temp-1;i++)
		ans+=(i*(i-1))/2*4;
		ans=ans*2;
		printf("%lld\n",ans);
		}
	}
}
