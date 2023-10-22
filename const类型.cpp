#include <iostream>
using namespace std;

int main(){
    //const: 常量, 一旦定义, 不可修改, 一般用大写字母表示, 用下划线分割
    const int LENGTH = 10;
    const int WIDTH = 5;
    const char NEWLINE = '\n';
    int area;  
    area = LENGTH * WIDTH;
    cout << area;
    cout << NEWLINE;
    return 0;
   }