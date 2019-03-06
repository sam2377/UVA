#include<stdio.h>
#include<stdlib.h>

int main()
{
	char a[100000],b[100000];
	while(scanf("%s",a)!=EOF&&scanf("%s",b)!=EOF){
		int size1=0,size2=0,index=0,count=0;
		for(int i=0;a[i]!='\0';i++)
		size1++;
		for(int i=0;b[i]!='\0';i++)
		size2++;
			for(int i=0;i<size1;index++){
				if(index>=size2) break; 
				if(a[i]==b[index]){
				i++;
				count++;	
				}
			}
		if(count==size1) printf("Yes\n");
		else printf("No\n");	
		for(int i=0;i<size1;i++)
		a[i]='\0';
		for(int i=0;i<size2;i++)
		b[i]='\0';
	}
	return 0;
 } 
