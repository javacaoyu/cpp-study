# include <iostream>
using namespace std;

template<typename T>    // 告诉编译器，后面紧跟着的T不要报错，是我定义的模板类型
                        // 一定要紧跟着，T被用了一次后，需要重新定义的
void mySwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

// template<typename T>
// template<typename T2>            这样写貌似不行哟。
// void mySwap2(T &a, T2 &b){
// T temp = a;
//     a = b;
//     b = temp;
// }

int main(){
    int a = 10;
    int b = 20;
    float c = 22.22;
    // 1. 自动推导类型
    mySwap(a, b);
    cout << "a: " << a << ", b: " << b << endl;
    // 2. 显示告诉编译器，模板的类型
    mySwap<int>(a, b);
    cout << "a: " << a << ", b: " << b << endl;

    //mySwap(a, c);   // 错误的， 自动类型推导一定要推导出一致的

    system("pause");
    return 0;
}

/*
函数模板也可以重载的哦

另外：
1. 
template<typename T>
void func(){cout << "hahaha" << endl;}

正常func是一个正常的函数， 也没有参数啥的，但是因为它紧跟在模板下面， 所以就是一个模板函数

那么如果直接调用func() 是不行的。 因为，1. 自动类型推导 推导不出来T是什么类型 哪怕你没有用到T
                                    2. 也没有显示制定，也不知道T是啥， 哪怕没用T

这样要用func() 只能
1. 注释掉模板定义
2. 使用 func<int>() 来调用， 给定一个T的类型, 类型随便给， 但是必须给。




2. 
普通函数调用，会自动隐式类型转换， 比如int转float
模板函数调用， 如果自动类型推导的话 不会做自动隐式类型转换
模板函数调用，但是如果显示指定了类型的话， 可以自动隐式类型转换


3. 
一：函数模板和 普通函数，如果都可以调用， 优先调用普通函数如：
    void xxx(int a, int b)
    template<class T>
    void xxx(T a, T b)
    如果xxx两个都能被调用到，优先调用普通函数

二：如果要强制调用模板函数，需要用空模板类型参数强制调用，如：
    xxx<>(100 ,200);    使用自动推导的空函数模板参数调用模板函数 <>内不要写任何内容，如果写了要保证和参数的类型匹配，写了就是下面的方式了
    xxx<int>(100, 200); 显示制定模板类型，强制调用模板

三：函数模板也可以重载
    template<class T>
    void xxx(T a, T b)

    template<class T>
    void xxx(T a, T b, T c)

    是可以的

四：如果函数模板能够更好的普配，优先使用函数模板，如:
    void xxx(int a, int b)
    
    template<class T>
    void xxx(T a, T b)

    使用两个char类型作为参数， 那么两个xxx 都能用， 只是普通函数，需要做char的隐式转换成int
    而模板可以直接用，所以模板更好匹配，调用的是模板

    如果使用两个double作为参数，那么不用说了，一定是模板，因为普通函数xxx根本不能接收double类型参数哦

五：模板不是万能的哦，如：
    一个模板比较 a 和 b的大小， 普通int double都能比，但是如果是自定义的类型呢， 如person类 point类 就不行了哦
    比如一个模板两个参数， a 和 b 函数体就是 a = b  做赋值， 一般没问题， 但如果传入的是数组就不行， 因为数组不能互相赋值
    so, 模板不是万能的， 用的时候要多想。
*/