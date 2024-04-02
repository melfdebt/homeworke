

#include <iostream>
using namespace std;

void ss(int num, int sistem) {
    if (sistem < 10) {
        int result = 0,count=1;
        while (num % sistem != 0) {
            result += num % sistem * count;
            num /= sistem;
            count *= 10;
        }
        cout << result;
    }
    else {
        char result = 'A';
        int a = 0;
        int count = 1;
        char list[36];
        int i = -1;
        bool flag = false;
        while (num % sistem != 0) {
            i++;
            char result = 'A';
            a = num % sistem;
            num /= sistem;
            if (a >= 10 or (num >= 10 and num < sistem)) { list[i] =result+( a - 10); }
            else {
                a = a * count;
                count *= 10;
                flag = true;
            }
        }
        if (flag) {
            cout << a;
            i--;
        }
        for (int e = i; e >= 0;e--) {
            cout << list[e];
        }
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    ss(125, 16);

  


}
