#include <iostream>
using namespace std;

class Adder{
    public:
    // 构造函数
    Adder(int a = 0){
        total = a;
    }
    // 对外的接口
    void addNum(int num){
        total += num;
    }
    // 对外的接口
    int getTotal(){
        return total;
    }
    private:
    // 对外隐藏的数据
    int total;
};

int main(){
    Adder adder(10);
    adder.addNum(10);
    cout << "total number is " << adder.getTotal() << endl; 
    return 0;
}