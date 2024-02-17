// roksberg.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    //1
    float r0,r1,r2,r3;
    cin >> r1; cin >> r2; cin >> r3;
    r0 = 1 / (1 / r1 + 1 / r2 + 1 / r3);
    cout << r0;
     //2
    const float PI = 3.14;
    float l,s,r;
    cin >> l;
    r = l /( 2 * PI);
    s = PI * pow(r, 2);
    cout << s;
    //3
    float v, t, a, s;
    cin >> v; cin >> t; cin >> a;
    s = v * t + (a * pow(t, 2))/ 2;
    cout << s;

}


