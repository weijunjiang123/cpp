#include <iostream>
using namespace std;

class Shape
{
public:
    // 提供接口框架的纯虚函数，
    virtual int getArea() = 0;
    void setLength(int len)
    {
        length = len;
    }
    void setWeight(int wei)
    {
        weight = wei;
    }

protected:
    int length, weight;
};
// 派生类Rectangle
class Rectangle : public Shape
{
public:
    int getArea()
    {
        return length * weight;
    }
};
// 派生类Triangle
class Triangle : public Shape
{
public:
    int getArea()
    {
        return (length * weight / 2);
    }
};

int main()
{
    Rectangle rec;
    Triangle tri;
    rec.setLength(5);
    rec.setWeight(7);
    cout << "Total Rectangle is " << rec.getArea() << endl;
    tri.setLength(5);
    tri.setWeight(7);
    cout << "Totak Triangle is " << tri.getArea() << endl;
    return 0;
}