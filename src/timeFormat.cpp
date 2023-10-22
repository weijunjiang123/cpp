#include <iostream>
#include <ctime>

using namespace std;

int main(){
    // 基于当前系统的当前日期/时间
    time_t now = time(0);

    cout << "Number of sec since January 1,1970: " << now << endl;

    // 输出 tm 结构的各个组成部分
    tm* ltm = localtime(&now);
    cout << "Year: " << 1900 + ltm->tm_year << endl;
    cout << "Month: " << 1 + ltm->tm_mon << endl;
    cout << "day: " << ltm->tm_mday << endl;
    cout << "Time: "<< 1 + ltm->tm_hour << ":";
    cout << 1 + ltm->tm_min << ":";
    cout << 1 + ltm->tm_sec << endl;
}