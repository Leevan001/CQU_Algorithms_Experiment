//求解填字游戏问题

//在3*3个方格的方阵中填入数字1-10的某9个数字，每个方格填一个整数，
//使所有相邻两个方格内的两个整数之和为素数。编写一个程序，
//求出所有满足这个要求的数字的填法。

#include<iostream>
using namespace std;
//采用回溯法+剪枝
//素数判断

/*
0 1 2
5 4 3
6 7 8
*/

int a[10];
int v[10]={0};
int sum=0;//记录符合要求的解的个数
int num=9;
bool prime(int a,int b){
	int c=a+b;
	if(c==1||c==2)return true;
	for(int i=2;i<c/2;i++){
		if(c%i==0)return false;
	}
	return true;
}

//输出符合要求的矩阵 
void print(int a[]){
	for (int i = 0; i < 3; i++){
		cout<<a[i*3]<<" "<<a[i*3+1]<<" "<<a[i*3+2]<<endl;
	}
	cout<<endl;
}

void solve(int a[],int i){
	if(i==9){//搜索到叶子结点,输出一个可行解
//		if(prime(a[8],a[7])&&prime(a[8],a[5])){
//			print(a);
//			sum++;	
//		}
		print(a);
		sum++;		
	}
	else{
		for(int j=i;j<10;j++){
			swap(a[i],a[j]);
			//判断 + 剪枝
			if(i>0){
				if(i!=3&&i!=6){
					if(prime(a[i],a[i-1])){
						if(i>2){
							if(prime(a[i],a[i-3]))
								solve(a,i+1);
						}
						else{
							solve(a,i+1);
						}
					}
				}
				else{
					if(prime(a[i],a[i-3]))solve(a,i+1);
				}
			}
			else{
				solve(a,i+1);
			}
			//solve(a,i+1);
			swap(a[i],a[j]);
		}
	}
}

int main(){
	int a[]={1,2,3,4,5,6,7,8,9,10};
	solve(a,0);
	cout<<"一共有 "<<sum<<" 个方格符合要求"<<endl; 
	return 0;
} 
