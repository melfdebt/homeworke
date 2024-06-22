// store2.0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include<string.h>
#include<Windows.h>
#include <fstream>
using namespace std;

string path = "melfdebt.txt";
int ID = 1;

enum ProductCategory {
    CLOTHES,//
    HOUSE,//
    HEALTH,//
    TECHNIC,//
    PRESENT,//
    SPORT,//
    CAR,//
    FOR_KIDS,//
    NUTRITIONAL_PRODUCTS,//
    EQUIPMENT//
};

struct Product {
    string name;
    ProductCategory category;
    float price;
    int quantity;
    int ID;
};

struct Shop {
    Product* products;
    int titleQuantity;
};

ProductCategory intToCategory(int cat) {
    switch (cat)
    {
    case 0:
        return ProductCategory::CLOTHES;
    case 1:
        return ProductCategory::HOUSE;
    case 2:
        return ProductCategory::HEALTH;
    case 3:
        return ProductCategory::TECHNIC;
    case 4:
        return ProductCategory::PRESENT;
    case 5:
        return ProductCategory::SPORT;
    case 6:
        return ProductCategory::CAR;
    case 7:
        return ProductCategory::FOR_KIDS;
    case 8:
        return ProductCategory::NUTRITIONAL_PRODUCTS;
    case 9:
        return ProductCategory::EQUIPMENT;
    default:
        break;
    }
}

string CategoryToString(ProductCategory category) {
    switch (category)
    {
    case CLOTHES:
        return "clothes, shoes, accessories";
    case HOUSE:
        return "house and garden";
    case HEALTH:
        return "beauty and health";
    case TECHNIC:
        return "technic and electronics";
    case PRESENT:
        return "presents, hobbies, books";
    case SPORT:
        return "sport and rest";
    case CAR:
        return "сars";
    case FOR_KIDS:
        return "products for kids";
    case NUTRITIONAL_PRODUCTS:
        return "nutritional products and drinks ";
    case EQUIPMENT:
        return "equipment and products for the provision of services";
    default:
        break;
    }
}

bool checkProduct(Shop shop, Product product) {
    for (int i = 0; i < shop.titleQuantity; i++)
    {
        if (shop.products[i].name == product.name) return false;
    }
    return true;
}

Product createProduct(string name, ProductCategory category, float price, int quantity) {
    Product prod{ name,category,price,quantity,ID++};
    return prod;
}

Product createProduct(string name, ProductCategory category, float price, int quantity, int id) {
    Product prod{ name,category,price,quantity,id };
    ID = ++id;
    return prod;
}

void addProduct(Shop& shop, Product product) {
    if (checkProduct(shop, product) == true) {
        if (shop.titleQuantity > 0) {
            Product* buf = new Product[shop.titleQuantity + 1];
            for (int i = 0; i < shop.titleQuantity; i++) {
                buf[i] = shop.products[i];
            }
            buf[shop.titleQuantity] = product;
            delete[] shop.products;
            shop.products = buf;
            shop.titleQuantity++;
            cout << "succesful" << endl;
        }
        else {
            Product* buf = new Product[shop.titleQuantity + 1];
            buf[shop.titleQuantity] = product;
            delete[] shop.products;
            shop.products = buf;
            shop.titleQuantity++;
            cout << "succesful" << endl;
        }
    }
    else cout << "this product already exist" << endl;
}

int getIndex(Shop shop, string name) {
    for (int i = 0; i < shop.titleQuantity; i++) {
        if (shop.products[i].name == name)return i;
    }
    return -1;
}

int getIndex(Shop shop, int id) {
    for (int i = 0; i < shop.titleQuantity; i++) {
        if (shop.products[i].ID == id)return i;
    }
    return -1;
}

 
void deleteProduct(Shop& shop, string name) {
    if (shop.titleQuantity == 0) {
        cout << "shop is empty,you can't delete anything" << endl;
        return;
    }
    int index = getIndex(shop, name);
    if (index == -1) {
        cout << "this product not exist" << endl;
    }
    else {
        Product* buf = new Product[shop.titleQuantity - 1];
        for (int i = 0; i < shop.titleQuantity; i++) {
            if (i<index)buf[i] = shop.products[i];
            else if (i==index)continue;
            else buf[i - 1] = shop.products[i];
        }
        delete[]shop.products;
        shop.products = buf;
        shop.titleQuantity--;
        cout << "succesful" << endl;
    }
}

void deleteProduct(Shop& shop, int id) {
    if (shop.titleQuantity == 0) {
        cout << "shop is empty,you can't delete anything" << endl;
        return;
    }
    int index = getIndex(shop, id);
    if (index == -1) {
        cout << "this product not exist" << endl;
    }
    else {
        Product* buf = new Product[shop.titleQuantity - 1];
        for (int i = 0; i < shop.titleQuantity; i++) {
            if (i < index)buf[i] = shop.products[i];
            else if (i == index)continue;
            else buf[i - 1] = shop.products[i];
        }
        delete[]shop.products;
        shop.products = buf;
        shop.titleQuantity--;
        cout << "succesful" << endl;
    }
}

void updateProduct(Shop& shop, string name,string name1,ProductCategory category,float price,int quantity) {
    int index = getIndex(shop, name);
    if (index == -1) {
        cout << "this product not exist" << endl;
        return;
    }
    else {
        shop.products[index].name = name1;
        shop.products[index].category = category;
        shop.products[index].price = price;
        shop.products[index].quantity = quantity;
        cout << "succesful" << endl;
    }
}

void updateProduct(Shop& shop, int id, string name, ProductCategory category, float price, int quantity) {
    int index = getIndex(shop, id);
    if (index == -1) {
        cout << "this product not exist" << endl;
        return;
    }
    else {
        shop.products[index].name = name;
        shop.products[index].category = category;
        shop.products[index].price = price;
        shop.products[index].quantity = quantity;
        cout << "succesful" << endl;
    }
}



void printProduct(Product product) {
    cout << "Product name: " << product.name << endl;
    cout << "Category: " << CategoryToString(product.category) << endl;
    cout << "Price: " << product.price << endl;
    cout << "Quantity: " << product.quantity << endl;
    cout << "id: " << product.ID << endl;
    cout << endl;
}

void showAll(Shop shop) {
    for (int i = 0; i < shop.titleQuantity; i++) {
        printProduct(shop.products[i]);
    }
}

void  showCategory(Shop shop, int category) {
    ProductCategory cat = intToCategory(category);
    for (int i = 0; i < shop.titleQuantity; i++)
    {
        if (shop.products[i].category == cat)printProduct(shop.products[i]);
    }
}

void showQuantity(Shop shop, string name) {
    int index = getIndex(shop, name);
    if (index == -1) {
        cout << "this product not exist" << endl;
    }
    else {
        cout <<"Product: " << shop.products[index].name << endl;
        cout << "price: " << shop.products[index].price << endl;
    }
}

void showQuantity(Shop shop, int id) {
    int index = getIndex(shop, id);
    if (index == -1) {
        cout << "this product not exist" << endl;
    }
    else {
        cout << "Product: " << shop.products[index].name << endl;
        cout << "price: " << shop.products[index].price << endl;
    }
}

//работа с файлами

void saveFile(Shop& shop) {
    fstream in(path);
    for (int i = 0; i < shop.titleQuantity; i++) {
        in << shop.products[i].ID << ";" << shop.products[i].name << ";" << shop.products[i].category << ";" << shop.products[i].price << ";" << shop.products[i].quantity << ";" << endl;
    }
    in.close();
}

Product strToProduct(string data) {
    string stdata[5];
    string str = "";
    for (int i = 0, count = 0; i <= data.length(); i++)
    {
        if (data[i] == ';') {
            stdata[count++] = str;
            str = "";
        }
        else str += data[i];
    }
    return createProduct(stdata[1], intToCategory(stoi(stdata[2])), stof(stdata[3]), stoi(stdata[4]), stoi(stdata[0]));
}

void readFile(Shop& shop) {
    ifstream in(path);
    if (in.is_open()) {
        string str;
        while (getline(in, str)) {
            addProduct(shop, strToProduct(str));
        }
    }
    in.close();
}


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    bool work = true;
    int choice;
    Shop shop{new Product[0],0};
    readFile(shop);
    system("cls");
    while (work) {
        cout << "0. close" << endl;
        cout << "1. add product" << endl;
        cout << "2. delete product" << endl;
        cout << "3. show all products" << endl;
        cout << "4. show product quantity" << endl;
        cout << "5. show products of category" << endl;
        cout << "6. update product" << endl;
        cout << "enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string name;
            int category;
            float price;
            int quantity;
            cout << "enter product name: ";
            cin >> name;
            cout << "1. clothes, shoes, accessories" << endl << "2. house and garden" << endl;
            cout << "3. beauty and health" << endl << "4. technic and electronics" << endl;
            cout << "5. presents, hobbies, books" << endl << "6. sport and rest" << endl;
            cout << "7. сars" << endl << "8. products for kids" << endl;
            cout << "9. nutritional products and drinks" << endl << "10. equipment and products for the provision of services";
            cout << endl << "enter number of category: ";
            cin >> category;
            category--;
            cout << "enter price: ";
            cin >> price;
            cout << "enter quantity: ";
            cin >> quantity;
            addProduct(shop, createProduct(name, intToCategory(category), price, quantity));
            system("cls");
            break;
        }
        case 2:
        {
            int choice2;
            cout << "how would you like to delete product?" << endl;
            cout << "1.by name\t\t2.by id" << endl;
            cin >> choice;
            if (choice == 1) {
                string name;
                cout << "enter name: ";
                cin >> name;
                deleteProduct(shop, name);
            }
            else if (choice == 2) {
                int id;
                cout << "enter id: ";
                cin >> id;
                deleteProduct(shop, id);
            }
            else {
                cout << "incorrect option" << endl;
            }
            system("cls");
            break;
        }
        case 3:
        {
            showAll(shop);
            string str;
            cout << "enter any symbol to close the list" << endl;
            while (str == "") getline(cin, str);
            system("cls");
            break;
        }
        case 4:
        {
            int choice2;
            cout << "how would you like to delete product?" << endl;
            cout << "1.by name\t\t2.by id" << endl;
            cin >> choice;
            if (choice == 1) {
                string name;
                cout << "enter name: ";
                cin >> name;
                showQuantity(shop, name);
            }
            else if (choice == 2) {
                int id;
                cout << "enter id: ";
                cin >> id;
                showQuantity(shop, id);
            }
            else {
                cout << "incorrect option" << endl;
            }
            string str;
            cout << "enter any symbol to close the list" << endl;
            while (str == "") getline(cin, str);
            system("cls");
            break;
        }
        case 5:
        {
            int category;
            cout << "1. clothes, shoes, accessories" << endl << "2. house and garden" << endl;
            cout << "3. beauty and health" << endl << "4. technic and electronics" << endl;
            cout << "5. presents, hobbies, books" << endl << "6. sport and rest" << endl;
            cout << "7. сars" << endl << "8. products for kids" << endl;
            cout << "9. nutritional products and drinks" << endl << "10. equipment and products for the provision of services";
            cout << endl << "enter number of category: ";
            cin >> category;
            category--;
            showCategory(shop, category);
            string str;
            cout << "enter any symbol to close the list" << endl;
            while (str == "") getline(cin, str);
            system("cls");
            break;
        }
        case 6:
        {
            int choice2;
            cout << "how would you like to delete product?" << endl;
            cout << "1.by name\t\t2.by id" << endl;
            cin >> choice;
            if (choice == 1) {
                string name;
                cout << "enter name: ";
                cin >> name;
                string name1;
                int category;
                float price;
                int quantity;
                cout << "enter product name: ";
                cin >> name1;
                cout << "1. clothes, shoes, accessories" << endl << "2. house and garden" << endl;
                cout << "3. beauty and health" << endl << "4. technic and electronics" << endl;
                cout << "5. presents, hobbies, books" << endl << "6. sport and rest" << endl;
                cout << "7. сars" << endl << "8. products for kids" << endl;
                cout << "9. nutritional products and drinks" << endl << "10. equipment and products for the provision of services";
                cout << endl << "enter number of category: ";
                cin >> category;
                category--;
                cout << "enter price: ";
                cin >> price;
                cout << "enter quantity: ";
                cin >> quantity;
                updateProduct(shop, name, name1, intToCategory(category), price, quantity);
            }
            else if (choice == 2) {
                int id;
                cout << "enter id: ";
                cin >> id;
                string name;
                int category;
                float price;
                int quantity;
                cout << "enter product name: ";
                cin >> name;
                cout << "1. clothes, shoes, accessories" << endl << "2. house and garden" << endl;
                cout << "3. beauty and health" << endl << "4. technic and electronics" << endl;
                cout << "5. presents, hobbies, books" << endl << "6. sport and rest" << endl;
                cout << "7. сars" << endl << "8. products for kids" << endl;
                cout << "9. nutritional products and drinks" << endl << "10. equipment and products for the provision of services";
                cout << endl << "enter number of category: ";
                cin >> category;
                category--;
                cout << "enter price: ";
                cin >> price;
                cout << "enter quantity: ";
                cin >> quantity;
                updateProduct(shop, id, name, intToCategory(category), price, quantity);
            }
            else {
                cout << "incorrect option" << endl;
            }
            system("cls");
            break;
        }
        case 0:
            saveFile(shop);
            system("cls");
            work = false;
            break;
        default:
            break;
        }
    }
}
