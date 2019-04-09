# include <iostream>
using namespace std;

class Test{
public:
    Test(int a, int b){
        x=a; y=b;
        cout << "Initializing: " << x << ", y: " << y << endl;
    }
    Test(){}                        // 定义内实现，为内联

    int getX(){return x;}
    int getY(){return y;}
private:
    int x;
    int y;
};

// 定义为全局变量并且在main之前，那么在进入main之前会自动调用构造函数 补充， 如果是外部变量，不会调用构造函数
/*
输出为：
Initializing: 5, y: 7
Enter main...
*/
Test global(5, 7);

int main(){
    cout << "Enter main..." << endl;

    system("pause");
    return 0;
}