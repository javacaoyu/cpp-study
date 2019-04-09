# include <string>
# include <iostream>
# include <complex>
using namespace std;

// 模板函数示例(显式)

template <typename T>		// typename 定义后 编译器可以自动判断类型， 不需要显式的说明类型
T maxTypename(T a, T b){
	return (a > b)? a: b;	
}
void func_351_2();

void func_351_2(){
	cout << "22, 55 who's max? " << maxTypename(22, 55) << endl;
	cout << "22.22, 55.55 who's max? " << maxTypename(22.22, 55.55) << endl;
	/*
	如果没有用typename定义T
	那么用函数要这样用 maxTypename <int>(1, 2) or maxTypename <float>(22.22, 55.55)
	*/
}
