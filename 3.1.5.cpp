# include <iostream>
# include <string>
using namespace std;

void change(string s);
void change(string &s, string s2);	// s2没有意义, 只是为了重载
void func_315();

void func_315(){
	string s = "No!";
	cout << "Can you change it?";
	change(s);
	cout << s << endl;

}

void change(const string s){
	//s = "hahaha";				// const can not modify
	cout << s << endl;
}

void change(const string &s, string s2){
	//s = "hahaha";				// const can not modify
	cout << s << endl;
}