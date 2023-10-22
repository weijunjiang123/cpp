#include <iostream>

using namespace std;

class Box
{

public:
    Box(double h, double w, double l) : height(h), weight(w), length(l){};
    Box() : height(0), weight(0), length(0){};
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
        cout << "height: " << height << " ";
        cout << "weight: " << weight << " ";
        cout << "length: " << length<< endl;
    }

    Box &operator++(int)
    {
        this->height++;
        this->weight++;
        this->length++;
        return *this;
    }

    Box &operator++()
    {
        this->height++;
        this->weight++;
        this->length++;
        return *this;
    }

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