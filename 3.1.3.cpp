# include <string>
# include <iostream>
using namespace std;

typedef int array[10];	// �Զ���array��������,���������������
void func_313(void);
void swap(array &s1);

void func_313(){
	array a = {1, 9};	// ����a
	array &b = a;		// ������a�ļ������
	cout << "befor b[0]: " << b[0] << ", b[1]: " << b[1] << endl;

	swap(b);

	cout << "after b[0]: " << b[0] << ", b[1]: " << b[1] << endl;

}

void swap(array &b){
	int tmp = b[0];
	b[0] = b[1];
	b[1] = tmp;
	cout << "inner: b[0]: " << b[0] << ", b[1]: " << b[1] << endl;
}