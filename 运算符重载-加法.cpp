# include <iostream>
using namespace std;

class Person{
public:
    // 成员函数重载
    // Person operator+(Person &p){
    //     Person temp;
    //     temp.a = p.a + this->a;
    //     temp.b = p.b + this->b;
    //     return temp;
    // }
    int a;
    int b;
};

// 全局函数重载
Person operator+(Person &p1, Person &p2){
    Person temp;
    temp.a = p1.a + p2.a;
    temp.b = p1.b + p2.b;
    return temp;
}


// 3. 运算法重载的函数重载
Person operator+(Person &p1, int num){
    Person temp;
    temp.a = p1.a + num;
    temp.b = p1.b + num + 10;
    return temp;
}


void test01(){
    Person p1, p2;
    p1.a = 10;
    p1.b = 20;
    p2.a = 50;
    p2.b = 60;

    // 正常，编译器不认识+号怎么做， 
    // 可以自定义+号的方法
    // 分为 成员函数重载操作符，和全局函数重载操作符
    
    // 1. 成员函数重载，见类内定义
    // p3 = p1 + p2; 相当于 p3 = p1.operator+(p2);
    Person p3 = p1 + p2;

    cout << "p3.a " << p3.a << endl;
    cout << "p3.b " << p3.b << endl;

    // 2. 全局函数重载， 见类后面的全局函数

    Person p4 = p3 + p2;

    cout << "p4.a " << p4.a << endl;
    cout << "p4.b " << p4.b << endl;

    // 3. 运算符重载同时也可以发生函数重载哦，这里以全局函数为例

    Person p5 = p1 + 100;       // 这里是上面的运算符重载的函数重载哦
    cout << "p5.a " << p5.a << endl;
    cout << "p5.b " << p5.b << endl;
}


int main(){
    test01();

    system("pause");
    return 0;
}
/*
注意 注意 注意
内置数据类型，重载了也没用
比如 1 + 1  怎么重载结果也是2
运算符重载只能适用于自定义类型哦
*/