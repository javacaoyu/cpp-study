# include <string>
# include <iostream>
using namespace std;

void func_322();
float * opt(const int &size);	// 指针型返回值

void func_322(){
	int size = 10;
	float * p_data = opt(size);
	for(int i=0;i<size;i++){
		cout << p_data[i] << endl;
	}
	delete p_data;		//手动销毁内存
}

float * opt(const int &size){
	cout << "size is: " << size << ", create a new array to storage data, max size is size: " << size << endl;
	if (size <= 0){
		cout << "size is < = 0, return NULL" << endl;
		return NULL;
	}
	float * buf = new float[size];		// 动态申请空间
	if (buf == 0) return NULL;			// 申请失败，返回NULL
	cout << "please input value for size: " << size << " array." << endl;
	for(int i=0;i<size;i++){
		//cin >> *(buf[0] + i);		// Why 不能这样用呢？ 这里不是应该赋值吗
		cin >> buf[i];
	}
	return buf;	//返回指针是buf 因为不能返回成员变量，成员变量的作用域出了函数就被销毁了。
				//所以要手动申请内存， 并手动销毁，所以buf是手动申请的，虽然是成员变量，但是内存不会自动销毁

}