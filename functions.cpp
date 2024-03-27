

#include <iostream>
using namespace std;
double mypow(float num1,float num2) {//возведение числа в степень
    double num = 1;
    for (int i = 0; i < num2; i++) {
        num*= num1;
    }
    return num;
}
int summaInDiap(int num1, int num2) {//сумма чисел в их диапазоне
    if (num1 > num2) swap(num1, num2);
    int summa = 0;
    for (int i = num1; i < num2 + 1; i++) {
        summa += i;
    }
    return summa;
}
int main()
{
    setlocale(LC_ALL, "rus");
    float num1, num2;
    cin >> num1 >> num2;
    cout << mypow(num1, num2)<<endl;//результат степени
    cout << summaInDiap(num1, num2);//результат суммы


}
