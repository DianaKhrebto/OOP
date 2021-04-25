#ifndef HEADER_H
#define HEADER_H

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//Класс "растение"
class Plant {
    string Name; //Название растения
public:
    string Get_Name(); //Функция получения названия растения

    static Plant* In_Plant(ifstream& ifst); //Функция вывод растения
    virtual void In_Data(ifstream& ifst) = 0; //Чисто вирутальная функция ввода растения,
                                              //она будет определена каждого класса растения
    virtual void Out_Data(string Name, ofstream& ofst) = 0; //Чисто вирутальная функция вывода растения,
                                              //она будет определена каждого класса растения
    virtual int Plant_consonant_letters(string Name) = 0; //Функция подсчета числа согласных букв в названии растения
    bool Compare(Plant& Other); //Функция сравнения числа согласных букв в названиях растений
protected:
    Plant() {};
};

//Класс "дерево"
class Tree : public Plant {
    long int Age; //Возраст дерева
public:
    void In_Data(ifstream& ifst); //Функция ввода дерева
    void Out_Data(string Name, ofstream& ofst); //Функция вывода дерева
    int Plant_consonant_letters(string Name); //Функция подсчета числа согласных букв в названии растения
    Tree() {};
};

//Класс "кустарник"
class Shrub : public Plant {
    //Месяц цветения
    enum Month {
        JENUARY,
        FEBRUARY,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUGUST,
        SEPTEMBER,
        OCTOBER,
        NOVEMBER,
        DECEMBER
    };

    Month M; //Месяц цветения
public:
    void In_Data(ifstream& ifst); //Функция ввода кустарника
    void Out_Data(string Name, ofstream& ofst); //Функция вывода кустарника
    int Plant_consonant_letters(string Name); //Функция подсчета числа согласных букв в названии растения
    Shrub() {};
};

//Класс "цветок"
class Flower : public Plant {
    //Тип цветка
    enum Type {
        HOME,
        GARDEN,
        WILD
    };

    Type T; //Тип цветка
public:
    void In_Data(ifstream& ifst); //Функция ввода цветка
    void Out_Data(string Name, ofstream& ofst); //Функция вывода цветка
    Flower() {};
};

//Структура "узел контейнера"
struct Node {
    Node* Next; //Указатель на следующий элемент контейнера (узел)
    Plant* Cont; //Указатель на растение
};

class Container {
    Node* Head; //Указатель на первый элемент контейнера
    int Len; //Количество элементов в контейнере
public:
    void In_Container(ifstream& ifst); //Функция ввода элементов в контейнер
    void Out_Container(ofstream& ofst); //Функция вывода контейнера
    void Clear_Container(); //Функция очистки контейнера
    void Sort(); //Функция сортировки контейнера
    Container(); //Конструктор
    ~Container() { Clear_Container(); } //Деструктор  
};

#endif // HEADER_H