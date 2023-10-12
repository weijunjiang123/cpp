#include <iostream>
using namespace std;

int hailstone (int n){
    int length = 0;
    while (n >1){
        if (n % 2 == 0){
            n /= 2;
        }else{
            n = 3*n+1;
        }
        length ++;
    }
    return length;
}
int main(){
    for (int i = 1; i <= 10000; i++){
        cout << hailstone(i) << ',';
    }
}