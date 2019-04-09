# include <string>
# include <iostream>
using namespace std;

// 使用函数返回值作为函数的参数

int getInt();
int max(int, int);
void func_324();

void func_324(){
	cout << max(55, max(22, getInt())) << endl;
}

int getInt(){
	return 11;
}

int max(int i1, int i2){
	return (i1 > i2)?i1:i2;
}