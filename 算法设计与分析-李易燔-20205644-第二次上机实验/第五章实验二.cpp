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
	for (int i = 0; i < 3; i++)
		cout << a[i] << ' ';
	cout << endl;
	cout << a[5] << ' ' << a[4] << ' ' << a[3] << endl;
	cout << a[6] << ' ' << a[7] << ' ' << a[8] << endl << endl << endl;
}

void solve(int i){
	if(i==10){
		for(int i=0;i<num-1;i++){
			if (!prime(a[i], a[i + 1]))
				return;
		}
		if (!prime(a[5], a[0]) || !prime(a[4], a[1]) || !prime(a[8], a[3]) || !prime(a[4], a[7]))
			return;
		sum++;
		print(a);
	}
	else{
		for(int j=0;j<10;j++){
			if(v[j]==0){
				v[j]=1;
				a[i]=j+1;
				solve(i+1);
				v[j]=0;
			}
		}
	}
}

int main(){
	solve(0);
	cout<<"一共有 "<<sum<<" 个方格符合要求"<<endl; 
	return 0;
} 
