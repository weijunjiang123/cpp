#include <iostream>
using namespace std;

int binSearch(int *addr, int len, int target)
{
    int low = 0;
    int high = len - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (addr[mid] == target)
        {
            return mid;
        }
        else if (addr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1; // not found
}

int main()
{
    int addr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int p = binSearch(addr, 10, 11);
    cout << p << endl;
}
