#include <iostream>

using namespace std;

class Box
{

public:
    // 构造函数
    Box(double h, double w, double l) : height(h), weight(w), length(l){};
    Box() : height(0), weight(0), length(0){};
    
    //构析函数
    ~Box(){};

    // 对外的接口
    double getVolume(void) const
    {
        return height * weight * length;
    }

    double getHeight() const
    {
        return height;
    }

    double getWeight() const
    {
        return weight;
    }

    double getLength() const
    {
        return length;
    }

    void show() const
    {
        cout << "height: " << height << "\t";
        cout << "weight: " << weight << "\t";
        cout << "length: " << length<< endl;
    }

    // 重载后置++：先返回，再自增
    Box &operator++(int)
    {
        Box box;
        box.height = this->height;
        box.weight = this->weight;
        box.length = this->length;
        this->height++;
        this->weight++;
        this->length++;
        return *this;
    }

    // 重载前置++：先自增，再返回
    Box &operator++()
    {
        this->height++;
        this->weight++;
        this->length++;
        return *this;
    }

    // 重载加法运算符
    Box operator+(Box &b)
    {
        Box box;
        box.length = this->length + b.length;
        box.weight = this->weight + b.weight;
        box.height = this->height + b.height;
        return box;
    }

private:
    double height;
    double weight;
    double length;
};

int main()
{
    Box box1(2.0, 3.0, 4.0);
    Box box2(5.0, 3.0, 4.0);
    Box box3;

    box1.show();
    box2.show();
    double volume = 0.0;

    box3 = box1 + box2;
    box3.show();
    box3++;
    box3.show();
    volume = box3.getVolume();
    cout << "volume of box3 is: " << volume << endl;

    return 0;
}