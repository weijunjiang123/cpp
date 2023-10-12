#include <iostream>
#include <string>

using namespace std;

int main(){
    string str1 = "hello";
    string str2 = "world";
    string str3;

    // 将str1复制到str3
    str3 = str1;
    cout << "str3: " << str3 << endl;

    // 将str1和str2连接
    str3 = str1 + str2;
    cout << "str1+str2: " << str3 << endl;

    // 连接后计算str3的长度
    int len = str3.size();
    cout << "str3.size(): " << len << endl;
    
    return 0;

}