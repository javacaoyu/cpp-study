# include <string>
# include <iostream>
using namespace std;

void func_321();
int& index(int);	// ��������������

int a[] = {1, 2, 3, 4, 5};	//����һ��ȫ������

void func_321(){
	cout << "befor use, index 2 is: " << a[2] << endl;

	index(2) = 16;	// ���ص������ö��� ���Կ���ֱ�ӱ���ֵ

	cout << "after use, index 2 is: " << a[2] << endl;


}

int& index(int i){
	return a[i];	// ��Ϊ�������������ã� ����ֱ�ӷ��ر�������, �Զ�������ã�ָ�����õ�����Ԫ��i �ĵ�ַ
}