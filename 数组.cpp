#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n[10];
    for(int i = 0; i < 9; i++){
        n[i] = i + 100;
    }
    cout << "Element" << setw(13) << "Value" << endl;
    for(int j = 0; j < 9; j++){
        cout << setw(7) << j << setw(13) << n[j] << endl;
    }
    return 0;
}