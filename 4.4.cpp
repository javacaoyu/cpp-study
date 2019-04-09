# include <iostream>
using namespace std;
// 析构函数
class Test{
public:
    Test(int a=0, int b=0){
        x=a;y=b;
        cout << "Initializing x: " << x << ", y: " << y << endl;
    }
    Test(const Test & t){       //自定义复制构造函数， 必须用 引用类型。 并且加上const 安全， 不会修改被引用的内容的值
        cout << "copy ing ......." << endl;
        x = t.x;
        y = t.y;        //虽然x y是私有的， 但是一个类的成员函数可以访问这个类定义下的所有 实例 的 私有属性
                        // 也就是 比如 Test a, b;  a 的成员函数可以访问b的私有属性，只要你能把b传入进a的成员函数即可（引用传递）
    }

    ~Test(){        // 为程序定义析构函数，用以释放内存
                    // 析构函数一般和类名同名，前面加上~（也认为和类同名），程序会自动调用析构函数，一般除了
                    // 指针对象手动delete以外，不需要我们显示的调用，会自动调用
                    // 执行delete的时候，会先执行析构，然后释放内存哦
        cout << "Free this class used memory..." << endl;
    }
    int getX(){return x;}
    int getY(){return y;}
private:
    int x;
    int y;
};
void display(Test a){
    cout << a.getX() << ", " << a.getY() << endl;
}
void disp(Test &a){
    cout << a.getX() << ", " << a.getY() << endl;
}
Test fun(){
    Test x(55,66);
    return x;
}
int main(){
    Test a(12,22);
    display(a);
    disp(a);
    Test x = fun();
    cout << x.getX() << ",,,,,,,, " << x.getY() << endl;
    system("pause");
    return 0;
}
/*
输出解析：
Initializing x: 12, y: 22           1
copy ing .......                    2
12, 22                              3
Free this class used memory...      4
12, 22                              5
Initializing x: 55, y: 66           6
55,,,,,,,, 66                       7
Press any key to continue . . .     8

Free this class used memory...      9
Free this class used memory...      10


1. 创建a 调用构造输出Init
2. 显示a， 当形式参数和实际参数结合的时候，也就是直接传对象本体（值传递是复制副本），那么会调用复制构造函数，所以输出copy ing
3. 输出的12， 22 是display函数输出的

4. 然后输出的Free。。。 是display函数执行结束了，display 函数内复制的对象生存周期结束，被释放内存了。

5. 然后执行的是disp函数，输出了12，22 为何没有执行复制构造呢， 因为，传的是引用哦
6. 6输出的Init是在fun内创建x输出的Init
7. 7是输出的x的值   
然后 输出的 Press any key .......
然后最后程序结束的时候 释放创建的a或x对象的内存。。。
然后最后程序结束的时候 释放创建的a或x对象的内存。。。
*/
/*
问题：
1. 在7之后应该有copy ing输出和 Free输出
    copy是 复制fun内的x 给main的x
    Free是fun函数执行结束了 fun内的x被释放内存了
    但是木有输出也，不知道为啥呢
    ??????很纳闷，返回值是对象，用对象接收不也是值复制吗，应该和传入一样输出copy ing才对哦 不知道为啥没输出, 书上说是会输出的 编译器版本问题？
2. fun函数结束的时候 内部的x应该被销毁，输出感觉为何少了一个Free输出
3. 如果main中的x对象不是复制的，那么fun函数都结束了，fun内的x都应该被销毁，那么main中的x如果不是复制过来了怎么还能get到x和y的值呢
*/