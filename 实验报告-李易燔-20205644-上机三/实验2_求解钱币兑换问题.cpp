//ʵ��2�����Ǯ�Ҷһ�����
//ĳ�����ҽ���1�֡�2�ֺ�5��Ӳ��,��Ǯn(n��5)�һ���Ӳ���кܶ��ֶҷ���
//��дһ��ʵ���������10��Ǯ�ж����ֶҷ�,���г�ÿ�ֶһ���ʽ��
//������ 
#include<iostream>
using namespace std;
int main(){
	int n,count=0;
	cin>>n;
	cout << "1��" << " " << "2��" << " " << "5��" << endl;
	for(int i=0;i<=n/5;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n;k++){
				if(i*5+j*2+k==n){
					cout << k << "  " << j << "  " << i << endl;
					count= count+ 1;	//ͳ�Ƹ���
				}
			}
		}
	}
	cout<<"һ���У�"<<count<<" �ֶһ�������"<<endl;
	return 0;
}
