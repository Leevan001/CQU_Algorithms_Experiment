//ʵ��4��������㷽�̽�����
//��дһ��ʵ�����,���a,b��c ,d ,e,����ab-cd-e=1����,�������б�����ȡֵΪ1��5���Ҿ�����ͬ��
#include<iostream>
using namespace std;
void print(int a[]){
	cout<<a[0]<<"*"<<a[1]<<" - "<<a[2]<<"*"<<a[3]<<" - "<<a[4]<<" = 1"<<endl;
}
void solve(int a[],int i){
	if(i==4){
		if (a[0]*a[1]-a[2]*a[3]-a[4] == 1){
			print(a);
		}
		return;
	}
	else{
		for(int j=i;j<5;j++){
			swap(a[i],a[j]);
			solve(a,i+1);
			swap(a[i],a[j]);
		}			
	}

}
int main(){
	int a[]={1,2,3,4,5};
	solve(a,0);
	return 0;
} 
