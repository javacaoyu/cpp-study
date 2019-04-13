# include <iostream>
using namespace std;
# include <string>
// 类模板没有类型推导
// 2. 类模板参数类型可以有默认参数，如下(函数模板没有哦)
template<class NameType, class AgeType = int>   // AgeType 默认是int
class Person{
public:
    NameType name;
    AgeType age;

    Person(NameType name, AgeType age);

    void show();
};

// 函数外实现类构造
template<class NameType, class AgeType>     // 上面Age Type的默认参数依旧有效
Person<NameType, AgeType>::Person(NameType name, AgeType age){
    this->name = name;
    this->age = age;
}

// 函数外， 实现成员函数
template<class NameType, class AgeType> // 上面Age Type的默认参数依旧有效
void Person<NameType, AgeType>::show(){
    cout << "name: " << name << ", age: " << age << endl;
}


int main(){
    // Person<string, int> p("孙悟空", 999);
    Person<string> p("孙悟空", 999);    //999 对应AgeType，有默认类型， 如果匹配可以不写。
                                        // 但如果没有默认类型，不提供的话， 会报错编译
    p.show();

    system("pause");
    return 0;
}