#include <iostream>
#include <vector>

using namespace std;
// vector: 类似于数组，但是支持动态扩容，存储类型可以是任意类型。
int main()
{
    // 构造一个int类型的vector对象。
    vector<int> v = {1, 2, 3, 4, 5};
    // vector<int>::iterator it; // 迭代器，用于遍历vector中的元素。
    vector<int>::iterator it;
    it = v.begin(); // 指向第一个元素。
    // 在vector的尾部插入一个元素。
    v.push_back(1);
    v.push_back(2);
    v.pop_back(); // 删除尾部元素。

    v.insert(it, 3); // 在it指向的位置插入元素3。

    int sum = 0;
    // 遍历vector中的元素。auto关键字可以自动推导类型。
    for (int i = 0; i < v.size(); i++)
    {
        // 在vector中，可以使用下标访问元素。
        sum += v[i];
    }
    int average = sum / v.size();
    cout << "average = " << average << endl;
}
