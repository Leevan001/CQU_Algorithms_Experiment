//ʵ����
//���һ���������黮��Ϊ��������������⣺�ֳ������������������٣���������
//���ÿ�������˼�� 
#include<iostream>
using namespace std;
int Partition(int a[],int l,int r){
	int i=l,j=r;
	int temp=a[l];//�������Ԫ��Ϊ��׼��
	while(i!=j){
		while(j>i&&a[j]>=temp)j--;
		a[i]=a[j];
		while(j>i&&a[i]<=temp)i++;
		a[j]=a[i];	
	}
	a[i]=temp;
	return i;
}
int solve(int a[],int n){
	int l=0,r=n-1;
	int i=Partition(a,l,r);
	while(1){
		if(i==n/2)break;
		else if(i>n/2){
			i=Partition(a,0,i-1);
		}
		else{
			i=Partition(a,i+1,r);
		}
	}
	int s1=0,s2=0;
	for(int i=0;i<n/2;i++)//����벿�ֵĺ�
		s1+=a[i];
	for(int j=n/2;j<n;j++)//���Ұ벿�ֵĺ�
		s2+=a[j];
	return s2-s1;
}
int main(){
	int a[]={5,2,1,4,3};
	cout<<"���Ϊ��"<<solve(a,5);
	return 0;
}
