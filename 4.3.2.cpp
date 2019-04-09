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
   Test * ptr = new Test[2];    // 动态创建Test对象数组，成员2个
                                // 会输出两个init语句
    delete [] ptr;              // 删除数组的内容， 必须用[] 告诉delete 这是一个数组对象， 它会
                                // 自动释放这个数组对象的每一个元素。
                                // 不能写成 ptr[] 

    /*
    输出为：
    Initializing x: 0, y: 0
    Initializing x: 0, y: 0
    Free this class used memory...
    Free this class used memory...
    正好 两次init 两次Free
    */
    
    system("pause");
    return 0;
}
/*
默认析构：
如果不自己定于，会自动定义一个默认的，如下:
~Test(){}   函数体为空
*/