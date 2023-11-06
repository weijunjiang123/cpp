#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class SmartPrinter
{
public:
    explicit SmartPrinter(T *prt = nullptr) : prt_(prt){};
    SmartPrinter(const SmartPrinter &sp) : prt_(sp.prt_) {}
    ~SmartPrinter() { delete prt_; };
    T *get() const { return prt_; }
    SmartPrinter &operator=(const SmartPrinter &sp)
    {
        if (this != &sp)
        {
            delete prt_;
            prt_ = sp.prt_;
        }
        return *this;
    }
    T &operator*() const { return *prt_; }
    T *operator->() const { return prt_; }

private:
    T *prt_;
};

template <typename T>
class UniquePrinter : public SmartPrinter<T>
{
public:
    explicit UniquePrinter(T *prt = nullptr) : prt_(prt){};
    UniquePrinter(const UniquePrinter &sp) = delete;
    ~UniquePrinter() { delete prt_; };
    T *get() const { return prt_; }
    UniquePrinter &operator=(const UniquePrinter &sp) = delete;
    T &operator*() const { return *prt_; }
    T &operator->() const { return prt_; }

private:
    T *prt_;
};

class Shap
{
public:
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;

private:
    int height;
    int width;
};

class Triangle : public Shap
{
public:
    Triangle(int height, int width) : height(height), width(width){};
    double getArea() override { return height * width / 2; }
    double getPerimeter() override { return height + width + sqrt(height * height + width * width); }

private:
    int height;
    int width;
};

class Rectangle : public Shap
{
public:
    Rectangle(int height, int width) : height(height), width(width){};
    double getArea() override { return height * width; }
    double getPerimeter() override { return 2 * (height + width); }

private:
    int height;
    int width;
};

int main()
{
    cout << "SmartPrinter:" << endl;
    SmartPrinter<Shap> sp(new Triangle(3, 4));
    SmartPrinter<Shap> sp2(sp);
    SmartPrinter<Shap> sp3(new Rectangle(3, 4));
    cout << "Area: " << sp->getArea() << endl;
    cout << "Perimeter: " << sp->getPerimeter() << endl;
    cout << "Area: " << sp3->getArea() << endl;
    cout << "Perimeter: " << sp3->getPerimeter() << endl;
    cout << "UniquePrinter:" << endl;
    UniquePrinter<Shap> up(new Triangle(3, 4));
    UniquePrinter<Shap> up2(new Rectangle(3, 4));
    // UniquePrinter<Shap> up3(up);
    cout << "Area: " << up->getArea() << endl;
    cout << "Perimeter: " << up->getPerimeter() << endl;
    cout << "Area: " << up2->getArea() << endl;
    cout << "Perimeter: " << up2->getPerimeter() << endl;
    // cout << "Area: " << up3->getArea() << endl;
    return 0;
}