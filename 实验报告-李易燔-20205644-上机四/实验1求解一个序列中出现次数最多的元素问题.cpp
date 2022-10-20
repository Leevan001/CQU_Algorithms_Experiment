//指定n个正整数，编写一个实验程序找出它们中出现次数最多的数。如果这样的数有多个，请输出其中最小的一个。
//输入描述：输入的第1行只有一个正整数n（1<=n<=1000）,表示数字的个数；输入的第2行有n个整数s1、s2、…、sn（1<=i<=n）。相邻的数用空格分隔。
//输出描述：输出这n个次数中出现次数最多的数。如果这样的数有多个，输出其中最小的一个。
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[10000],n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int result;//出现次数最多的最小数 
	int count=0;//出现最多的次数 
	sort(a,a+n);//先排序
	int temp=a[0];
	int num=1;
	int i=1;
	while(i<n){
		while(i<n&&a[i]==temp){
			num++;
			i++;
		}
		if(num>count){
			count=num;
			result=temp;
		} 
		temp=a[i];
		num=1;
		i++;
	} 
	cout<<result<<endl;
	return 0;
} 
