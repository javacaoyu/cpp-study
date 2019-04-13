# include <iostream>
using namespace std;
// 静态 类 对象

class Test{
public:
    Test(){cout << "构造啦" << endl;}
    Test(int a){cout << "构造啦" << endl;x = a;}
    ~Test(){cout << "析构啦" << endl;}
    int getX(){return x;}
    void setX(int a){x = a;}
    void fun(){x++;}
private:
    int x;
};

int main(){
    for(int i = 0; i < 3; i++)
    {
        static Test a(3);           // 静态对象， 一次构造 整个程序生命周期都存在 不管for循环创建几次， 只输出一次构造 结束的时候输出一次析构
                                    // 也就是后续for循环构建这个静态对象不会调用构造函数
        Test b(3);
        a.fun();                    // 如上， 对象一直存在，那么成员值一直保留，那么++ 就一直累加 最终a里面的x 会++到6 而b对象，每次都是新的 也就是都是++后都是4
        b.fun();
        cout << "a.x: " << a.getX() << endl;
        cout << "b.x: " << b.getX() << endl;
    }
    
    
    system("pause");
    return 0;
}
/*
输出：
构造啦
构造啦
a.x: 4
b.x: 4
析构啦
构造啦
a.x: 5
b.x: 4
析构啦
构造啦
a.x: 6
b.x: 4
析构啦
*/