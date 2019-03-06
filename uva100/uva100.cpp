#include<stdio.h>
#include<stdlib.h>
int main()
{
	int input1,input2;
	while(scanf("%d%d",&input1,&input2)!=EOF)
	{
		printf("%d %d",input1,input2);
		if(input1>input2)
		{
		int cd;
		cd=input2;
		input2 = input1;
		input1 = cd;
		}
		int temp;
		int max;
		for(max=0;input1<=input2;input1++)
		{
			int count=1;
			temp = input1;
				while(temp!=1)
				{
					if(temp%2==1)
					{
					temp = 3*temp+1;
					count++;
					}
					else
					{
					temp = temp/2;	
					count++;
					}
				}
			if(count>max)
				max = count;
		}
		printf(" %d\n",max);	
	}
}
	
