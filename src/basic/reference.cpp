#include <iostream>

using namespace std;

// 引用很容易与指针混淆，它们之间有三个主要的不同：
// 1. 不存在空引用。引用必须连接到一块合法的内存。
// 2. 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
// 3. 引用必须在创建时被初始化。指针可以在任何时间被初始化。

int main(){
    int i;
    double j;

    int& r = i;
    double& s = j;
    
    i = 10;
    cout << "value of i: " << i << endl;
    cout << "value of i reference: " << r << endl;

    j = 14.5;
    cout << "value of j: " << j << endl;
    cout << "value of j reference: " << s << endl;

    return 0;
}

// 引用通常用于函数参数列表和函数返回值。下面列出了 C++ 程序员必须清楚的两个与 C++ 引用相关的重要概念：
// 概念	                    描述
// 把引用作为参数      c++支持把引用作为参数传给函数，这比传一般的参数更安全。
// 把引用作为返回值    可以从c++函数中返回引用，就像返回其他数据类型一样。