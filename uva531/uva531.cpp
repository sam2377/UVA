#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
vector<string> V1,V2,ans;
int LCS[101][101]={0};
int pre[101][101]={0};
int cases=0;
int main(){
	string temp;
	while((cin>>temp)){
			int index1,index2;
			for(int i=0;i<101;i++){
				for(int j=0;j<101;j++){
					LCS[i][j]=0;
					pre[i][j]=0;
				}
			}
			if(V1.size()>0){
				if(V1[V1.size()-1]=="#")
					V2.push_back(temp);
				else
			 		V1.push_back(temp);			
			}
			else
				V1.push_back(temp);
			if(V2.size()>0){
				if(V2[V2.size()-1]=="#"){
					V1.pop_back();
					V2.pop_back(); 
						for(int i=0;i<V1.size();i++){
							for(int j=0;j<V2.size();j++){
								if(V1[i]==V2[j]){
									LCS[i+1][j+1]=LCS[i][j]+1;
									pre[i+1][j+1]=3;
								}
								else{
									LCS[i+1][j+1]=max(LCS[i][j+1],LCS[i+1][j]);
									if(LCS[i+1][j+1]==LCS[i][j+1]) {
										pre[i+1][j+1]=1; //1 = up
										continue;
									}
									if(LCS[i+1][j+1]==LCS[i+1][j]) 
										pre[i+1][j+1]=2; //2 = left
								}
							}
						}
//						for(int i=0;i<50;i++){
//							for(int j=0;j<50;j++)
//								printf("%d ",pre[i][j]);
//							printf("\n");
//						}
						index1=V1.size();
						index2=V2.size();
						while(pre[index1][index2]!=0){
							switch(pre[index1][index2]){
								case 1:{
								index1--; 
								break;
								}
								case 2:{
								index2--; 
								break;
								} 
								case 3:{ 
								ans.push_back(V1[index1-1]);
								index1--;
								index2--;
								break; 
								} 
							}
						}
						for(int i=ans.size()-1;i>=0;i--){
							cout<< ans[i];
							if(i!=0) cout<<" ";
						}
						cout << endl;
					while(!V1.empty()) V1.erase(V1.begin());
					while(!V2.empty()) V2.erase(V2.begin());
					while(!ans.empty()) ans.erase(ans.begin());			
				}
			}
	}
}

