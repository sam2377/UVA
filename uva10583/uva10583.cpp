#include<map>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
vector<int> A;
int num=1;
int Find(int x)
{
	if(x==A[x]) return x;
	return A[x] = Find(A[x]);
}
void Union(int x,int y)
{
	int X = Find(x);
	int Y = Find(y);
	A[Y] = X;
}
int main()
{
	while(1){
        A.clear();
	    int input1,input2,count=1;
	    scanf("%d%d",&input1,&input2);
	    if(input1==0&&input2==0)  return 0;
		    for(int i=0;i<input1;i++){
			    A.push_back(1);
			    A[i] = i;
		    }
		    for(int i=0;i<input2;i++){
			    int a,b;
			    scanf("%d%d",&a,&b);
			    Union(a-1,b-1);
	    	}
		    for(int i=0;i<A.size();i++){
			    Find(i);
		    }

            sort(A.begin(),A.end());
            int tmp = A[0];
            for(int i=1;i<A.size();i++){
                if(A[i]!=tmp){
                    count++;
                    tmp = A[i];
                }
            }
	    printf("Case %d: %d\n",num,count);
	    num++;
	}
}
