# include <iostream>
# include <string>
using namespace std;

void func_314(void);
void display(string s1, string s2="", string s3="");	// default parameter.

void func_314(){
	string s1("nihao");
	string s2 = "woyehao";
	string s3 = "dajiahao";

	display(s1);
	display(s1, s2);
	display(s1, s2, s3);
	
}

//void display(string s1, string s2="", string s3=""){  默认参数在原型定义,不能出现在实现
void display(string s1, string s2, string s3){
cout << "s1: " << s1 << ", s2: " << s2 << ", s3: " << s3 << endl;

}