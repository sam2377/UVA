#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int cal(string);
int main(){
	string a,b;
	while(getline(cin,a)&&getline(cin,b)){
	int ans1,ans2;
	ans1=cal(a);
	ans2=cal(b);
	if(ans1==0&&ans2==0)
	printf("0.00 %%\n");
	else
	printf("%.2lf %%\n",(double)min(ans1,ans2)/(double)max(ans1,ans2)*100);
	}
	return 0;			
}
int cal(string a){
	int answer=0,temp=0;
	for(int i=0;a[i]!='\0';i++)
		if(a[i]>='A'&&a[i]<='Z') temp+=a[i]-'A'+1;
		else if(a[i]>='a'&&a[i]<='z') temp+=a[i]-'a'+1;
/*	 
	for(int i=0;(a[i]<=90&&a[i]>=65)||(a[i]>=97&&a[i]<=122);i++){
	if(a[i]<=90)
		temp+=a[i]-'A'+1;
	else
		temp+=a[i]-'a'+1;
	}

	while(temp>=10)
	{
		answer=0;
		answer+=(temp%10);
		while(temp>=10){
		answer+=(temp/10);
		temp = temp/10;
		}	
		temp = answer;
	}
*/ 
	while(temp>=10)
	temp=temp/10+temp%10;
	
	return temp;

}

 
