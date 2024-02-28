// roksberg.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    //1
    int num, a, b, count, count1;
    cin >> num;
    if (num >= 1000000 || num < 100000) cout << "error";
    
    else{
    
        count = 0;
        count1 = 0;
        for (int i = 100000; i != 100; i /= 10) {
            a = num / i;
            count += a;
            num -= a * i;
        for (int i = 100; i != 0; i /= 10) {
        }
            b = num / i;            count1 += b;
            num -= b * i;
        }
        cout << ((count == count1) ? "счастливое число" : "нет");

    }
    //2
   int n, first = 0, last = 0, count = 0;

    cin >> n;
    for (int i = 1000; n > 0; i /= 100) {
    if (n>1000 && n<10000){
            first = n / i;
            n -= first*i;
            last = n / (i / 10);
            n -= last*(i/10);
            swap(first, last);
            count += (first * i) + (last * (i / 10));
        }
        else cout<<"error";
    }
    cout << count;
    //3 97-103
    int a, count = 0;
    cin >> a ;
    for (int i = 1; i < 7; i++) {
        cin >> a;
        if (a > count) count = a;
    }
    cout << count;
    //4
    float sab, sbc, m,pass=0,oil=0,need=0;
    cin >> sab >> sbc >> m;
    if (m < 2000 && m >= 0 ) {
        if (m < 500) pass = 1;
        else if (m >= 500 && m < 1000) pass = 4;
        else if (m >= 1000 && m < 1500) pass = 7;
        else if (m >= 1500 && m < 2000) pass = 9;
        if (pass * sab > 300 || pass * sbc > 300) cout << "error";
        else {
            oil = 300 - (pass * sab);
            need = sbc * pass;
            if (oil <= need) {
                need = need - oil;
                cout << need;
            }
            else if (oil > need)cout << "достаточно топлива";
        }
    }
    else cout << "перегруз";
    

    

}


