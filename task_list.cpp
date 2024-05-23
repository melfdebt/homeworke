// task_list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <string.h>
#include <Windows.h>
#include <fstream>
using namespace std;

string path = "melissa.txt";


 int strNum(string path) {
        int count = 0;
        ifstream in(path);
        if (in.is_open()) {
            string str;
            while (getline(in, str)) {
                count++;
            }
        }
        in.close();
        return count;
 }

void readFile(string * &array, int& size) {
        size = strNum(path);
        array = new string[size];
        if (size > 0) {
            ifstream in(path);
            if (in.is_open()) {
                int index = 0;
                string str;
                while (getline(in, str)) {
                    array[index] = str;
                    index++;
                }
            }
            in.close();
        }
}

void showTasks(string * arr, int size) {
        ifstream in(path);
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ". " << arr[i] << endl;
        }
        in.close();
}

void deleteTask(string* &array, int index,int &size) {
        index--;
        string* buf = new string[size-1];
        for (int i = 0; i<size; i++) {
            if (i < index) buf[i] = array[i];
            else if (i == index)continue;
            else buf[i - 1] = array[i];
        }
        delete[] array;
        array = buf;
        size--;
}

void addTask(string * &arr, int& size, string str) {
        string* buf = new string[size + 1];
        for (int i = 0; i < size; i++) {
            if (size == 0) break;
            buf[i] = arr[i];
        }
        buf[size++] = str;
        delete[]arr;
        arr = buf;
}



void saveFile(string* &array,int size) {
    ofstream out(path);
    if (out.is_open()) out << array[0] << endl;
    out.close();
    ofstream app(path, ios::app);
    if (app.is_open()) {
        for (int i = 1; i < size; i++) {
            app << array[i] << endl;
        }
    }
    app.close();
}

void deleteAll(string*& array, int& size) {
    delete[] array;
    size = 0;
}



int main()
{

   setlocale(LC_ALL, "rus");


   int choice;
   string* array = new string[strNum(path)];
   int size = strNum(path);
   bool flag = true;
   while (flag) {
       cout << "enter 1 to append task in list\n2 to delete one task\n3 to delete all tasks\n4 to look at list\n5 to close program" << endl;
       cout << "your choise: ";
       cin >> choice;
       switch (choice) {
       case 1:
       {
           readFile(array, size);
           showTasks(array, size);
           string text;
           cout << "enter your task" << endl;
           while (text=="")getline(cin, text);
           addTask(array, size, text);
           cout << "element appended" << endl;
           Sleep(1000);
           saveFile(array, size);
           system("cls");
           break;
       }
       case 2:
       {
           readFile(array, size);
            showTasks(array,size);
            int index;
            cout << " enter task you like to delete: ";
            cin >> index;
            deleteTask(array, index,size);
            cout << "task deleted" << endl;
            Sleep(1000);
            saveFile(array, size);
            system("cls");
            break;
       }
       case 3:
       {
           cout << "are you sure that you want to delete all tasks?(yes/no)" << endl;
           string answer;
           while (answer == "") getline(cin, answer);
           if (answer == "yes" or answer=="yes ") {
               deleteAll(array,size);
               saveFile(array, size);
               Sleep(1000);
               system("cls");
               break;
           }
           else {
               system("cls");
               break;
           }
       }
       case 4:
       {
           showTasks(array, size);
           string str;
           cout << "enter 'stop' or 'close' to close list"<<endl;
           while (str == "") getline(cin, str);
           system("cls");
           break;
       }
       case 5:
           flag = false;
       default:
           system("cls");
           break;
       }
   }
   cout << "list saved" << endl;

}
