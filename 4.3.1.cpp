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

/* 解析输出:
Initializing x: 5, y: 7
p2->x: 5, p2->y: 7
Free this class used memory...
Press any key to continue . . .

Free this class used memory...

先输出的Free 是 delete p2 显示的调用free内存自动调用的析构函数
然后输出system("pause")的内容
然后程序return 0了 也就是程序执行完了
又输出一个Free 是自动调用析构函数析构的p1
*/