# include <iostream>
# include <string>

using namespace std;

void swap(string *, string *);

void func_312(){
	string s1 = "����";
	string s2 = "��ȥ";

	string &s3 = s1;	// ���ñ����ʼ��
	//&s3 = s2;		�����Ե�,���ó�ʼ��֮�󣬲������ٸı�(����ָ������������)
	//   s3 = s2; �ǿ��Եģ� ����ı����s3 ��Ӧ��ָ(s3 ��ͬ�� s1)
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