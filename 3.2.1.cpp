# include <string>
# include <iostream>
using namespace std;

void func_321();
int& index(int);	// 返回类型是引用

int a[] = {1, 2, 3, 4, 5};	//设置一个全局数组

void func_321(){
	cout << "befor use, index 2 is: " << a[2] << endl;

	index(2) = 16;	// 返回的是引用对象， 所以可以直接被赋值

	cout << "after use, index 2 is: " << a[2] << endl;


}

int& index(int i){
	return a[i];	// 因为返回类型是引用， 所以直接返回变量即可, 自动变成引用，指向被引用的数组元素i 的地址
}