#ifndef HEADER_H
#define HEADER_H

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//����� "��������"
class Plant {
    string Name; //�������� ��������
public:
    string Get_Name(); //������� ��������� �������� ��������

    static Plant* In_Plant(ifstream& ifst); //������� ����� ��������
    virtual void In_Data(ifstream& ifst) = 0; //����� ����������� ������� ����� ��������,
                                              //��� ����� ���������� ������� ������ ��������
    virtual void Out_Data(string Name, ofstream& ofst) = 0; //����� ����������� ������� ������ ��������,
                                              //��� ����� ���������� ������� ������ ��������
    virtual int Plant_consonant_letters(string Name) = 0; //������� �������� ����� ��������� ���� � �������� ��������
    bool Compare(Plant& Other); //������� ��������� ����� ��������� ���� � ��������� ��������
protected:
    Plant() {};
};

//����� "������"
class Tree : public Plant {
    long int Age; //������� ������
public:
    void In_Data(ifstream& ifst); //������� ����� ������
    void Out_Data(string Name, ofstream& ofst); //������� ������ ������
    int Plant_consonant_letters(string Name); //������� �������� ����� ��������� ���� � �������� ��������
    Tree() {};
};

//����� "���������"
class Shrub : public Plant {
    //����� ��������
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

    Month M; //����� ��������
public:
    void In_Data(ifstream& ifst); //������� ����� ����������
    void Out_Data(string Name, ofstream& ofst); //������� ������ ����������
    int Plant_consonant_letters(string Name); //������� �������� ����� ��������� ���� � �������� ��������
    Shrub() {};
};

//����� "������"
class Flower : public Plant {
    //��� ������
    enum Type {
        HOME,
        GARDEN,
        WILD
    };

    Type T; //��� ������
public:
    void In_Data(ifstream& ifst); //������� ����� ������
    void Out_Data(string Name, ofstream& ofst); //������� ������ ������
    Flower() {};
};

//��������� "���� ����������"
struct Node {
    Node* Next; //��������� �� ��������� ������� ���������� (����)
    Plant* Cont; //��������� �� ��������
};

class Container {
    Node* Head; //��������� �� ������ ������� ����������
    int Len; //���������� ��������� � ����������
public:
    void In_Container(ifstream& ifst); //������� ����� ��������� � ���������
    void Out_Container(ofstream& ofst); //������� ������ ����������
    void Clear_Container(); //������� ������� ����������
    void Sort(); //������� ���������� ����������
    Container(); //�����������
    ~Container() { Clear_Container(); } //����������  
};

#endif // HEADER_H