//实验1．求解4皇后问题
//编写一个实验程序,采用队列式和优先队列式分枝限界法求解4皇后问题的一个解,
//分析这两种方式的求解过程,比较创建的队列结点个数。

//优先队列式分支限界法 （row越大越好） 
#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
struct node
{
	int no;
	int row;
	vector<int>cols;
	bool operator<(const node& s)const     
	{
		return row < s.row;
	}
};
bool judge(vector<int>cols,int i,int j){//判断（i，j）是否符合要求
	for(int k=0;k<i;k++){
		if(cols[k]==j||abs(k-i)==abs(cols[k]-j))return false;
	} 
	return true;	
}
void queen(){
	int i,j,count=1;
	node e,e1;
	priority_queue<node>q;
	e.no=count++;
	e.row=-1;
	q.push(e);
	while(!q.empty()){
		e=q.top();
		q.pop();
		if(e.row==3){//到达叶子节点，即找到一个解
			cout<<"已经建立"<<count-1<<"个节点。"<<endl; 
			cout<<"四皇后问题的一个解是："<<endl;
			for(i=0;i<4;i++)
				cout<<"["<<i+1<<" , "<<e.cols[i]+1<<" ]"<<endl;		
			return ;	
			}
		else{
			for(j=0;j<4;j++){
				i=e.row+1;
				if(judge(e.cols,i,j)){
					e1.no=count++;
					e1.row=i;
					e1.cols=e.cols;
					e1.cols.push_back(j);
					q.push(e1);
				}
			}
		}
	}
}
int main(){
	queen();
	return 0;
}
