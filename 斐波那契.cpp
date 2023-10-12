#include <iostream>

using namespace std;

int febonacci(int n);

int main(){
    for(int i = 1; i < 100; i++){
        cout << i << " is: " << febonacci(i) << endl;
    }
    return 0;
}

int febonacci(int n){
    if(n == 1) return 1;
    if(n == 2) return 1;
    long f = 0;
    long g = 1;
    for(int i = 2; i <= n; i++){
        g = f + g;
        f = g - f;
    }
    return g;
}