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
	for (int i = 0; i < 3; i++){
		cout<<a[i*3]<<" "<<a[i*3+1]<<" "<<a[i*3+2]<<endl;
	}
	cout<<endl;
}

void solve(int a[],int i){
	if(i==9){//������Ҷ�ӽ��,���һ�����н�
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
			//�ж� + ��֦
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
	cout<<"һ���� "<<sum<<" ���������Ҫ��"<<endl; 
	return 0;
} 
