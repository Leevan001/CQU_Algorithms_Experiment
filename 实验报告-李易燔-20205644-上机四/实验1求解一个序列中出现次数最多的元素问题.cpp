//ָ��n������������дһ��ʵ������ҳ������г��ִ�����������������������ж���������������С��һ����
//��������������ĵ�1��ֻ��һ��������n��1<=n<=1000��,��ʾ���ֵĸ���������ĵ�2����n������s1��s2������sn��1<=i<=n�������ڵ����ÿո�ָ���
//��������������n�������г��ִ�����������������������ж�������������С��һ����
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[10000],n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int result;//���ִ���������С�� 
	int count=0;//�������Ĵ��� 
	sort(a,a+n);//������
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
