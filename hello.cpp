#include <iostream>
#include <cstdlib>
#include <ctime>


int main() {
    srand(time(0));  // 设置种子，确保每次运行生成不同的随机数

    int secretNumber = rand() % 100 + 1;  // 生成 1 到 100 之间的随机数
    int guess;
    int attempts = 0;

    std::cout << "欢迎参加猜数字游戏！" << std::endl;

    while (true) {
        std::cout << "请输入一个猜测的数字：";
        std::cin >> guess;

        attempts++;

        if (guess == secretNumber) {
            std::cout << "恭喜你猜对了！你总共猜了 " << attempts << " 次。" << std::endl;
            break;
        } else if (guess < secretNumber) {
            std::cout << "太小了，请再猜一次。" << std::endl;
        } else {
            std::cout << "太大了，请再猜一次。" << std::endl;
        }
    }

    return 0;
}