# include <iostream>
using namespace std;
# include <vector>
# include <algorithm> // 标准算法的头文件 algorithm

void print(int val){
    cout << val << endl;
}

void test01(){
    vector<int> v;  // 定义一个vector容器
    // 向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    // how to iterator it？

    // v.begin() 获得起始迭代器，指向第一个元素。v.end() 指向最后一个元素  的   下一位
    // v.begin() v.end() 得到的都是指针
    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();
    
    // 第一种遍历方式:
    cout << "Function 1: " << endl;
    while(itBegin != itEnd){
        cout << *itBegin << endl; // *取指针指向内容的值
        itBegin++;  //指针++
    }

    // 第二种方式，更简单
    // 把上面的内容合到一个for循环内了
    cout << "Function 2: " << endl;
    for(vector<int>::iterator itBegin = v.begin(); itBegin != v.end(); itBegin++){
        cout << *itBegin << endl;
    }

    // 第三种方式去遍历，用系统提供的for_each方法
    cout << "Function 3, using for_each: " << endl;
    // 参数1，起始位置，参数2结束位置（不包含），参数3，回调函数的name（回调函数接受一个参数就是取出来的内容，
    // 处理逻辑自己写）
    for_each(v.begin(), v.end(),print);
}





int main(){
    test01();

    system("pause");
    return 0;
}