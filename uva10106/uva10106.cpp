#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
void product(vector<int> A,vector<int> B);
string A,B,C;
vector<int> a,b;
int ans[1000]={0};
int main(){
	while(getline(cin,A)){
 		getline(cin,B);
	int cnt=0;
	for(int j=0,i=A.length()-1;i>=0;i--,j++){
		a.push_back(0);
		switch(A[i]){
		case '0': a[j]=0;break;
		case '1': a[j]=1;break;
		case '2': a[j]=2;break;
		case '3': a[j]=3;break;
		case '4': a[j]=4;break;
		case '5': a[j]=5;break;
		case '6': a[j]=6;break;
		case '7': a[j]=7;break;
		case '8': a[j]=8;break;
		case '9': a[j]=9;break;
		}	
	}
//	for(int i=0;i<=A.length()-1;i++)
//	printf("%d",a[i]);
	for(int j=0,i=B.length()-1;i>=0;i--,j++){
        	b.push_back(0);
        	switch(B[i]){
        	case '0': b[j]=0;break;
        	case '1': b[j]=1;break;
        	case '2': b[j]=2;break;
        	case '3': b[j]=3;break;
        	case '4': b[j]=4;break;
        	case '5': b[j]=5;break;
        	case '6': b[j]=6;break;
        	case '7': b[j]=7;break;
        	case '8': b[j]=8;break;
        	case '9': b[j]=9;break;
        	}
        }
//        for(int i=0;i<=B.length()-1;i++)
//       printf("%d",b[i]); 
	product(a,b);             
	for(int i=999;i>=0;i--){
		if(ans[i]==0) cnt++;
		else break;
	}
	
	for(int i=999-cnt;i>=0;i--)
		printf("%d",ans[i]);	
	
	for(int i=0;i<1000;i++)
		ans[i]=0;
 	
	while(!a.empty())
		a.erase(a.begin());
	
	while(!b.empty())
		b.erase(b.begin());
	
	
	if(cnt==1000) printf("0\n");
	else printf("\n");
	}
	 
	return 0;
}

void product(vector <int>A,vector <int>B){
	int temp=0;
	for(int i=0;i<A.size();i++){
		for(int j=0;j<B.size();j++){
			ans[i+j]+=(A[i]*B[j]);
			ans[i+j+1]+=ans[i+j]/10;
			ans[i+j]=ans[i+j]%10;
		}	
	}

}
