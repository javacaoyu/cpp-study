# include <iostream>
# include <string>
using namespace std;

void swap(string, string);
void func_311(void);

void func_311(){
	string s1 = "现在";
	string s2 = "过去";

	cout << "befor transfer s1: " << s1 << ", s2: " << s2 << endl;
	swap(s1, s2);

	cout << "After transfer s1: " << s1 << ", s2: " << s2 << endl;
	system("pause");
}

void swap(string s1, string s2){
	string tmp = s1;
	s1 = s2;
	s2 = tmp;

	cout << "in swap transfered s1: " << s1 << ", s2: " << s2 << endl;
}