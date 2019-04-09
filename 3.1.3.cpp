# include <string>
# include <iostream>
using namespace std;

typedef int array[10];	// 自定义array数组类型,用来间接引用数组
void func_313(void);
void swap(array &s1);

void func_313(){
	array a = {1, 9};	// 数组a
	array &b = a;		// 对数组a的间接引用
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