# include <string>
# include <iostream>
# include <complex>
using namespace std;

// ģ�庯��ʾ��(��ʽ)

template <typename T>		// typename ����� �����������Զ��ж����ͣ� ����Ҫ��ʽ��˵������
T maxTypename(T a, T b){
	return (a > b)? a: b;	
}
void func_351_2();

void func_351_2(){
	cout << "22, 55 who's max? " << maxTypename(22, 55) << endl;
	cout << "22.22, 55.55 who's max? " << maxTypename(22.22, 55.55) << endl;
	/*
	���û����typename����T
	��ô�ú���Ҫ������ maxTypename <int>(1, 2) or maxTypename <float>(22.22, 55.55)
	*/
}
