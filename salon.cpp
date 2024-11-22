// salon.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>
#include <set>
#include <string>
#include <Windows.h>
using namespace std;
struct Auto {
    string name, motor;
    int year;
    float price;
    Auto() {};
    Auto(string name, string motor, int year, float price):name(name),motor(motor),year(year),price(price){}
};

void print(Auto* machine) {
    if (machine == nullptr) {
        cout << "not found" << endl;
        return;
    }
    cout << machine->name << endl << "motor: " << machine->motor << endl << "year: " << machine->year << endl << "price: " << machine->price << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

Auto* toArray(set<Auto*> mashins) {
    Auto* arr = new Auto[mashins.size()];
    int i = 0;
    for (Auto* it : mashins)
    {
        arr[i] = *it;
        i++;
    }
    return arr;
}
void show(set<Auto*> mashins) {
    if (mashins.empty()) {
        cout << "shop is empty" << endl;
        return;
    }
    for (Auto* it : mashins) {
        print(it);
    }
}
set<Auto*> toSet(Auto* arr,int size) {
    set<Auto*> a;
    for (int i = 0; i < size; i++) {
        Auto* v = new Auto(arr[i].name, arr[i].motor,arr[i].year,arr[i].price);
        a.insert(v);
    }
    return a;
}
set<Auto*> sortPrice(set<Auto*> mashins) {
    Auto* arr = toArray(mashins);
    for (int i = 0; i < mashins.size(); i++) {
        for (int e = 1; e < mashins.size(); e++) {
            if (arr[e].price < arr[e - 1].price) {
                swap(arr[e], arr[e - 1]);
            }
        }
    }
    return toSet(arr, mashins.size());
}


set<Auto*> sortYear(set<Auto*> mashins) {
    Auto* arr = toArray(mashins);
    for (int i = 0; i < mashins.size(); i++) {
        for (int e = 1; e < mashins.size(); e++) {
            if (arr[e].year > arr[e - 1].year) {
                swap(arr[e], arr[e - 1]);
            }
        }
    }
    return toSet(arr, mashins.size());
}

Auto* find(string name, string motor, int year, set<Auto*> mashins) {
    for (Auto* it : mashins) {
        if (it->name == name && it->motor == motor && it->year == year) {
            return it;

        }
    }
    return nullptr;
}

void buy(Auto* avto, set<Auto*>& machins, float& budget) {
    budget += avto->price;
    machins.erase(avto);
    
}
//function buy()
int main()
{
    set<Auto*> autos;
    float budget = 1000000;
    bool salon = true;
    while (salon) {
        cout << "1. choose auto" << endl;//fdfd
        cout << "2. find your auto" << endl;//kdfjdf
        cout << "3. sell auto" << endl;//nsdksjds
        cout << "4. exit" << endl;//jkd
        cout << "enter: ";
        int num;
        cin >> num;
        system("cls");
        switch (num)
        {
        case 1:
        {
            cout << "1.show all" << endl;//lsfld
            cout << "2.filter by price" << endl;//skjdsd
            cout << "3.filter by year" << endl;//jdkfjd
            cout << "4.exit" << endl;//fdlf
            int num2;
            cout << "enter: ";
            cin >> num2;
            system("cls");
            switch (num2)
            {
            case 1: {
                show(autos);
                string str;
                cout << "if you want to buy a car, input 'buy'" << endl;
                while (str=="") {
                    getline(cin, str);
                }
                if (str == "buy") {
                    string name, motor;
                    int year;
                    cout << "enter name: ";
                    cin >> name;
                    cout << "enter motor: ";
                    cin >> motor;
                    cout << "enter year: ";
                    cin >> year;
                    print(find(name, motor, year, autos));
                    cout << "are you sure?" << endl;
                    string str1;
                    while (str1 == "") {
                        getline(cin, str);
                    }
                    if (str1 == "Yes" || str1 == "yes") {
                        buy(find(name, motor, year, autos),autos,budget);
                    }
                }
                system("cls");
                break;
            }
            case 2:
            {
                show(sortPrice(autos));
                string str;
                while (str == "") {
                    getline(cin, str);
                }
                if (str == "buy") {

                }
                system("cls");
                break;
            }
            case 3:
            {
                show(sortYear(autos));
                string str;
                while (str == "") {
                    getline(cin, str);
                }
                if (str == "buy") {

                }
                system("cls");
                break;
            }
            default:
                system("cls");
                break;
            }
            break;
        }
        case 2:
        {
            string name, motor;
            int year;
            cout << "enter name: ";
            cin >> name;
            cout << "enter motor: ";
            cin >> motor;
            cout << "enter year: ";
            cin >> year;
            print(find(name, motor, year, autos));
            string str;
            while (str == "") {
                getline(cin, str);
            }
            if (str == "buy") {
                cout << "are you sure?" << endl;
                string str1;
                while (str1 == "") {
                    getline(cin, str);
                }
                if (str1 == "Yes" || str1 == "yes") {
                    buy(find(name, motor, year, autos), autos, budget);
                }
            }
            system("cls");
            break;
        }
        case 3:
        {
            cout << "enter some characteristics of auto you'd like to sell" << endl;
            string name, motor;
            int year;
            float price;
            cout << "enter name: ";
            cin >> name;
            cout << "enter motor: ";
            cin >> motor;
            cout << "enter year: ";
            cin >> year;
            cout << "enter your price:";
            cin >> price;
            if (price > 0.6 * budget) {
                cout << "it's too expensive" << endl;
                cout << "our company can't buy your auto" << endl;
                Sleep(2000);
            }
            else {
                Auto* a = new Auto(name, motor, year, price + 0.2 * price);
                autos.insert(a);
            }
            system("cls");
            break;
        }
        case 4:
        {
            autos.clear();
            system("cls");
            salon = false;
            break;
        }
        default:
            system("cls");
            break;
        }
    }
    
}

