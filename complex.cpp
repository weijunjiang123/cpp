#include <iostream>
using namespace std;

class Complex
{
public:
    // 构造函数
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    // 析构函数
    ~Complex() {}

    // 重载运算符
    Complex operator+(const Complex &c2) const;
    Complex operator-(const Complex &c2) const;
    void display() const;

private:
    double real; // 复数实部变量
    double imag; // 复数虚部变量
};

// 重载+运算符，实现复数加法运算
Complex Complex::operator+(const Complex &c2) const
{
    return Complex(real + c2.real, imag + c2.imag);
}
// 重载-运算符，实现复数减法运算
Complex Complex::operator-(const Complex &c2) const
{
    return Complex(real - c2.real, imag - c2.imag);
}

void Complex::display() const
{
    cout << "(" << real << "," << imag << ")" << endl;
}

int main()
{
    Complex c1(5, 4), c2(2, 10), c3;
    cout << "c1 = ";
    c1.display();
    cout << "c2 = ";
    c2.display();
    c3 = c1 - c2; // 使用重载运算符完成复数减法
    cout << "c3 = c1 - c2 = ";
    c3.display();
    c3 = c1 + c2; // 使用重载运算符完成复数加法
    cout << "c3 = c1 + c2 = ";
    c3.display();
    return 0;
}