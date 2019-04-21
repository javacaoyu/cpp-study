# include <iostream>
using namespace std;
// 动态 多态， 虚函数， 运行时确定。地址后绑定
// 静态多态：重载，运算符重载


class Animal{
public:
    virtual void speak(){cout << "Animal Speaking..." << endl;}
    // 带上virtual 后 分别输出 喵喵喵和汪汪汪， 不带，输出Animal Speaking...
};

class Cat:public Animal{
public:
    void speak(){cout << "喵喵喵" << endl;}
};

class Dog:public Animal{
public:
    void speak(){cout << "汪汪汪" << endl;}
};

void doSpeak(Animal &animal){
    animal.speak();
}

void test01(){
    Animal animal;
    Cat cat;
    Dog dog;

    doSpeak(cat);
    doSpeak(dog);
}

int main(){
    test01();

    system("pause");
    return 0;
}