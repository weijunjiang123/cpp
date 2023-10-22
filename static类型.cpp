#include <iostream>

void func(void); 

static int count = 10; // 全局变量: static 修饰, 只能在本文件中使用, 不能被其他文件访问, 也不能被其他文件修改, 但是可以被其他文件定义同名变量覆盖

 int main(){
    while(count--)
    {
       func();    
    }
    return 0;
}
void func( void ){
    static int i = 5; // 局部静态变量: static 修饰, 只能在本函数中使用, 不能被其他函数访问, 也不能被其他函数修改, 但是可以被其他函数定义同名变量覆盖
    i++;
    std::cout << "变量 i 为 " << i ;
    std::cout << " , 变量 count 为 " << count << std::endl;
}