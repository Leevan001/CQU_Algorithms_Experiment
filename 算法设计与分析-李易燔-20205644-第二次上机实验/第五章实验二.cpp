//���������Ϸ����

//��3*3������ķ�������������1-10��ĳ9�����֣�ÿ��������һ��������
//ʹ�����������������ڵ���������֮��Ϊ��������дһ������
//��������������Ҫ������ֵ����

#include<iostream>
using namespace std;
//���û��ݷ�+��֦
//�����ж�

/*
0 1 2
5 4 3
6 7 8
*/

int a[10];
int v[10]={0};
int sum=0;//��¼����Ҫ��Ľ�ĸ���
int num=9;
bool prime(int a,int b){
	int c=a+b;
	if(c==1||c==2)return true;
	for(int i=2;i<c/2;i++){
		if(c%i==0)return false;
	}
	return true;
}

//�������Ҫ��ľ��� 
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
	cout<<"һ���� "<<sum<<" ���������Ҫ��"<<endl; 
	return 0;
} 
