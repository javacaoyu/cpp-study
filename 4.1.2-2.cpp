# include <string>
# include <iostream>
using namespace std;

class Point{
    int x;                                          // 不给权限，默认private
private:
    int y;
public:
    int getX(){return x;}                           // inline
    int getY(){return y;}                           // inline

    void move(int a, int b){x += a; y += b;}        // 类定义中实现的话，自动就是内联函数inline
    void display(){
        cout << "x: " << x << ", y: " << y << endl; // inline
    }
    void setXY(int, int);

};

void Point::setXY(int a, int b){                    // 类定义的外面实现，就不是内联
    x = a;
    y = b;
}

void print(Point &a){                               // 引用接收
    cout << "x: " << a.getX() << ", y: " << a.getY() << endl;
}

int main(){
    Point a, b;                                     // object of class Point
    Point * p = &b;
    Point & r = a;
    a.setXY(1,6);
    b.setXY(6,12);

    print(a);
    print(b);

    r.setXY(99, 100);
    p->setXY(2, 7);

    print(a);
    print(b);

    // cout << "x: " << a.x << endl;   这样会报错的， 因为是私有，报错为： error: 'int Point::x' is private within this context
    system("pause");
    return 0;
}