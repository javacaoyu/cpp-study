# include <string>
# include <iostream>
using namespace std;

// ÄÚÁª º¯Êı inline

inline int maxInline(int, int);
void func_33();
void func_33(){
	cout << "Please input two number for get the max number." << endl;
	cout << "num 1" << endl;
	int i1, i2;
	cin >> i1;
	cout << "num 2" << endl;
	cin >> i2;
	cout << "max is: " << maxInline(i1, i2) << endl;
}

inline int maxInline(int i1, int i2){
	return (i1 > i2)? i1: i2;
}