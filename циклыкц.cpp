// roksberg.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    //1
   /*int a, count = 0, kolvo = 0, zeros = 0;
    cin >> a;//1673
    for (int i = 10; a > 0; i *= 10) {
        count += (a % i)/(i/10);
        if ((a % i) / (i / 10) == 0) zeros++;
        a =a-(( a % i));
        kolvo++;
    }
    cout << "сумма цифр: "<<count << endl;
    cout << "среднее арифметическое цифр: "<<(float)count / (float)kolvo << endl;
    cout <<"кол-во нулей: "<< zeros << endl;*/
    //2
    // а как что? я воооблще не поняла что надо сделать
    // 3 заказ в ресторане
    int visitors,a,count=0,check=0;
    cin >> visitors;
    for (int i = 0; i < visitors; i++) {
        cout << "1-вода: 100руб" << endl;
        cout << "2-чай: 150руб" << endl;
        cout << "3-паста с морепродуктами: 1000руб" << endl;
        cout << "4-стейк: 1500руб" << endl;
        cout << "5-роллы: 1000руб" << endl;
        cout << "6-меренговый рулет: 150руб" << endl;
        cout << "7-мороженное: 100руб" << endl;
        cout << "8-торт: 200руб" << endl;
        do {
            cin >> a;
            if (a == 0) continue;
            else if (a == 1 || a == 7) count += 100;
            else if (a == 2 || a == 6) count += 150;
            else if (a == 3 || a == 5) count += 1000;
            else if (a == 4) count += 1500;
            else if (a == 8) count += 200;
            else cout << "error";
        } while (a != 0);
        check += count;
    }
    cout << check;
    //4 вывести поле морского боя
    //int x=10;
    //char letter=353;//353-378
    //for (int i = 0; i < 10; i++) {
    //    letter = 353;
    //    for (int f = x; f >= 1; f--) {
    //        cout << letter++ << i<<" ";
    //    }
    //    cout << endl;
    //}



}


