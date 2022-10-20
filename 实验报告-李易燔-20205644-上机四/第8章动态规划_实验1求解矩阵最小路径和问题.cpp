//��8�¶�̬�滮 ʵ��1��������С·�������⡣

//��̬�滮�����
/*
״̬ת�Ʒ���
dp[0][0]=a[0][0]
dp[i][0]=dp[i-1][0]+a[i][0]
dp[0][j]=dp[0][j-1]+a[0][j
dp[i][j]=min(dp[i][j-1],dp[i-1][j])+a[i][j] 
*/ 
#include<iostream>
#include<stack>
using namespace std;
int main(){
	int a[10][10];
	int dp[10][10];//��С·��ֵ
	int pre[10][10];//��¼����·�� ��0��ʾ��ֱ��1��ʾˮƽ 
	int n,m,i,j;//�洢�У���
	cin>>n>>m;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			cin>>a[i][j];
	}
	dp[0][0]=a[0][0];
	//�ȴ�����Ϊ0����Ϊ0��Ԫ��
	for(i=1;i<n;i++){
		dp[i][0]=dp[i-1][0]+a[i][0];
		pre[i][0]=0;	
	}

	for(j=1;j<m;j++){
		dp[0][j]=dp[0][j-1]+a[0][j];
		pre[i][0]=1;
	}

//һ���������
//dp[i][j]=min(dp[i][j-1],dp[i-1][j])+a[i][j]  
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			if(dp[i][j-1]<dp[i-1][j]){
				dp[i][j]=dp[i][j-1]+a[i][j];
				pre[i][j]=1;
			}else{
				dp[i][j]=dp[i-1][j]+a[i][j];
				pre[i][j]=0;
			}
		}
	}
	cout<<"���·�����ȣ�"<<dp[n-1][m-1]<<endl;
	cout<<"����·����"<<endl;
	stack<int>res;//����һ��ջ����Ϊ·������ĩ��ǰ�Ƶģ��������ʱҪ��ת�� 
	i=n-1,j=m-1;
	res.push(a[i][j]);
	while(i!=0&&j!=0){
		if(pre[i][j]){
			j--;
			res.push(a[i][j]);
		}else{
			i--;
			res.push(a[i][j]);
		}
	}
	cout<<a[0][0];
	while(!res.empty()){
		cout<<" ->"<<res.top();
		res.pop();
	}
	cout<<endl;
	return 0;
}










