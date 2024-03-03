// roksberg.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
   //1
    int a,count=0;
    cin >> a;
    for (int i = a; i <= 500; i++) {
        count += i;
    }
    cout << count;
    //2
    int x, y;
    cin >> x >> y;
    cout << pow(x, y);
    //3
    float count = 0;
    for (int i = 1; i <= 1000; i++) {
        count += i;
    }
    cout << count / 998;
    //4
    int a, count = 1;
    cin >> a;
    for (int i = a; a <= 20; i++) {
        count *= i;
    }
    //5
    int k;
    cin >> k;
    for (int i = 1; i < 11; i++) {
        cout << k << "*" << i << "=" << k * i << endl;
    }
    

}


