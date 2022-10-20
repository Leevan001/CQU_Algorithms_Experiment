//第8章动态规划 实验1求解矩阵最小路径和问题。

//动态规划法求解
/*
状态转移方程
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
	int dp[10][10];//最小路径值
	int pre[10][10];//记录具体路径 ，0表示垂直，1表示水平 
	int n,m,i,j;//存储行，列
	cin>>n>>m;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			cin>>a[i][j];
	}
	dp[0][0]=a[0][0];
	//先处理行为0，列为0的元素
	for(i=1;i<n;i++){
		dp[i][0]=dp[i-1][0]+a[i][0];
		pre[i][0]=0;	
	}

	for(j=1;j<m;j++){
		dp[0][j]=dp[0][j-1]+a[0][j];
		pre[i][0]=1;
	}

//一般情况处理
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
	cout<<"最短路径长度："<<dp[n-1][m-1]<<endl;
	cout<<"具体路径："<<endl;
	stack<int>res;//设置一个栈，因为路径是由末向前推的，所以输出时要反转。 
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










