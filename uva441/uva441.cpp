#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
int k,tmp[6]={0},no_use=0;
vector<int> V;
void backtrack(int,int);
int main(){
 	while(1){
    scanf("%d",&k);
    if(k==0) break;
    for(int i=0;i<k;i++){
      int temp;
      scanf("%d",&temp);
      V.push_back(temp);
    }
    if(no_use!=0)printf("\n");
	backtrack(0,0);
//  for(int i=0;i<V.size();i++)
//  printf("%d ",V[i]);
  	while(!V.empty()) V.erase(V.begin());
	no_use++;
	}
  return 0; 
}
void backtrack(int a,int index){
    if(a==6){
      for(int i=0;i<5;i++)
         printf("%d ",tmp[i]);
     	printf("%d\n",tmp[5]);
    	return;
	}
    for(int i=index;i<=(k-6+a);i++){       
      tmp[a]=V[i];
	  backtrack(a+1,i+1);      
    }
}
