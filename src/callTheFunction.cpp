#include <iostream>

using namespace std;

int maxNumber(int num1, int num2);

int main()
{
    int num1;
    int num2;
    cout << "input a number : ";
    cin >> num1;
    cout << "input another number : ";
    cin >> num2;
    cout << "the large number is : " << maxNumber(num1, num2);
    return 0;
}

int maxNumber(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}