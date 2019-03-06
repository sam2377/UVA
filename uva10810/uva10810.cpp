#include<stdio.h>
#include<stdlib.h>
void Mergesort(int,int);
void Combine(int,int,int);
int A[500001]={0},buf[500001];
long long int output;
int main()
{
	int n;
	while(1){
		output=0;
		scanf("%d",&n);
		if(n==0) return 0;
		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);
		Mergesort(0,n-1);
	printf("%lld\n",output);
	for(int i=0;i<500001;i++)
	A[i]=0;
	}
	return 0;	
 }
 
void Combine(int l,int mid,int r){
	int i,j,count;
	i=l,j=mid+1,count=0;
	
	while(i<=mid&&j<=r) {
		if(A[i]<A[j]) 
		buf[count++]=A[i++];
		else {
		buf[count++]=A[j++];
		output+=(mid-i+1);   //右邊要搬去左邊花多少次 mid-i	//又或者左邊還剩幾個擋著 
		}
	}
	while(i<=mid) buf[count++]=A[i++];
	while(j<=r) buf[count++]=A[j++];
	
	for(int i=l;i<=r;i++)
		A[i]=buf[i-l];
} 
void Mergesort(int l,int r)
{
	if(l==r) return;
	int mid = (l+r)/2;
	Mergesort(l,mid);
	Mergesort(mid+1,r);
	Combine(l,mid,r);
 } 
