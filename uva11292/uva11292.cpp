#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
int abc(int dragon, int warrior)
{
	int sum=0,index=0;
	if(dragon==0&&warrior==0) return 0;
	int head[dragon],money[warrior],fighter[dragon]={0};
	for(int i=0;i<dragon;i++)
		scanf("%d",&head[i]);
	for(int i=0;i<warrior;i++)
		scanf("%d",&money[i]);
	if(dragon>warrior) 
	{
	return -1;
	}
	else
	{
		qsort(&head[0],dragon,sizeof(int),cmp);
		qsort(&money[0],warrior,sizeof(int),cmp);
/*		
		for(int i=0;i<dragon;i++)
			printf("%d\n",head[i]);
		for(int i=0;i<warrior;i++)
			printf("%d\n",money[i]);
*/		
		for(int i=0;i<dragon;i++)
		{
			if(index==warrior) return -1;
			while(head[i]>money[index])	
			{
 				index++;
				if(index==warrior) 
				{
					return -1;
				}
			}
		 	fighter[i]=money[index];
			index++;
 		}
 		for(int i=0;i<dragon;i++)
 			sum+=fighter[i];
 		return sum;
 	}
}
int main()
{
	int answer[100]={0};
	for(int i=0;;i++)
	{
		int dragon,warrior;
		scanf("%d%d",&dragon,&warrior);
		answer[i] = abc(dragon,warrior);
		if(answer[i]==-1) 
		{
			continue;
		}
		if(answer[i]==0)
		{
			break;
		}
		if(answer[i]!=0&&answer[i]!=-1)
		{
			continue;
		}
	}
	for(int i=0;;i++)
	{
		if(answer[i]==-1) printf("Loowater is doomed!\n");
		if(answer[i]==0) return 0;
		if(answer[i]!=0&&answer[i]!=-1) printf("%d\n",answer[i]); 
	}
} 
