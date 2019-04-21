# include <iostream>
using namespace std;


template<class T>
class TA{
public:
    T x;
    TA(T X): x(X){}
};

int main(){
    TA <int> a(10);
    cout << "a.x: " << a.x << "asd";


    system("pause");
    return 0;
}