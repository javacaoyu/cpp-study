# include <iostream>
using namespace std;

class Test{
public:
    Test(int, int);
    Test();

    int getX(){return x;}
    int getY(){return y;}
private:
    int x;
    int y;
};

Test::Test(int a, int b): x(a), y(b){
    cout << "Initializing " << x << ", " << y << endl;
}
/*
Test::Test(int a, int b): x(a), y(b){   这样的写法 叫做初始化列表
    cout << "Initializing " << x << ", " << y << endl;
}
等价于:
Test::Test(int a, int b){
    x = a; y = b;
    cout << "Initializing " << x << ", " << y << endl;
}
*/
Test::Test(){};                 // 无参构造函数实现
//Test::Test():x(0), y(0){cout << "Initializing " << x << ", " << y << endl;};// 也可以这样写, 这样就是给 x 和 y 一个默认值0（C++ 中不能在类定义中给成员变量初始化值（java可以，一般做默认值））

int main(){
    Test ts[2];     // 如果Test类定义了自己的带参数的构造函数(但不提供无参构造函数)，那么这样创建数组就不行，因为这样创建数组需要默认无参的构造函数
                    // 因为自己构造了带参构造函数，那么默认不提供无参的，需要自己实现一个。
    Test ts2[2] = {Test(5, 7), Test(12, 22)};  // 使用带参构造创建数组


    system("pause");
    return 0;
}