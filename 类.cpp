#include <iostream>

using namespace std;

// 基类Shape，定义了两个变量width和height，以及两个函数setWidth()和setHeight()
class Shape
{
public:
    // 构造函数:在对象创建时执行
    Shape(int w = 0, int h = 0) : width(w), height(h){};

    // 析构函数:在对象销毁时执行
    ~Shape(){};

    void setWidth(int w)
    {
        width = w;
    }

    void setHeight(int h)
    {
        height = h;
    }

protected:
    int width;
    int height;
};

// 基类PaintCost，定义了一个函数getCost()
class PaintCost
{
public:
    int getCost(int area)
    {
        return area * 70;
    }
};

// 派生类Rectangle，继承了基类Shape和PaintCost
class Rectangle : public Shape, public PaintCost
{
public:
    int getArea()
    {
        return (width * height);
    }
};

int main()
{
    Rectangle Rect;
    Rect.setWidth(5);
    Rect.setHeight(7);
    int area = Rect.getArea();
    cout << "Area: " << area << endl;
    cout << "Cost: " << Rect.getCost(area) << endl;
    return 0;
}