# include <string>
# include <iostream>
# include <complex>
using namespace std;

// 模板函数示例

template <class T>
// void pointer(complex <T>);  经过测试，模板函数不能定义，直接实现即可， 不知道为啥，这一句带上就报错
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
