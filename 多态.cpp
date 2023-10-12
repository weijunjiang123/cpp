#include <iostream>
using namespace std;

class Shape{
    protected:
        int length, weight;
    public:
        Shape(int len = 0, int wei = 0){
            length = len;
            weight = wei;
        }
        // 设置虚函数，在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数
        virtual int area(){
            cout << "Prant class area:" << endl;
            return 0;
        }
};

class Rectangle: public Shape{
    public:
    Rectangle(int len = 0, int wei =0):Shape(len, wei){

    }
    int area(){
        cout << "Rectangle class area: " << endl;
        return length * weight;
    }
};

class Triangle: public Shape{
    public:
    Triangle(int len = 0, int wei = 0):Shape(len, wei){

    }
    int area(){
        cout << "Triangle class area" << endl;
        return (length * weight / 2);
    }
};

int main(){
    Shape *shape;
    Rectangle rec(5,20);
    Triangle tri(10, 20);
    shape = &rec;
    shape->area();
    shape = &tri;
    shape->area();

}