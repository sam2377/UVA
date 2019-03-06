#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
void backtrack(int);
int check_row(int);
int check_col(int);
int check_cell(int);
int input;
vector<int> V,ans,last;
int main(){
	while(scanf("%d",&input)!=EOF){
		for(int i=0;i<input*input*input*input;i++){
			int temp;
			scanf("%d",&temp);
			V.push_back(temp);
		}
//		for(int i=0;i<input*input*input*input;i++){
//			printf("%d ",V[i]);
//			if((i+1)%(input*input)==0) printf("\n");
//		}
		for(int i=0;i<input*input*input*input;i++){
			 if(V[i]==0) last.push_back(i);
		} 
		backtrack(0);
		for(int i=0;i<input*input*input*input;i++){
			printf("%d ",V[i]);
			if((i+1)%(input*input)==0) printf("\n");
		}
	}
} 
void backtrack(int x){
	
	if(x>last[last.size()-1]) 
		return;
		
	for(int i=x;i<input*input*input*input;i++){
		if(V[i]==0){
			for(int j=1;j<=input*input;j++){
				if(check_row(i)&&check_col(i)&&check_cell(i))
				V[i]=j;
				backtrack(i+1);
			}
		}
		else continue;
	}
}
int check_row(int pos){
	int check[10]={0};
	int index=(pos/input)*input;
	for(int i=index;i<index+input*input;i++)
		check[V[i]]++;
	for(int i=1;i<=input*input;i++){
		if(check[i]>1) return 0;
	} 
	return 1;
}

int check_col(int pos){
	int check[10]={0};
	int index=(pos%input);
	for(int i=0;i<input*input;i++)
		check[V[i*input+index]]++;
	for(int i=1;i<=input*input;i++){
		if(check[i]>1) return 0;
	}
	return 1;
}
int check_cell(int pos){
	int check[10]={0}; 
	int index2=(pos%input)/input;
	int index1=pos/(input*input*input);
	int correct_index = index1*input*input*input+index2*input;
		for(int i=0;i<input;i++)
			for(int j=0;j<input;j++)
				check[V[correct_index+j+i*input*input]]++;					
	for(int i=1;i<=input*input;i++){
		if(check[i]>1) return 0;
	}
	return 1;
}
