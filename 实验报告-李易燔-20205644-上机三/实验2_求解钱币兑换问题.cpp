//实验2．求解钱币兑换问题
//某个国家仅有1分、2分和5分硬币,将钱n(n≥5)兑换成硬币有很多种兑法。
//编写一个实验程序计算出10分钱有多少种兑法,并列出每种兑换方式。
//蛮力法 
#include<iostream>
using namespace std;
int main(){
	int n,count=0;
	cin>>n;
	cout << "1分" << " " << "2分" << " " << "5分" << endl;
	for(int i=0;i<=n/5;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n;k++){
				if(i*5+j*2+k==n){
					cout << k << "  " << j << "  " << i << endl;
					count= count+ 1;	//统计个数
				}
			}
		}
	}
	cout<<"一共有："<<count<<" 种兑换方法。"<<endl;
	return 0;
}
