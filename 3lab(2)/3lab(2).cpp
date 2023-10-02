﻿#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

#define MAX_EMPLOYEES 100
#define MAX_CARS 100
#define MAX_DEALS 100

// Класс автосалона
class Dealership {
    string name;      // Название автосалона
    string address;   // Адрес автосалона

public:
    Dealership() : name(""), address("") {}

    Dealership(string name, string address) : name(name), address(address) {}

    ~Dealership() {}
};

// Класс человека
class Person {
    string first_name;  // Имя человека
    string last_name;   // Фамилия человека

public:
    Person() : first_name(""), last_name("") {}

    Person(string first_name, string last_name) : first_name(first_name), last_name(last_name) {}

    ~Person() {}
};

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
};

// Класс покупателя
class Customer {
    Person person;         // Информация о покупателе
    string phone_number;  // Номер телефона покупателя

public:
    Customer() : phone_number("") {}

    Customer(string first_name, string last_name, string phone_number)
        : person(first_name, last_name), phone_number(phone_number) {}

    ~Customer() {}
};

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
};

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
    Deal() : deal_number(0), date(""), transaction_amount(0) {}

    Deal(int deal_number, string date, Employee seller, Customer buyer, Car car_sold, int transaction_amount, Dealership dealership)
        : deal_number(deal_number), date(date), seller(seller), buyer(buyer), car_sold(car_sold), transaction_amount(transaction_amount), dealership(dealership) {}

    ~Deal() {}
};




// Функция для установки кодировки для консоли (для поддержки кириллицы)
void SetConsoleEncoding() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

int main() {
	SetConsoleEncoding();

    // Создание массивов сотрудников, автомобилей и сделок
    Employee employees [MAX_EMPLOYEES];
    Car cars[MAX_CARS];
    Deal deals[MAX_DEALS];

    // Пример добавления сотрудника в массив
    employees[0] = Employee("John", "Doe", "Sales Manager", 50000);

    // Пример добавления автомобиля в массив
    cars[0] = Car("Toyota Camry", "Japan", 2022, 25000, "New", 10);

    // Пример создания сделки и добавления ее в массив
    Employee seller = Employee("Jane", "Smith", "Salesperson", 40000);
    Customer buyer = Customer("Alice", "Johnson", "555-1234");
    Car car_sold = Car("Honda Civic", "Japan", 2021, 20000, "Used", 1);
    Dealership dealership = Dealership("Auto World", "123 Main St");

    deals[0] = Deal(1, "2023-10-02", seller, buyer, car_sold, 22000, dealership);

    // Ваш код для работы с массивами и объектами здесь

    return 0;

}

