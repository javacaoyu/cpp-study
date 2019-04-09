# include <iostream>
# include <string>

using namespace std;

void swap(string *, string *);

void func_312(){
	string s1 = "现在";
	string s2 = "过去";

	string &s3 = s1;	// 引用必须初始化
	//&s3 = s2;		不可以的,引用初始化之后，不可以再改变(引用指向其他变量了)
	//   s3 = s2; 是可以的， 这个改变的是s3 对应的指(s3 等同于 s1)
	cout << "befor transfer s1: " << s1 << ", s2: " << s2 << endl;
	swap(&s1, &s2);

	cout << "After transfer s1: " << s1 << ", s2: " << s2 << endl;

	cout << "s3: " << s3 << endl;
	system("pause");
}

void swap(string * s1, string * s2){
	string tmp = *s1; *s1 = *s2; *s2 = tmp;
	cout << "in swap: s1: " << *s1 << ", s2: " << *s2 << endl;
}