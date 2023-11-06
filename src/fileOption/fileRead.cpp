#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    try
    {
        ifstream fin("test.txt", ios::in);
        if (!fin)
        {
            throw "File open error.";
        }
        string str;
        while (getline(fin, str))
        {
            cout << str << endl;
        }
        fin.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}