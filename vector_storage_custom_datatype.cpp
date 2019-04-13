# include <iostream>
using namespace std;
// vector 中存放自定义数据内容
# include <vector>
# include <string>
# include <algorithm>
// 自定义内容，class，persion
class Person{
public:
    Person(string name, int age){this->name = name; this->age = age;}

public:
    string name;
    int age;
};

// 存放自定义类型对象
void test01(){
    vector<Person> v;
    Person p1("孙悟空", 10000);
    Person p2("猪八戒", 9999);
    Person p3("沙悟净", 8888);
    Person p4("唐小僧", 10000);
    Person p5("白龙马", 5000);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    

    // 遍历for
    for(vector<Person>::iterator itBegin = v.begin(); itBegin != v.end(); itBegin++){
        cout << itBegin->name << ", " << itBegin->age << endl;
        cout << (*itBegin).name << ", " << (*itBegin).age << endl;
        // 上面两种方法一个作用
        // 因为itBegin就是vector存放的元素的指针，这个vector存放的是Person类
        // 那么itBegin就是Person的一个对象指针，所以可以用-> 取元素（public）
        // 或者解引用得到对象直接用. 来取也是一样的 注意(*itBegin) 别忘了括号括起来
    }

}
//存放自定义类型对象的指针
void test02(){
    vector<Person*> v;
    // 注意咯， 指针对象要么从已有对象指向过去赋值，要么new 赋值,
    // 这里没有也不需要既有对象， 就需要用new来动态分配内存
    Person * p1 = new Person("孙悟空", 10000);
    Person * p2 = new Person("猪八戒", 9999);
    Person * p3 = new Person("沙悟净", 8888);
    Person * p4 = new Person("唐小僧", 10000);
    Person * p5 = new Person("白龙马", 5000);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    
    /*
    或者这样也可以存入进去，不需要new,  取对象地址就可以
    Person p1("孙悟空", 10000);
    Person p2("猪八戒", 9999);
    Person p3("沙悟净", 8888);
    Person p4("唐小僧", 10000);
    Person p5("白龙马", 5000);
    v.push_back(&p1);
    v.push_back(&p2);           用& 取地址等同于传入指针
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    */

    // 遍历for
    for(vector<Person*>::iterator itBegin = v.begin(); itBegin != v.end(); itBegin++){
        cout << "test02: " << (*itBegin)->name << ", " << (*itBegin)->age << endl;
        cout << "test02: " << (**itBegin).name << ", " << (**itBegin).age << endl;
        // 上面两种方法一个作用
        // 因为itBegin就是vector存放的元素的指针，这个vector存放的是Person类的指针对象
        // 那么itBegin就是Person的一个对象指针的指针，所以要(*itBegin)-> 取
        // 第二种 ** 取出来指针指向的指针指向的对象 所以用. 可以取
    }

    // new 搭配 delete 绝配哦，别忘了
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;

}

void test03(){
    // 其他向量的创建方式
    vector<int> a(20);  // 创建一个存放20个int的向量，每个元素默认0
    vector<int> b(20, 5);    // 创建一个存放20个int的向量，每个元素默认5
    vector<int> c(b);       // 按b来定义c， 让c和b一样
    vector<char> d(30, 't');    // 定义一个30个大小的char向量，每个元素默认为字符 t

    c = b;  //整体赋值，让c和b一样
    b = a;  // 整体赋值，让b 和 a 一样

    a.size();   // 向量当前大小
    a.max_size();   //向量可以存储的最大大小，取决硬件和系统
    a.capacity();   //在下次自动扩容前，可以存放的容量
    a.front();      //返回第一个对象
    a.back();       //返回最后一个对象
}


// 逆向遍历
void test05(){
    vector<Person> v;
    Person p1("孙悟空", 10000);
    Person p2("猪八戒", 9999);
    Person p3("沙悟净", 8888);
    Person p4("唐小僧", 10000);
    Person p5("白龙马", 5000);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    

    // 遍历for
    cout << "test05: 逆向遍历: " << endl;
    for(vector<Person>::reverse_iterator it = v.rbegin(); it != v.rend(); it++){
        cout << it->name << ", " << it->age << endl;
        cout << (*it).name << ", " << (*it).age << endl;
        // rbegin() 返回的是结尾的泛型指针
        // reverse_iterator 是逆向遍历， 泛型指针++ 是向前走
        // rend r end.  rend() 是取的第一个元素的泛型指针哦
    }

}

int main(){
    // test01();
    // test02();
    test05();
    system("pause");
    return 0;
}