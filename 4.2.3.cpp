# include <iostream>
using namespace std;

class Test{
public:
    Test(int a, int b){
        x=a; y=b;
        cout << "Initializing: " << x << ", y: " << y << endl;
    }
    Test(){cout << "初始化，但是不设置成员变量的值，让其为不确定状态" << endl;} // 定义内实现，为内联

    int getX(){return x;}
    int getY(){return y;}
private:
    int x;
    int y;
};

int main(){
    /*
    使用new 创建对象是动态分配内存，并且为了内存可控， 不会跟随函数等的生命周期自动销毁
    只能手动用delete释放内存
    */
    Test * p1 = new Test();
    Test * p2 = new Test(5, 7);

    delete p1;
    delete p2;
    system("pause");
    return 0;
}