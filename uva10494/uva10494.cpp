#include<cstdio>
#include<cstdlib>
#include<cstring> 
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
int B[50]={0};
vector<int>A,ans;
void process(long long int);
int main(){
	string a;
	char b;
	long long int chu=0;
	while(getline(cin,a)){
		long long int index,cnt=0,no_use=0;
		long long int long1=0,long2=0;
		for(index=0;48<=a[index]&&a[index]<=57;index++)
			A.push_back(a[index]-'0');
		long1=A.size();
		A.insert(A.begin(),0);
		for(;a[index]==' ';index++) ;
		b=a[index];
		for(int i=a.length(),j=0;48<=a[i-1]&&a[i-1]<=57;j++,i--)
			B[j]=a[i-1]-'0';
		for(int i=0;i<50;i++)
			chu+=(long long int)B[i]*(long long int)pow(10,i);
		no_use = chu;
		while(no_use>0){
			no_use=no_use/10;
			long2++;
		}
		if(long2>long1){
			switch(b){
				case '/': printf("0");
							break;
				case '%': for(int i=1;i<A.size();i++)
							printf("%d",A[i]);
							break;
			}
		}
		else{
			process(chu);
			switch(b){
				case '/':	for(int i=0;i<ans.size();i++){
							if(ans[0]==0) continue;
							printf("%d",ans[i]);
							}
							break;
							
				case '%':  	for(int i=0;i<A.size()&&A[i]==0;i++){
								cnt++;	 
							}
							if(cnt==A.size()) printf("0");
							else{
								for(int i=cnt;i<A.size();i++)
								printf("%d",A[i]);
							}
							break;		
			}
		}
		printf("\n"); 
		while(!A.empty())	A.erase(A.begin());
		while(!ans.empty())	ans.erase(ans.begin());
		for(int i =0;i<50;i++)	B[i]=0;
		a = "";
		chu=0;			
	}	
}

void process(long long int chu){
	long long int div=chu,len=0,len1=0;
	while(chu>0){
		chu=chu/10;
		len++;
	}
	len1=len+1;
//	printf("%ld\n",div);
//	printf("%ld\n",len);
	for(int i=0;i<A.size()-len;i++){
		long long int temp=0,ind=0;
		while(ind<len1){
		temp+=(long long int)A[i+ind]*(long long int)pow(10,len1-ind-1);
		ind++;
		}
		ans.push_back(temp/div);
		temp=temp%div;
		for(int j=i+len;j>i-1;j--){
			A[j]=temp%10;
			temp=temp/10;
		}	
	}
	
}

