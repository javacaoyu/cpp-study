# include <iostream>
using namespace std;
//静态成员

class A{
public:
    A(int a, int b){
        A::n = a;   // 静态成员 必须用类限定符 实现, 因为静态属于整个类，不属于单个对象
        x = b;
    }
    A(){};
    void pp(){n++;}
    static int getN(){return n;}
    int getX(){return x;}
    void setX(int a){x = a;}
private:
    static int n;
    int x;
protected
};

int A::n = 5;           // why? n是private的啊？ 是不是说private只作用与类的对象上， 静态的类成员是全部公用的可以直接改？
// void A::setN(6); 这个为何编译不通过？
int main(){
    cout << A::getN() << endl;
    A a;
    a.setX(66);
    cout << a.getN() << ", " << a.getX() << endl;   // n 所有对象共享哟， 不设置也有的。
    system("pause");
    return 0;
}