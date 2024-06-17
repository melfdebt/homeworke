// store.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<string>
#include <fstream>
#include<Windows.h>
#include <string.h>
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

bool checkProduct(Shop shop, Product prod) {
    for (int i = 0; i < shop.titleQuantity; i++) {
        if (shop.products[i].name == prod.name) return false;
    }
    return true;
}

ProductCategory getCategory(int cat);

Product createProduct(string name, int category, float price, int quantity) {
    Product prod{ name,getCategory(category),price,quantity,ID++ };
    return prod;
}
Product createProduct(string name, int category, float price, int quantity, int id) {
    Product prod{ name,getCategory(category),price,quantity,id };
    ID=id++;
    return prod;
}
void addProduct(Shop& shop, Product product)
{
    if (checkProduct(shop, product) == false) {
        cout << "this product was already added. you can update." << endl;
        Sleep(2000);
        return;
    }
    Product* buf = new Product[shop.titleQuantity + 1];

    for (int i = 0; i < shop.titleQuantity; i++) {
        buf[i] = shop.products[i];
    }
    buf[shop.titleQuantity] = product;
    shop.titleQuantity++;
   
    
    shop.products = buf;
}

void addPrStart(Shop& shop, Product product) {
    Product* buf = new Product [shop.titleQuantity];
    buf[shop.titleQuantity - 1] = product;
    shop.products = buf;
    ID++;
}

void deleteProduct(Shop& shop, int ID) {
    if (ID > shop.titleQuantity+1 or ID == 0) {
        cout << "ID out of range" << endl;
        Sleep(2000);
        return;
    }
    Product* buf = new Product[shop.titleQuantity - 1];
    for (int i = 0; i < shop.titleQuantity; i++) {
        if (shop.titleQuantity == 1) {
            break;
        }
        else {
            if (i < ID-1)buf[i] = shop.products[i];
            else if (i == ID-1) continue;
            else buf[i - 1] = shop.products[i];
        }
    }
    shop.products = buf;
    shop.titleQuantity--;
    ID--;
    cout << "succes" << endl;
    Sleep(2000);
}

void deleteProductByName(Shop& shop, string name) {
    int ID = -1;
    for (int i = 0; i < shop.titleQuantity; i++) {
        if (shop.products[i].name == name) ID = shop.products[i].ID;
    }
    if (ID == -1) {
        cout << "this product doesn't exist" << endl;
        Sleep(2000);
    }
    else deleteProduct(shop, ID);
}

void printProduct(Product& product);

void outputProducts(Shop &shop) {
    if (shop.titleQuantity <= 0) {
        cout << "shop is empty" << endl;
        return;
    }
    for (int i = 0; i < shop.titleQuantity; i++) {
        printProduct(shop.products[i]);
    }
}
string showCategory(ProductCategory category) {
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
void printProduct(Product& product) {
    cout << "Product name: " << product.name << endl << "Product category: "
        << showCategory(product.category) << endl << "Product price: " << product.price << endl
        << "Quantity of products: " << product.quantity << endl << "ID: " << product.ID << endl;
}
void outputProdCategory(Shop shop, ProductCategory category) {
    for (int i = 0; i < shop.titleQuantity; i++) {
        if (shop.products[i].category == category) printProduct(shop.products[i]);
        else continue;
    }
}

void outputByTitleQuantity(Shop shop, string title)
{
    for (int i = 0; i < shop.titleQuantity; i++) {
        if (shop.products[i].name == title) cout << "Product quantity: " << shop.products[i].quantity << endl;
    }
}

void saveFile(Shop& shop) {
    fstream in(path);
    for (int i = 0; i < shop.titleQuantity; i++) {
        in << shop.products[i].ID << ";" << shop.products[i].name << ";" << shop.products[i].category << ";" << shop.products[i].price << ";" << shop.products[i].quantity << ";" << endl;
    }
    in.close();
}
int getstr() {
    int count = 0;
    ifstream in(path);
    if (in.is_open()) {
        string str;
        while (getline(in, str)) {
            if (str != "")count++;
        }
    }
    in.close();
    return count;
}

ProductCategory getCategory(int cat) {

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
    return createProduct(stdata[1], getCategory(stoi(stdata[2])), stof(stdata[3]), stoi(stdata[4]), stoi(stdata[0]));
}

void readProducts(Shop& shop) {
    ifstream in(path);
    if (in.is_open()) {
        string str;
        while (getline(in, str)) {
            addPrStart(shop, strToProduct(str));
        }
    }
    in.close();
}


void updateProduct(Shop& shop, string name, float price, int category, int quantity) {
    int index;
    bool flag = true;
    for (int i = 0; i < shop.titleQuantity; i++) {
        if (shop.products[i].name == name) {
            index = i;
            flag = false;
        }
    }
    if (flag == false) {
        shop.products[index].price = price;
        shop.products[index].quantity = quantity;
        shop.products[index].category = getCategory(category);
        cout << "updated" << endl;
    }
    else cout << "not found" << endl;
    Sleep(2000);

}

int main()
{
    //setlocale(LC_NUMERIC, "ru_RU.UTF-8");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    bool work = true;
    int choice;
    Shop shop;
    shop.titleQuantity = getstr();
    if (shop.titleQuantity ==0) {
        cout << "you can't work with store, because you don't have any products. to work, add something" << endl;
    }
    else {
        shop.products = new Product[shop.titleQuantity];
        readProducts(shop);
    }
    
    while (work) {
        cout << "1. вывод списка товаров" << endl;
        cout << "2. добавить товар" << endl;
        cout << "3. удалить товар" << endl;
        cout << "4. вывести все товары определенной категории" << endl;
        cout << "5. вывести количество товаров определенного наименования" << endl;
        cout << "6. удалить товар по названию" << endl;
        cout << "7. обновить данные о продукте" << endl;
        cout << "0. закрыть приложение" << endl;
        cout << "введите цифру: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            work = false;
            system("cls");
            break;
        case 1:
        {
            outputProducts(shop);
            string str;
            while (str == "") getline(cin, str);
            system("cls");
            break;
        }
        case 2:
        {
            string name;
            cout << "введите название товара: ";
            cin >> name;
            int category;
            cout << "1. clothes, shoes, accessories" << endl << "2. house and garden" << endl;
            cout << "3. beauty and health" << endl << "4. technic and electronics" << endl;
            cout << "5. presents, hobbies, books" << endl << "6. sport and rest" << endl;
            cout << "7. сars" << endl << "8. products for kids" << endl;
            cout << "9. nutritional products and drinks" << endl << "10. equipment and products for the provision of services";
            cout << endl << "введите номер категории: ";
            cin >> category;
            category--;
            float price;
            cout << "введите цену продуктa: ";
            cin >> price;
            int quantity;
            cout << "введите количество товара: ";
            cin >> quantity;
            Product prod = createProduct(name, category, price, quantity);
            addProduct(shop, prod);
            cout << "успешно" << endl;
            system("cls");
            break;
        }
        case 3:
        {
            //outputProducts(shop);
            int id;
            cout << "введите ID товара: ";
            cin >> id;
            deleteProduct(shop, id);
            system("cls");
            break;
        }
        case 4:
        {
            int category;
            cout << "1. clothes, shoes, accessories" << endl << "2. house and garden" << endl;
            cout << "3. beauty and health" << endl << "4. technic and electronics" << endl;
            cout << "5. presents, hobbies, books" << endl << "6. sport and rest" << endl;
            cout << "7. сars" << endl << "8. products for kids" << endl;
            cout << "9. nutritional products and drinks" << endl << "10. equipment and products for the provision of services" << endl;
            cout << "введите номер категории: ";
            cin >> category;
            category--;
            outputProdCategory(shop, getCategory(category));
            string str;
            while (str == "") getline(cin, str);
            system("cls");
            break;
        }
        case 5:
        {
            string name;
            cout << "введите название товара: ";
            cin >> name;
            outputByTitleQuantity(shop, name);
            string str;
            while (str == "") getline(cin, str);
            system("cls");
            break;
        }
        case 6:
        {
            string name;
            cout << "enter product name: ";
            cin >> name;
            deleteProductByName(shop, name);
            system("cls");
            break;
        }
        case 7:
        {
            string name;
            cout << "введите название товара: ";
            cin >> name;
            int category;
            cout << "1. clothes, shoes, accessories" << endl << "2. house and garden" << endl;
            cout << "3. beauty and health" << endl << "4. technic and electronics" << endl;
            cout << "5. presents, hobbies, books" << endl << "6. sport and rest" << endl;
            cout << "7. сars" << endl << "8. products for kids" << endl;
            cout << "9. nutritional products and drinks" << endl << "10. equipment and products for the provision of services";
            cout << endl << "введите номер категории: ";
            cin >> category;
            category--;
            float price;
            cout << "введите цену продукты: ";
            cin >> price;
            int quantity;
            cout << "введите количество товара: ";
            cin >> quantity;
            updateProduct(shop, name, price, category, quantity);
            system("cls");
            break;
        }
        default:
            break;
        }

    }
    saveFile(shop);
}
