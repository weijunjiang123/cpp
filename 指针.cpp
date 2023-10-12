#include <iostream>

using namespace std;

int main(){
    int var1 = 20;        //实际变量的声明
    int *ip;              //指针变量的声明
    ip = &var1;           //将指针变量中存储var1的地址

    cout << "value of var1 variable: " << var1 << endl;
    //输出指针变量中存储的地址
    cout << "Address stored in ip variable: " << ip << endl;
    //输出指针中地址的值
    cout << "value of *ip variable: " << *ip << endl;

    return 0;
}