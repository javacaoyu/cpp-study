# include <string>
# include <iostream>
using namespace std;

void func_322();
float * opt(const int &size);	// ָ���ͷ���ֵ

void func_322(){
	int size = 10;
	float * p_data = opt(size);
	for(int i=0;i<size;i++){
		cout << p_data[i] << endl;
	}
	delete p_data;		//�ֶ������ڴ�
}

float * opt(const int &size){
	cout << "size is: " << size << ", create a new array to storage data, max size is size: " << size << endl;
	if (size <= 0){
		cout << "size is < = 0, return NULL" << endl;
		return NULL;
	}
	float * buf = new float[size];		// ��̬����ռ�
	if (buf == 0) return NULL;			// ����ʧ�ܣ�����NULL
	cout << "please input value for size: " << size << " array." << endl;
	for(int i=0;i<size;i++){
		//cin >> *(buf[0] + i);		// Why �����������أ� ���ﲻ��Ӧ�ø�ֵ��
		cin >> buf[i];
	}
	return buf;	//����ָ����buf ��Ϊ���ܷ��س�Ա��������Ա��������������˺����ͱ������ˡ�
				//����Ҫ�ֶ������ڴ棬 ���ֶ����٣�����buf���ֶ�����ģ���Ȼ�ǳ�Ա�����������ڴ治���Զ�����

}