#include <iostream>

using namespace std;

class Shape {
    public:
        void setWidth(int w){
        width = w;
    }
        void setHeight(int h){
        height = h;
    }
    protected:
    int width;
    int height;
};

class PaintCost{
    public:
    int getCost(int area){
        return area*70;
    }
};

class Rectangle: public Shape, public PaintCost{
    public:
    int getArea(){
        return (width*height);    
    }
};

int main(){
    Rectangle Rect;
    Rect.setHeight(19);
    Rect.setWidth(20);
    int area = Rect.getArea();
    cout << "Area: " << area << endl;
    cout << "Cost: " << Rect.getCost(area) << endl;
    return 0;
}