#include <iostream>
using namespace std;

class Box{
    public:
        void setLength(double len){
            length = len;
        }
        void setWeight(double wei){
            weight = wei;
        }
        void setHeight(double hei){
            height = hei;
        }
        void setBox(double len, double wei, double hei){
            length = len;
            weight = wei;
            height = hei;
        }
        void printBox(){
            cout << "Length: " << length << endl;
            cout << "Weigth: " << weight << endl;
            cout << "Height: " << height << endl;
        }
        Box operator+(const Box& b){
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


int main(){
    Box box1;
    Box box2;
    Box box3;
    box1.setBox(1.0, 2.0, 5.5);
    box2.setBox(3.0, 4.8, 3.1);
    box3 = box1 + box2;
    cout << "box1: " << endl;
    box1.printBox();
    cout << "box2: " << endl;
    box2.printBox();
    cout << "box3: " << endl;
    box3.printBox();


}

