// roksberg.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    //1
   /* int sec,hours,min;
    cin >> sec;
    hours = sec / 3600;
    sec = sec - (hours * 3600);
    min = sec / 60;
    sec = sec - (min * 60);
    cout << hours << ":" << min << ":" << sec;*/
    //2
    /*float n;
    int dollars, cents;
    cin >> n;
    dollars = n ;
    n=n*100;
    cents = n - (dollars * 100);
    cout << dollars << " долларов " << cents << " центов";*/
    //3
   /* int days, weeks;
    cin >> days;
    weeks = days / 7;
    days = days - (weeks * 7);
    cout << weeks << " weeks " << days << " days";*/
    //4
    cout << "Calculating running speed.";
    float distance, time, speed;
    int seconds, min,sec;
    cout << "Enter the length of distance(meters) = ";cin >> distance;
    cout << "Enter time(min.sec) ="; cin >> time;
    cout << "distance: " << distance << "m"<<endl;
    min = time;
    sec = (time - min) * 100;
    seconds = min * 60 + sec;
    cout << "time: " << min << "min" << sec << "sec = " << seconds <<"seconds"<< endl;
    distance = distance / 1000;
    time = seconds / 3600;
    speed = distance / time;
    cout << "You were running at speed " << speed;
}


