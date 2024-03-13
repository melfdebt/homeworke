// roksberg.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    //1
    //int massive[5],max=massive[0], min =0;
    //srand(time(NULL));
    //for (int i = 0; i < 5; i++) {
    //    massive[i] = rand();
    //    cout << massive[i] << endl;
    //}
    //min = massive[0];
    //for (int i = 0; i < 5; i++) {
    //    if (max < massive[i]) max = massive[i];
    //    if (min > massive[i]) min = massive[i];
    //}
    //cout << max <<" "<< min;
    //2
  /*  int array[10], min, max;
    cin >> min >> max;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        array[i] = min + rand() % (max - min + 1);
        cout << array[i] << " ";
    }
    int n,count=0;
    cin >> n;
    for (int i = 0; i < 10; i++) {
        if (array[i] < n)count += array[i];
    }
    cout << endl<<count;*/
    //3
    /*int profit[12],mounth;
    for (int i = 0; i < 12; i++) {
        cin >> mounth;
        profit[i] = mounth;
    }
    int a, b,min,max;
    cout << "введите диапазон:";
    cin >> a >> b;
    min = profit[a-1];
    max = profit[0];
    for (int i = 0; i < 12; i++) {
        cout << profit[i] << endl;
        if (i>a && i<b && max < profit[i]) max = profit[i];
        if (i > a && i<b && min > profit[i]) min = profit[i];
    }
    cout << min <<" " << max;*/
    //4
    const int N = 5;
    float array[N]{1.2,-34.4,356.67,45.0,-34.6}, a, count = 0;
    for (int i = 0; i < N; i++) {
     /*   cin >> a;
        array[i] = a;*/
        if (array[i] < 0)count += array[i];//сумма отрриц. чисел
    }
    cout <<" Суммa отрицательных элементов." << count << endl;
    int indmin, indmax;
    for (int i = 1; i < N; i++) {
        if (array[i] > array[i - 1]) indmax = i;
    }
    for (int i = 1; i < N; i++) {
        if (array[i] < array[i - 1])indmin = i;
    }
    if (indmax < indmin) swap(indmax, indmin);
    float pois=1.0;
    for (int i = indmin ; i < indmax+1; i++) {
        pois *= array[i];//произведение от мин до макс
    }
    cout <<" Произведение элементов, находящихся между min и max элементами." << pois << endl;
    float fourth=1;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 1)continue;
        else fourth *= array[i];//произведение с четными номерами
    }
    cout <<" Произведение элементов с четными номерами" << fourth << endl;
    int indfirst=0, indlast=0;
    for (int i = 0; i < N; i++) {
        if (array[i] < indfirst) {
            indfirst = i;
            break;
        }
    }
    for (int i = N - 1; i > indfirst; i--) {
        if (array[i] < indlast) {
            indlast = i;
            break;
        }
    }
    float sum=0;
    for (int i = indfirst+1; i < indlast; i++) {
        sum += array[i];//Сумма элементов, находящихся между первым и последним отрицательными элементами.
    }
    cout <<" Суммa элементов, находящихся между первым и последним отрицательными элементами." << sum;
}


