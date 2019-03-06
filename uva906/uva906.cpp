#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
long long a,b,c,d;
double eps;	
int main(){

	while(scanf("%lld %lld %lf",&a,&b,&eps)!=EOF){
		long double temp = (long double)a/b,temp2;
		for(d=1;;d++){
			c = (long long int)(temp*d); 
			while(a*d>=b*c)
			c++;
			temp2 = (long double)c/d;
			if(temp2-temp<=eps){
				printf("%lld %lld\n",c,d);
				break;
			}
		}
	}
}
