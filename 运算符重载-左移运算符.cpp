# include <iostream>
# include <ostream>
using namespace std;
// 重载 << 运算符， 用在cout上

//下面的Person类，如果要输出 a 和 b  要手动 cout << p.a << p.b ...xxx
// 如果我们想cout << p 直接就能输出a 和b呢， 如果不重载运算法 是报错的， 因为编译器不知道
// cout << p 是啥意思 就跟 Person p3 = p1 + p2; 了 不认识这个+号能干嘛， 这里也是 不知道 <<能干嘛 对于p
// 所以要重载 << 
class Person{
    // 成员函数重载
    //ostream operator<<(ostream out){}; 不能在成员函数中重载，因为在成员函数内 表示成员函数是左值 也就是 p << cout 
    // 但是正常是cout 在左边呢 ， 所以只能用全局函数重载

    // 友元运算符重载的函数
    friend ostream& operator<<(ostream &osout, Person &p);

    int a;
    int b;
public:
    Person(int a, int b){
        this->a = a;
        this->b = b;
    }
};

// 全局函数重载<<
ostream& operator<<(ostream &osout, Person &p){
    // 这里p想访问a和b 访问不了，因为a和b是私有的， 这里
    // 引入，运算符重载的函数也可以被友元哦。
    osout << "p.a : " << p.a << ", p.b: " << p.b;
    return osout;   // 这里传入参数是ostream的引用，cout本身属于ostream，这里osout就是一个引用别名
                    // cout << p 就是 operator<<(cout, p)的简写啦， 传入的就是cout本身，这里用引用接收
                    // 但是一定要返回， 如果不返回，那么比如在main函数中用 cout << p 没问题
                    // 但是要使用 cout << p << endl;就会有问题， 因为 p << endl; 编译器又不认识咯， 难道
                    // 还能写一个 p << endl;的运算符重载吗？ 那如果后面是 p << "hello world"; 呢 总不能都重载运算符吧
                    // 所以这里 把原本的cout 返回回去就可以啦

}


int main(){
    Person p(10, 20);
    cout << p;

    system("pause");
    return 0;
}