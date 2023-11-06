#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // 操作文件的三大类：
    // ofstream: 写文件。
    // ifstream: 读文件。
    // fstream: 读写文件。

    // 打开文件。
    // ofstream fout("test.txt"); // 默认打开模式为out，即写文件。
    // ofstream fout("test.txt", ios::out); // 打开模式为out，即写文件。
    // ofstream fout("test.txt", ios::in); // 打开模式为in，即读文件。
    // ofstream fout("test.txt", ios::app); // 打开模式为app，即在文件末尾追加内容。
    // ofstream fout("test.txt", ios::ate); // 打开模式为ate，即打开文件后定位到文件末尾。
    // ofstream fout("test.txt", ios::trunc); // 打开模式为trunc，即打开文件前将文件清空。
    // ofstream fout("test.txt", ios::binary); // 打开模式为binary，即以二进制方式打开文件。
    try
    {
        ofstream fout("test.txt", ios::app);
        cout << fout.is_open() << endl;
        if (!fout)
        {
            throw "File open error.";
        }
        for (int i = 0; i < 10; i++)
        {
            fout << "Hello world." << endl;
        }

        fout.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}