#include <iostream>
using namespace std;

class Box
{
public:
    // 构造函数
    Box(double len, double wei, double hei) : length(len), weight(wei), height(hei){};
    // 拷贝构造函数
    Box(const Box &b)
    {
        length = b.length;
        weight = b.weight;
        height = b.height;
    }
    // 默认构造函数
    Box():length(0), weight(0), height(0){};

    // 析构函数
    ~Box(){};

    // 对外的接口
    void setLength(double len)
    {
        length = len;
    }
    void setWeight(double wei)
    {
        weight = wei;
    }
    void setHeight(double hei)
    {
        height = hei;
    }
    void printBox()
    {
        cout << "Length: " << length << "\t";
        cout << "Weigth: " << weight << "\t";
        cout << "Height: " << height << endl;
    }

    // 重载运算符，实现Box类对象的加法运算
    Box operator+(const Box &b)
    {
        Box box;
        box.length = this->length + b.length;
        box.weight = this->weight + b.weight;
        box.height = this->height + b.height;
        return box;
    }

protected:
    double length;
    double weight;
    double height;
};

int main()
{
    Box box1(1.0, 2.0, 5.5);
    Box box2(3.0, 4.8, 3.1);
    Box box3;
    box3 = box1 + box2;
    cout << "box1: " << endl;
    box1.printBox();
    cout << "box2: " << endl;
    box2.printBox();
    cout << "box3: " << endl;
    box3.printBox();
}
