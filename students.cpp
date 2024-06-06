// students.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> 
#include <Windows.h> 
#include <string> 
#include <string.h> 
#include <fstream> 
#define random(min, max) min + rand() % (max - min + 1) 

using namespace std;

int CURRENT_ID = 1;
struct Student {
    int id;
    string name;
    int age;
    float AVG;
};

Student createStudent(string name, int age, float avg) {
    return Student{ CURRENT_ID++,name,age ,avg };
}

void print(Student student) {
    cout << "ID: " << student.id << "\nName: " << student.name << "\nAge: " << student.age <<
        "\nAVG: " << student.AVG << "\n\n";
}

void printAll(Student* students, int size) {
    cout << "Students info: \n";
    for (int i = 0; i < size; i++) print(students[i]);
}

void addStudent(Student*& students, int& size, Student st) {
    Student* buf = new Student[size + 1];
    for (int i = 0; i < size; i++)
    {
        buf[i] = students[i];
    }
    buf[size++] = st;
    delete[] students;
    students = buf;
}

int find(Student* students, int size, int id) {
    for (int i = 0; i < size; i++)
    {
        if (students[i].id == id) return i;
    }
    return -1;

}

void showStudentByIndex(Student*& students, int index) {
    print(students[index]);
}


void changeStudent(Student* students, int index) {
    print(students[index]);
    cout << "1. Изменить имя." << endl;
    cout << "2. Изменить возраст." << endl;
    cout << "3. Изменить средний балл." << endl;
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        string name;
        cout << "Введите имя: ";
        cin >> name;
        students[index].name = name;
        break;
    }
    case 2:
    {
        int age;
        cout << "Введите возраст: ";
        cin >> age;
        students[index].age = age;
        break;
    }
    case 3:
    {
        float AVG;
        cout << "Введите средний балл: ";
        cin >> AVG;
        students[index].AVG = AVG;
        break;
    }
    default:
        cout << "Incorrect number choice" << endl;
    }
}


void TopTenStudents(Student* students, int size) {
    bool flag = false;
    for (int i = 0; i < size; i++) {
        for (int e = 0; e < size; e++) {
            if (students[e].AVG < students[e + 1].AVG) {
                swap(students[e + 1], students[e]);
                flag = true;
            }
        }
        if (flag = false) break;
    }
    (size >= 10) ? size = 10 : size = size;
    for (int i = 0; i < size; i++) {
        print(students[i]);
    }
}

void deleteStudentById(Student*& students, int& size, int id) {
    int index = find(students, size, id);
    if (index != -1) {
        Student* buf = new Student[size - 1];
        for (int i = 0; i < index; i++)
        {
            buf[i] = students[i];
        }
        for (int i = index + 1; i < size; i++)
        {
            buf[i - 1] = students[i];
        }
        delete[] students;
        students = buf;
        size--;
    }
    else cout << "Пользователь с таким id не найден." << endl;
}

string path = "melfdebt.txt";

void saveFile(Student* students, int size) {
    fstream in(path);
    if (in.is_open()) {
        for (int i = 0; i < size; i++) {
            in << students[i].id << ";" << students[i].name << ";" << students[i].age << ";" << students[i].AVG << endl;
        }
    }
    in.close();
}
int getstr() {
    ifstream in(path);
    string str;
    int count = 0;
    while (getline(in, str)) count++;
    return count;
}

Student strToStud(string data) {
    string stdata[3];
    data = data.substr(data.find(';') + 1, data.length());
    string str = "";
    for (int i = 0, int count = 0; i <= data.length(); i++)
    {
        if (data[i] == ';' or data[i] == '\n') {
            stdata[count++] = str;
            str = "";
        }
        else str += data[i];
    }
    return createStudent(stdata[0], stoi(stdata[1]), stof(stdata[2]));

}
Student* readStud(Student*& students, int size) {
    int size = getstr();
    Student* students = new Student[size];
    ifstream in(path);
    if (in.is_open()) {
        string str;
        while (getline(in, str)) {
            addStudent(students, size, strToStud(str));
        }
    }
    in.close();
    return students;
}



int main()
{
    setlocale(LC_ALL, "rus");
    int size = 3; Student* students = readStud(students,size);
    int choice; bool work = true;
    while (work) {
        cout << "1. Добавить нового студента." << endl;
        cout << "2. Удалить студента по ID." << endl;  cout << "3. Изменить данные студента." << endl;
        cout << "4. Вывести студента по ID." << endl;  cout << "5. Вывести топ учеников" << endl;
        cout << "9. Вывести всех студентов." << endl;  cout << "0. Выйти." << endl;
        cout << "Enter your choice: ";  cin >> choice;
        switch (choice) {
        case 1: {
            string name;   int age;
            float AVG;   cout << "Введите имя: ";
            cin >> name;   cout << "Введите возраст: ";
            cin >> age;   cout << "Введите средний балл: ";
            cin >> AVG;   addStudent(students, size, createStudent(name, age, AVG));
            cout << "Student added";   Sleep(1000);
            system("cls");   saveFile(students, size);
            break;
        }
        case 2:   int id;
            cout << "Введите id пользователя, которого хотите удалить: ";   cin >> id;
            deleteStudentById(students, size, id);   saveFile(students, size);
        break;  case 3:
        {
            int id;
            cout << "Введите id пользователя, которого хотите изменить: ";   cin >> id;
            int index = find(students, size, id);   if (index != -1) {
                changeStudent(students, index);    saveFile(students, size);
            }
            else cout << "Пользователь с таким id не найден.";
            Sleep(1000);   system("cls");
            break;
        }
        case 4: {
            int id;   cout << "Введите id пользователя: ";
            cin >> id;   int index = find(students, size, id);
            if (index != -1) {
                system("cls");
                showStudentByIndex(students, index);
            }
            else cout << "Пользователь с таким id не найден.";
            break;
        }
        case 5: {
            TopTenStudents(students, size);   string num;
            cout << "enter 0 to close" << endl;
            while (num == "") getline(cin, num);   system("cls");
            break;
        }
        case 9:   system("cls");
            printAll(students, size);   break;
        case 0:   saveFile(students, size);
            work = false;   break;

        default:   break;
        }
    }

}

