//ʵ��1�����4�ʺ�����
//��дһ��ʵ�����,���ö���ʽ�����ȶ���ʽ��֦�޽編���4�ʺ������һ����,
//���������ַ�ʽ��������,�Ƚϴ����Ķ��н�������

//���ȶ���ʽ��֧�޽編 ��rowԽ��Խ�ã� 
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
bool judge(vector<int>cols,int i,int j){//�жϣ�i��j���Ƿ����Ҫ��
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
		if(e.row==3){//����Ҷ�ӽڵ㣬���ҵ�һ����
			cout<<"�Ѿ�����"<<count-1<<"���ڵ㡣"<<endl; 
			cout<<"�Ļʺ������һ�����ǣ�"<<endl;
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
