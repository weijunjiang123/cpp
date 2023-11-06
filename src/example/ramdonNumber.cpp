#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

extern int getRandomNum (){
    int i,j;
    // 设置种子
    srand( (unsigned)time( NULL ) );
    /* 生成 10 个随机数 */
    return rand();

}