# include <string>
# include <iostream>
# include <complex>
using namespace std;

// ģ�庯��ʾ��

template <class T>
// void pointer(complex <T>);  �������ԣ�ģ�庯�����ܶ��壬ֱ��ʵ�ּ��ɣ� ��֪��Ϊɶ����һ����Ͼͱ���
void pointer(complex <T> a){
	cout << "Real is: " << a.real() << ", image is: " << a.imag() << endl;
}
void func_351();

void func_351(){
	complex <float> a(22.22, 66.66);
	complex <int> b(2, 9);

	pointer(a);
	pointer(b);

}
