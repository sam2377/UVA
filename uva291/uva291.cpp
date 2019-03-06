#include<cstdio>
#include<cstdlib>
#include<iostream>
int ans[9]={0};
bool path[6][6];
void backtrack(int,int);
int main(){
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			path[i][j]=false;
	path[1][2]=true;path[1][3]=true;path[1][5]=true;
	path[2][1]=true;path[2][3]=true;path[2][5]=true;
	path[3][1]=true;path[3][2]=true;path[3][4]=true;path[3][5]=true;
	path[4][3]=true;path[4][5]=true;
	path[5][1]=true;path[5][2]=true;path[5][3]=true;path[5][4]=true;
	ans[0]=1;
	backtrack(0,1);
}
void backtrack(int x,int pos){
	if(x==8){
		for(int i=0;i<9;i++)
		printf("%d",ans[i]);
	printf("\n");
		return;
	} 
	for(int i=1;i<6;i++){
		if(path[pos][i]){
			path[pos][i]=false;
			path[i][pos]=false;
			ans[x+1]=i;
			backtrack(x+1,i);
			path[pos][i]=true;
			path[i][pos]=true;
		}
	}
	
	
	
}
