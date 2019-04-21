# include <iostream>
using namespace std;
# include <string>

/*
虚析构： 如果在用多态的时候，使用了赋值兼容性（父类对象或指针指向子类示例）
那么在delete这个父类指针或者运行结束自动析构对象的时候， 无法自动的调用到子类的虚构函数
class P .....
class SP:public P ......

P * p = new SP;
delete p;
如上delete p的时候，只会调用父类的析构函数， 而不会调用子类的析构函数，为了解决这个问题，
把父类的析构函数 设置为虚函数即可
这样在delete p的时候 会先析构 sp子类，然后析构父类

同时 析构函数如果没啥特殊实现可以设置为纯虚析构（纯虚的析构函数）
定义为： ~P() = 0;
规则和纯虚函数一样， 类自动变抽象类，无法实例化哦，子类要复写，不然子类也无法实例化

但是如果设置了纯虚析构，但是确实需要函数体怎么办呢？ 那就是在类外实现纯虚析构哦（对哦，没看错，纯虚析构在类外可以实现函数体的）
实现如：
P::~P(){xxx} xxx是函数体

下面代码演示一下
*/
class Animal{
public:
    virtual void speak() = 0;
    virtual ~Animal() = 0;
};
Animal::~Animal(){      // 纯虚析构的类外实现
    cout << "Animal 纯虚析构函数工作啦" << endl;
}

class Cat:public Animal{
public:
    string * name;
    Cat(string * name){
        this->name = new string(*name);
    }
    void speak(){
        cout << *name << ": 喵喵喵" << endl;
    }
    ~Cat(){
        cout << "cat 析构函数工作啦" << endl;
        delete this->name;  // 因为有name这个指针，接受了new，在堆区有内存，必须要执行析构释放，不然内存就浪费了，泄露了
        this->name = NULL;
    }
};

void test01(){
    Animal * a = new Cat(new string("tom"));
    a->speak();
    delete a;
    a = NULL;
}

int main(){
    test01();

    system("pause");
    return 0;
}

/*
输出：
tom: 喵喵喵
cat 析构函数工作啦
Animal 纯虚析构函数工作啦

可以看出，cat析构了，父类animal也析构了，目标达成
*/