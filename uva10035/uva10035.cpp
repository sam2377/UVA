#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;
int main(){
	while(1){
		string a,b;
		int A[11]={0},B[11]={0};
		int temp=0,ans=0;
		cin >> a;
		cin >> b;
//		cout << a << endl;
//		cout << b << endl;
		if(a=="0"&&b=="0") return 0;
		for(int j=0,i=a.length()-1;i>=0;j++,i--)
			A[j]=a[i]-'0';
		for(int j=0,i=b.length()-1;i>=0;j++,i--)
			B[j]=b[i]-'0';
/*		for(int i=0;i<11;i++)
			printf("%d",A[i]);
		printf("\n");
		for(int i=0;i<11;i++)
			printf("%d",B[i]);
		printf("\n");
*/
		for(int i=0;i<11;i++){ 
			if(A[i]+B[i]+temp>=10){
		 	ans++;
		 	temp=(A[i]+B[i]+temp)/10;
			}
			else
			temp = 0;
		}
		if(ans==0) printf("No carry operation.\n");
		else {
		if(ans==1) printf("%d carry operation.\n",ans);
		else printf("%d carry operations.\n",ans); 
		} 
	}
		
} 
