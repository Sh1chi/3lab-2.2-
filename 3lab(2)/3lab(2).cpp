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

    const string getFirstName(); // Метод получения имени человека
    const string getLastName();// Метод получения фамилии человека
};

// Реализация методов класса Person
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

    const string getFirstName(); // Метод получения имени сотрудника
    const string getLastName(); // Метод получения имени сотрудника
    void outputEmployee(); // Метод вывода информации о сотруднике
};

// Реализация методов класса Employee
const string Employee::getFirstName() {
    return person.getFirstName();
}
const string Employee::getLastName() {
    return person.getLastName();
}
void Employee::outputEmployee() {
    cout << "Имя сотрудника: " << person.getFirstName() << " " << person.getLastName() << endl;
    cout << "Должность сотрудника: " << position << endl;
    cout << "Зарплата сотрудника: " << salary << endl;
}

// Функция ввода информации о сотруднике в адреса меременных
void inputEmployee(string* first_name, string* last_name, string* position, int* salary) {
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


// Класс покупателя
class Customer {
    Person person;         // Информация о покупателе
    string phone_number;  // Номер телефона покупателя

public:
    Customer() : phone_number("") {}

    Customer(string first_name, string last_name, string phone_number)
        : person(first_name, last_name), phone_number(phone_number) {}

    ~Customer() {}

    const string getFirstName(); // Метод получения имени сотрудника
    const string getLastName(); // Метод получения имени сотрудника
    void outputCustomer(); // Метод вывода информации о покупателе
};

// Реализация методов класса Customer
const string Customer::getFirstName() {
    return person.getFirstName();
}
const string Customer::getLastName() {
    return person.getLastName();
}
void Customer::outputCustomer() {
    cout << "Имя покупателя: " << person.getFirstName() << " " << person.getLastName() << endl;
    cout << "Номер телефона: " << phone_number << endl;
}

// Функция ввода информации о покупателе в адреса меременных
void inputCustomer(string* first_name, string* last_name, string* phone_number) {
    cout << "Введите имя покупателя: ";
    cin >> *first_name;
    cout << "Введите фамилию покупателя: ";
    cin >> *last_name;
    cout << "Введите номер телефона: ";
    cin >> *phone_number;
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

    // Добавим метод для получения марки и модели авто
    const string getBrandModel(); // Метод получения марки и модели авто
    const int getPrice(); // Метод получения цены авто
    void outputCar(); // Метод вывода информации об автомобиле
};
// Реализация методов класса Car
const string Car::getBrandModel() {
    return brand_model;
}
const int Car::getPrice() {
    return price;
}
void Car::outputCar() {
    cout << "Марка и модель авто: " << brand_model << endl;
    cout << "Страна-производитель: " << country << endl;
    cout << "Год производства: " << year << endl;
    cout << "Цена: " << price << endl;
    cout << "Состояние: " << condition << endl;
    cout << "Количество: " << quantity << endl;
}

// Функция ввода информации об автомобилях в адреса меременных
void inputCar(string* brand_model, string* country, int* year, int* price, string* condition, int* quantity) {
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

    const string getDealershipName(); // Метод получения названия автосалона
    void outputDealership(Employee* employeeArray, int num_employees, Car* carArray, int num_cars); // Функция вывода информации об автосалоне
};

// Реализация методов класса Dealership
const string Dealership::getDealershipName() {
    return name;
}
void  Dealership::outputDealership(Employee* employeeArray, int num_employees, Car* carArray, int num_cars) {
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

    void outputDeal(); // Метод вывода информации о сделке
};

// Реализация методов класса Deal
void Deal::outputDeal() {
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
    SetConsoleEncoding(); // Установка кодировки для консоли (для поддержки кириллицы)

    cout << "          -- Реализация АТД на языке С и С++ --" << endl;
    cout << endl;

    // Ввод данных о автосалоне
    string dealership_name, dealership_address;
    cout << "Введите название автосалона: ";
    getline(cin, dealership_name);
    cout << "Введите адрес автосалона: ";
    getline(cin, dealership_address);

    // Ввод количества сотрудников и создание массива сотрудников
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
        inputEmployee(&first_name, &last_name, &position, &salary);
        employeeArray[i] = Employee(first_name, last_name, position, salary);
        cout << endl;
    }

    // Ввод количества автомобилей и создание массива автомобилей
    int num_cars;
    cout << "Введите количество автомобилей: ";
    cin >> num_cars;
    Car* carArray = new Car[num_cars];

    cout << endl;
    cout << "  -- Ввод данных об автомобилях --" << endl;
    for (int i = 0; i < num_cars; ++i) {
        string brand_model, country, condition;
        int year, price, quantity;
        cout << "Автомобиль #" << i + 1 << ":" << endl;
        inputCar(&brand_model, &country, &year, &price, &condition, &quantity);
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
    dealership.outputDealership(employeeArray, num_employees, carArray, num_cars);
    cout << endl;

    // Вывод информации о сотрудниках
    cout << " -- Информация о сотрудниках --" << endl;
    for (int i = 0; i < num_employees; ++i) {
        cout << endl;
        cout << "Сотрудник #" << i + 1 << ":" << endl;
        employeeArray[i].outputEmployee();
    }
    cout << endl;

    // Вывод информации о автомобилях
    cout << " -- Информация об автомобилях --" << endl;
    for (int i = 0; i < num_cars; ++i) {
        cout << endl;
        cout << "Автомобиль #" << i + 1 << ":" << endl;
        carArray[i].outputCar();
    }

    // Ввод количества сделок и создание массива сделок
    int num_deals;
    cout << endl;
    cout << "Введите количество сделок: ";
    cin >> num_deals;
    Deal* dealArray = new Deal[num_deals];

    int deal_number;
    cout << endl;
    cout << "  -- Ввод данных о сделках --" << endl;
    // Ввод данных о каждой сделке и их сохранение в массиве
    for (int i = 0; i < num_deals; ++i) {
        //Ввод номера сделки
        cout << "Сделка #";
        cin >> deal_number;

        //Ввод даты сделки
        string deal_date;
        cout << "Введите дату сделки: ";
        cin >> deal_date;

        // Ввод данных о покупателе
        string buyer_first_name, buyer_last_name, buyer_phone_number;
        inputCustomer(&buyer_first_name, &buyer_last_name, &buyer_phone_number);
        Customer buyer(buyer_first_name, buyer_last_name, buyer_phone_number);

        // Вывод списка доступных сотрудников и попросим выбрать
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

        // Создание объекта сделки и сохранение его в массиве
        dealArray[i] = Deal(deal_number, deal_date, seller, buyer, car_sold, car_sold.getPrice(), dealership);
        cout << endl;
    }

    // Вывод информации о каждой сделке
    cout << endl;
    cout << " __-- Информация о сделках --__" << endl;

    for (int i = 0; i < num_deals; ++i) {
        dealArray[i].outputDeal();
        cout << endl;
    }

    // Освобождение выделенной памяти
    delete[] employeeArray;
    delete[] carArray;
    delete[] dealArray;

    return 0;
}

