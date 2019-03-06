#include<cstdlib>
#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
int A[1000010] = {0};
int buf[1000010] = {0};
void Merge(int, int);
void Combine(int, int, int);
long long int ans;
int n;
int main(){
	while(scanf("%d",&n)!=EOF){
    	for(int i=0;i<n;i++){
	    	scanf("%d",&A[i]);
	    }
	    ans=0;
	    Merge(0,n-1);
	    printf("%lld\n",ans);
	}

	return 0;
}
void Combine(int l, int mid, int r){
    int i=l,j=mid+1,cnt=0;
	while(i<=mid && j<=r) {
        if(A[i] <= A[j]){
            buf[cnt++] = A[i++];
        }
		else{
		    buf[cnt++] = A[j++];
            ans += mid-i+1;
		}
	}

    while(i<=mid)  buf[cnt++] = A[i++];
    while(j<=r)    buf[cnt++] = A[j++];

    for(int i=l;i<=r;i++){
	    A[i] = buf[i-l];
    }

}

void Merge(int l, int r){

	if(l==r) return;

	int mid = (l+r)/2;
    Merge(l,mid);
	Merge(mid+1,r);
	Combine(l,mid,r);
}
