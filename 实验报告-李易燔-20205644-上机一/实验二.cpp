#include<iostream>
using namespace std;
//实验二众数问题
 
//分治算法解决众数求解（数组已经按从小到大排好序，如果不止一个众数则只显示其中一个众数的值） 
void solve(int a[],int n,int &l,int &r){
	int mid=n/2;
	l=mid-1;
	r=mid+1;//记录a[mid]的起始位置和终止位置 
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
	cout<<"众数是："<<a[num]<<" 重数是："<<maxcnt<<endl;
	return 0;
}

