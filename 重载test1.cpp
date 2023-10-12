#include <iostream>

using namespace std;

class Box{

    public:
    double getVolume(void){
        return height * weight * length;
    }

    void setHeight(double h){
        height = h;
    }

    void setWeight(double w){
        weight = w;
    }

    void setLength(double l){
        length = l;
    }

    Box operator+(Box& b){
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

int main(){
    Box box1;
    Box box2;
    Box box3;

    double volume = 0.0;

    box1.setHeight(1.0);
    box1.setWeight(2.0);
    box1.setLength(3.0);

    box2.setHeight(4.0);
    box2.setLength(5.0);
    box2.setWeight(6.0);

    box3 = box1 + box2;
    volume =  box3.getVolume();
    cout << "volume of box3 is: " << volume << endl; 

    return 0;
}