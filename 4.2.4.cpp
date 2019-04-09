# include <iostream>
using namespace std;

class Test{
public:
    Test(int a=0, int b=0){
        x=a;y=b;
        cout << "Initializing x: " << x << ", y: " << y << endl;
    }

    int getX(){return x;}
    int getY(){return y;}
private:
    int x;
    int y;
};

int main(){
    /*
    构造函数采用了默认参数设置，默认x 和 y 为0
    所以 可以传0个参数
    可以传1个参数
    也可以传两个参数哦， 一举多得，省的定义无参构造以及有参构造定义好几个咯

    验证： 输出为：
    Initializing x: 0, y: 0 无参
    Initializing x: 1, y: 0 传一个参数（给x赋值了)
    Initializing x: 5, y: 7 传两个参数，都赋值咯
    */
    Test * p1 = new Test();
    Test * p2 = new Test(1);
    Test * p3 = new Test(5, 7);

    delete p1;
    delete p2;
    delete p3;
    system("pause");
    return 0;
}