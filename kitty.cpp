

#include <iostream>
using namespace std;
void happyNumber(int num) {
    if (num > 100000 || num<999999) {
        int a[6];
        for (int i = 0; i < 6; i++) {
            a[i] = num % 10;
            num = num / 10;
        }
        bool flag = false;
        for (int i = 0; i < 3; i++) {
            if (a[i] == a[5 - i]) flag = true;
            else {
                cout << "no";
                break;
            }
        }
        if (flag) cout << "yes";
    }
    else {
        cout << "not correct number";
    }
}
void searching(int mas[], int key,const int lenght) {
    bool flag = true;
    for (int i = 0; i < lenght; i++) {
        if (mas[i] == key) {
            cout << "found " << i;
            flag = false;
            break;
        }
    }
    if (flag) cout << "not found";
}
int main()
{
    setlocale(LC_ALL, "rus");
   /* int number;
    cin >> number;
    happyNumber(number);*/
    const int A = 10;
    int array[A]{ 12,32,4,45,23,1,2,3,43,4343 };
    int item = 28;
    searching(array, item, A);


}
