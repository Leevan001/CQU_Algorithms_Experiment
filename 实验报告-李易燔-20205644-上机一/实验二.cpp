#include<iostream>
using namespace std;
//ʵ�����������
 
//�����㷨���������⣨�����Ѿ�����С�����ź��������ֹһ��������ֻ��ʾ����һ��������ֵ�� 
void solve(int a[],int n,int &l,int &r){
	int mid=n/2;
	l=mid-1;
	r=mid+1;//��¼a[mid]����ʼλ�ú���ֹλ�� 
	while(l>=0&&a[mid]==a[l]){
		l--;
	}
	l++;
	while(r<n&&a[r]==a[mid]){
		r++;
	}
	r--;
}
void Solution(int a[],int n,int &mid,int &maxcnt){
	if(n==1){
		mid=0;
		maxcnt=1;
	}
	int l=0,r=0;
	solve(a,n,l,r);
	int num=n/2;
	int cnt=r-l+1;
	if(cnt>maxcnt){
		maxcnt=cnt;
		mid=a[num];
	}
	if(l>maxcnt){
		Solution(a,l--,mid,maxcnt);
	}
	if(n-r>maxcnt){
		Solution(a+r,n-r,mid,maxcnt);
	}
}
int main(){
	int a[]={1,2,2,3,5};
	int maxcnt=0,num=0;
	Solution(a,5,num,maxcnt);
	cout<<"�����ǣ�"<<a[num]<<" �����ǣ�"<<maxcnt<<endl;
	return 0;
}

