# include <iostream>
using namespace std;

class Test{
public:
    Test(int a=0, int b=0){
        x=a;y=b;
        cout << "Initializing x: " << x << ", y: " << y << endl;
    }
    Test(const Test & t){       //自定义复制构造函数， 必须用 引用类型。 并且加上const 安全， 不会修改被引用的内容的值
        x = t.x;
        y = t.y;        //虽然x y是私有的， 但是一个类的成员函数可以访问这个类定义下的所有 实例 的 私有属性
                        // 也就是 比如 Test a, b;  a 的成员函数可以访问b的私有属性，只要你能把b传入进a的成员函数即可（引用传递）
    }

    int getX(){return x;}
    int getY(){return y;}
private:
    int x;
    int y;
};

int main(){
    /*

    */
    Test p1(5, 7);
    Test * p2 = new Test(p1);   // 使用复制，复制p1给p2的指针对象
                                // 注意 Test * p = new Test(1,2);  Test * p2 = new Test(p); 是不对的， 复制接受的是引用，但传入的是指针
    
    cout << "p2->x: " << p2->getX() << ", p2->y: " << p2->getY() << endl;   // 指针要用 -> 哦

    delete p2;
    system("pause");
    return 0;
}