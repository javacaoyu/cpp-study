# include <iostream>
using namespace std;

// 纯虚函数 和 抽象类
// 一般在用多态的时候，很多时候，父类的虚函数的实现是基本上不用的， 但是又要给他写实现，没有意义
// 这里就引出了 纯虚函数的概念，纯虚函数就是一个没有实现的虚函数
// 但是，一旦类里面出现了纯虚函数，那么这个类自动就变成了 抽象类
// 抽象类： 
/*
1. 抽象类无法实例化对象
2. 子类继承抽象类，如果不重写父类的纯虚函数，子类也无法实例化对象


*/

class AbstrackCalculator{
public:
    virtual int getResult(int &, int &) = 0;        // 纯虚函数的定义语法， 直接等于0即可， 不需要{}了
};          

class AddCalculator:public AbstrackCalculator{
public:
    int getResult(int &n1, int &n2){    // 子类中的virtual 可写可不写，如下面减法类就没写，一样的
        return n1 + n2;                 // 参数也要和父类一样哦，不然不算复写
    };
};

class SubCalculator:public AbstrackCalculator{
public:
    int getResult(int &n1, int &n2){    // 子类如果不复写，也是不能实例化哦
        return n1 - n2;
    }
};

void test01(){
    //AbstrackCalculator as;  // 无法实例化抽象类哦
    AbstrackCalculator * as = new AddCalculator;
    int a = 3;
    int b = 5;
    cout << a << "+" << b << "=" << as->getResult(a, b) << endl;
    delete as;


    as = new SubCalculator;     // 上面delete删除的是内存空间， as 还在，所以可以被赋值。最后不用delete后还应该手动置为 NULL
    cout << a << "-" << b << "=" << as->getResult(a, b) << endl;
    delete as;
    as = NULL;
}

int main(){
    test01();

    system("pause");
    return 0;
}