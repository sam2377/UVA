#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;
void DFS(int);
bool compare(int,int);
int box[30][10]={0};
vector<int> V,for_index,sol[10000000],ans,num,ans_one_dim;
int input1,input2,cnt=0,index=0,find_sol_index=0;
int main(){
	while(scanf("%d%d",&input1,&input2)!=EOF){
		int sum=0,temp_min=0,max_sol_size=0,index=0,find_sol_index=0,search_index[30]={0},start=0;
		if(input2>1){
			for(int i=0;i<input1;i++){
				for(int j=0;j<input2;j++){
					int temp;
					scanf("%d",&temp);
					V.push_back(temp);	
				}
				sort(V.begin(),V.end());
				for(int k=0;k<input2;k++)
					box[i][k]=V[k];
				while(!V.empty()) V.erase(V.begin());
			}
//			cout << endl;
//			for(int i=0;i<input1;i++){
//				for(int j=0;j<input2;j++)
//					printf("%d ",box[i][j]);
//				printf("\n");
//			}
			for(int i=0,total=0;i<input1;i++,total=0){
				for(int j=0;j<input2;j++)
					total+=box[i][j];
				for_index.push_back(total);
			}
			temp_min=for_index[0];
//			for(int i=0;i<input1;i++){
//				if(for_index[i]<temp_min){
//					temp_min=for_index[i];
//					index = i;
//				}
//			}
			for(int i=0;i<input1-1;i++){
				for(int j=i+1;j<input1;j++){
					if(compare(i,j)) 
						search_index[j]++;
				}
			}
			for(int i=0;i<input1;i++){
				if(search_index[i]==0){					
					ans.push_back(i);
					DFS(i);
					ans.pop_back();
				}
			}
//			for(int i=0;i<10;i++){
//				for(int j=0;j<sol[i].size();j++)
//					printf("%d ",sol[i][j]);
//				printf("\n");
//			}
			for(int i=0;i<10000000;i++){
				if(sol[i].size()>max_sol_size)
				max_sol_size=sol[i].size();
			}
			printf("%d\n",max_sol_size);
			for(int i=0;i<10000000;i++){
				if(sol[i].size()==max_sol_size){
					for(int j=0;j<max_sol_size;j++) 
						printf("%d ",(sol[i][j]+1));
					printf("\n");
					break;
				}
			}
			while(!V.empty()) V.erase(V.begin());
			while(!for_index.empty()) for_index.erase(for_index.begin());
			while(!ans.empty()) ans.erase(ans.begin());
			for(int i=0;i<10000000;i++)
				while(!sol[i].empty()) sol[i].erase(sol[i].begin());
		}
		else{
			for(int i=0;i<input1;i++){
				int temp;
				scanf("%d",&temp);
				num.push_back(temp);
				ans_one_dim.push_back(temp);
			}
			sort(num.begin(),num.end());	
			int cnt=0;
			for(int i=0;i<input1;i++){
				if(i==0||num[i]!=num[i-1]){
					cnt++;
					for(int j=0;j<input1;j++){
						if(num[i]==ans_one_dim[j]){
							ans.push_back(j+1);
							break;
						}
					}	
				}
			}
			printf("%d\n",cnt);
			for(int i=0;i<ans.size();i++)
				printf("%d ",ans[i]);
			printf("\n");
			while(!num.empty()) num.erase(num.begin());
			while(!ans_one_dim.empty()) ans_one_dim.erase(ans_one_dim.begin());
			while(!ans.empty()) ans.erase(ans.begin());
		}
	}	
}
bool compare(int a,int b){
	for(int x=0;x<input2;x++){
		if(box[a][x]>=box[b][x]) 
		return false;
	}
	return true;
}

void DFS(int a){
	for(int i=0;i<input1;i++){
		if(compare(a,i)==true){
			ans.push_back(i);
				for(int j=0;j<ans.size();j++)
					sol[cnt].push_back(ans[j]);
				cnt++;	
			DFS(i);
			ans.pop_back();
		}
	}
}
