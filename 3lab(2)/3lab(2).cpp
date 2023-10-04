#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

#define MAX_EMPLOYEES 100
#define MAX_CARS 100
#define MAX_DEALS 100

// Класс человека
class Person {
    string first_name;  // Имя человека
    string last_name;   // Фамилия человека

public:
    Person() : first_name(""), last_name("") {}

    Person(string first_name, string last_name) : first_name(first_name), last_name(last_name) {}

    ~Person() {}

    const string getFirstName();
    const string getLastName();
};
const string Person::getFirstName() {
    return first_name;
}
const string Person::getLastName() {
    return last_name;
}

// Класс сотрудника
class Employee {
    Person person;      // Информация о сотруднике
    string position;   // Должность сотрудника
    int salary;        // Зарплата сотрудника

public:
    Employee() : position(""), salary(0) {}

    Employee(string first_name, string last_name, string position, int salary)
        : person(first_name, last_name), position(position), salary(salary) {}

    ~Employee() {}

    void OutputEmployee();
    const string getFirstName();
    const string getLastName();
};
void InputEmployee(string* first_name, string* last_name, string* position, int* salary) {
    cout << "Введите имя сотрудника: ";
    cin >> *first_name;
    cout << "Введите фамилию сотрудника: ";
    cin >> *last_name;
    cout << "Введите должность сотрудника: ";
    cin.ignore(); // Очищаем буфер ввода перед считыванием строки
    getline(cin, *position);
    cout << "Введите зарплату сотрудника: ";
    cin >> *salary;
}
void Employee::OutputEmployee() {
    cout << "Имя сотрудника: " << person.getFirstName() << " " << person.getLastName() << endl;
    cout << "Должность сотрудника: " << position << endl;
    cout << "Зарплата сотрудника: " << salary << endl;
}
const string Employee::getFirstName() {
    return person.getFirstName();
}
const string Employee::getLastName() {
    return person.getLastName();
}


// Класс покупателя
class Customer {
    Person person;         // Информация о покупателе
    string phone_number;  // Номер телефона покупателя

public:
    Customer() : phone_number("") {}

    Customer(string first_name, string last_name, string phone_number)
        : person(first_name, last_name), phone_number(phone_number) {}

    ~Customer() {}

    // Добавим метод для вывода информации о покупателе
    void OutputCustomer();
    const string getFirstName();
    const string getLastName();
};
void InputCustomer(string* first_name, string* last_name, string* phone_number) {
    cout << "Введите имя покупателя: ";
    cin >> *first_name;
    cout << "Введите фамилию покупателя: ";
    cin >> *last_name;
    cout << "Введите номер телефона: ";
    cin >> *phone_number;
}
void Customer::OutputCustomer() {
    cout << "Имя покупателя: " << person.getFirstName() << " " << person.getLastName() << endl;
    cout << "Номер телефона: " << phone_number << endl;
}
const string Customer::getFirstName() {
    return person.getFirstName();
}
const string Customer::getLastName() {
    return person.getLastName();
}

// Класс автомобиля
class Car {
    string brand_model;  // Марка и модель автомобиля
    string country;     // Страна производства
    int year;            // Год выпуска
    int price;           // Цена
    string condition;    // Состояние (например, "New" или "Used")
    int quantity;        // Количество доступных автомобилей

public:
    Car() : brand_model(""), country(""), year(0), price(0), condition(""), quantity(0) {}

    Car(string brand_model, string country, int year, int price, string condition, int quantity)
        : brand_model(brand_model), country(country), year(year), price(price), condition(condition), quantity(quantity) {}

    ~Car() {}

    void OutputCar() {
        cout << "Марка и модель авто: " << brand_model << endl;
        cout << "Страна-производитель: " << country << endl;
        cout << "Год производства: " << year << endl;
        cout << "Цена: " << price << endl;
        cout << "Состояние: " << condition << endl;
        cout << "Количество: " << quantity << endl;
    }

    // Добавим метод для получения марки и модели авто
    const string getBrandModel();
};
const string Car::getBrandModel() {
    return brand_model;
}
// Метод для ввода информации об автомобиле
void InputCar(string* brand_model, string* country, int* year, int* price, string* condition, int* quantity) {
    cout << "Введите марку и модель авто: ";
    cin.ignore(); // Очищаем буфер ввода перед считыванием строки
    getline(cin, *brand_model);
    cout << "Введите страну-производитель: ";
    getline(cin, *country);
    cout << "Введите год производства: ";
    cin >> *year;
    cout << "Введите цену: ";
    cin >> *price;
    cout << "Введите состояние: ";
    cin.ignore(); // Очищаем буфер ввода перед считыванием строки
    getline(cin, *condition);
    cout << "Введите количество: ";
    cin >> *quantity;
}

// Класс автосалона
class Dealership {
    string name;                      // Название автосалона
    string address;                   // Адрес автосалона
    Employee employees[MAX_EMPLOYEES]; // Список сотрудников
    Car cars[MAX_CARS];               // Список имеющихся автомобилей

public:
    Dealership() : name(""), address("") {}

    // Контруктор с параметрами
    Dealership(string name, string address, Car* carArray, int numCars, Employee* employeeArray, int numEmployees)
        : name(name), address(address) {
        // Инициализация массивов в конструкторе
        for (int i = 0; i < numCars; ++i) {
            cars[i] = carArray[i];
        }

        for (int i = 0; i < numEmployees; ++i) {
            employees[i] = employeeArray[i];
        }
    }

    ~Dealership() {}

    void OutputDealership(Employee* employeeArray, int num_employees, Car* carArray, int num_cars);
    const string getDealershipName();
};
// Метод для вывода информации об автосалоне
void  Dealership::OutputDealership(Employee* employeeArray, int num_employees, Car* carArray, int num_cars) {
    cout << "Название автосалона: " << name << endl;
    cout << "Адрес автосалона: " << address << endl;
    cout << "-Сотрудники:" << endl;
    for (int j = 0; j < num_employees; ++j) {
        cout << j + 1 << ". " << employeeArray[j].getFirstName() << " " << employeeArray[j].getLastName() << endl;
    }

    // Вывод информации о автомобилях
    cout << "-Автомобили:" << endl;
    for (int j = 0; j < num_cars; ++j) {
        cout << j + 1 << ". " << carArray[j].getBrandModel() << endl;
    }
}
const string Dealership::getDealershipName() {
    return name;
}

// Класс сделки
class Deal {
    int deal_number;          // Номер сделки
    string date;              // Дата сделки
    Employee seller;         // Продавец
    Customer buyer;          // Покупатель
    Car car_sold;            // Проданный автомобиль
    int transaction_amount;  // Сумма сделки
    Dealership dealership;   // Автосалон

public:
    Deal() : deal_number(0), transaction_amount(0) {}

    Deal(int deal_number, string date, Employee seller, Customer buyer, Car car_sold, int transaction_amount, Dealership dealership)
        : deal_number(deal_number), date(date), seller(seller), buyer(buyer), car_sold(car_sold), transaction_amount(transaction_amount), dealership(dealership) {}

    ~Deal() {}

    void OutputDeal();
};
void Deal::OutputDeal() {
    cout << " -- Сделка #" << deal_number << ":" << endl;
    cout << "Дата сделки: " << date << endl;
    cout << "Продавец: " << seller.getFirstName() << " " << seller.getLastName() << endl;
    cout << "Покупатель: " << buyer.getFirstName() << " " << buyer.getLastName() << endl;
    cout << "Автомобиль: " << car_sold.getBrandModel() << endl;
    cout << "Сумма сделки: " << transaction_amount << endl;
    cout << "Автосалон: " << dealership.getDealershipName() << endl;
}

// Функция для установки кодировки для консоли (для поддержки кириллицы)
void SetConsoleEncoding() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}


int main() {
    SetConsoleEncoding();

    cout << "          -- Реализация АТД на языке С и С++ --" << endl;
    cout << endl;

    string dealership_name, dealership_address;
    cout << "Введите название автосалона: ";
    getline(cin, dealership_name);
    cout << "Введите адрес автосалона: ";
    getline(cin, dealership_address);

    int num_employees;
    cout << "Введите количество сотрудников: ";
    cin >> num_employees;

    Employee* employeeArray = new Employee[num_employees];

    cout << endl;
    cout << "  -- Ввод данных о сотрудниках --" << endl;
    for (int i = 0; i < num_employees; ++i) {
        string first_name, last_name, position;
        int salary;
        cout << "Сотрудник #" << i + 1 << ":" << endl;
        InputEmployee(&first_name, &last_name, &position, &salary);
        employeeArray[i] = Employee(first_name, last_name, position, salary);
        cout << endl;
    }

    int num_cars;
    cout << "Введите количество автомобилей: ";
    cin >> num_cars;
    cout << endl;

    Car* carArray = new Car[num_cars];

    cout << "  -- Ввод данных об автомобилях --" << endl;
    for (int i = 0; i < num_cars; ++i) {
        string brand_model, country, condition;
        int year, price, quantity;
        cout << "Автомобиль #" << i + 1 << ":" << endl;
        InputCar(&brand_model, &country, &year, &price, &condition, &quantity);
        carArray[i] = Car(brand_model, country, year, price, condition, quantity);
        cout << endl;
    }

    // Создание объекта Dealership и ввод данных о сотрудниках и автомобилях (как в предыдущем коде)
    Dealership dealership(dealership_name, dealership_address, carArray, num_cars, employeeArray, num_employees);

    cout << endl;
    cout << endl;
    cout << " __--Вся введенная информация--__" << endl;
    cout << endl;
    // Вывод информации об автосалоне
    cout << " -- Информация об автосалоне --" << endl;
    dealership.OutputDealership(employeeArray, num_employees, carArray, num_cars);

    cout << endl;
    // Вывод информации о сотрудниках
    cout << " -- Информация о сотрудниках --" << endl;
    for (int i = 0; i < num_employees; ++i) {
        cout << endl;
        cout << "Сотрудник #" << i + 1 << ":" << endl;
        employeeArray[i].OutputEmployee();
    }

    cout << endl;
    // Вывод информации о автомобилях
    cout << " -- Информация об автомобилях --" << endl;
    for (int i = 0; i < num_cars; ++i) {
        cout << endl;
        cout << "Автомобиль #" << i + 1 << ":" << endl;
        carArray[i].OutputCar();
    }


    int num_deals;
    cout << endl;
    cout << "Введите количество сделок: ";
    cin >> num_deals;
    cout << endl;

    Deal* dealArray = new Deal[num_deals];
    int deal_number;
    cout << "  -- Ввод данных о сделках --" << endl;
    for (int i = 0; i < num_deals; ++i) {
        cout << "Сделка #";
        cin >> deal_number;

        string deal_date;
        cout << "Введите дату сделки: ";
        cin >> deal_date;

        // Введите данные о покупателе
        string buyer_first_name, buyer_last_name, buyer_phone_number;
        InputCustomer(&buyer_first_name, &buyer_last_name, &buyer_phone_number);
        Customer buyer(buyer_first_name, buyer_last_name, buyer_phone_number);

        // Выведем список доступных сотрудников и попросим выбрать
        cout << "Выберите продавца (введите номер сотрудника):" << endl;
        for (int j = 0; j < num_employees; ++j) {
            cout << j + 1 << ". " << employeeArray[j].getFirstName() << " " << employeeArray[j].getLastName() << endl;
        }
        int seller_choice;
        cin >> seller_choice;
        Employee seller = employeeArray[seller_choice - 1];

        // Выведем список доступных автомобилей и попросим выбрать
        cout << "Выберите автомобиль (введите номер автомобиля):" << endl;
        for (int j = 0; j < num_cars; ++j) {
            cout << j + 1 << ". " << carArray[j].getBrandModel() << endl;
        }
        int car_choice;
        cin >> car_choice;
        Car car_sold = carArray[car_choice - 1];

        dealArray[i] = Deal(deal_number, deal_date, seller, buyer, car_sold, 0, dealership);
        cout << endl;
    }

    cout << endl;
    cout << " __-- Информация о сделках --__" << endl;

    for (int i = 0; i < num_deals; ++i) {
        dealArray[i].OutputDeal();
        cout << endl;
    }


    delete[] employeeArray;
    delete[] carArray;
    delete[] dealArray;

    return 0;
}
