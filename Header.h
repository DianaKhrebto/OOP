#ifndef HEADER_H
#define HEADER_H

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//����� ��������
enum Habitation {
    TUNDRA, //������
    DESERT, //�������
    STEPPE, //�����
    TAIGA //�����
};

//����� "��������"
class Plant {
    string Name; //�������� ��������
    Habitation H; //����� ��������
public:
    string Get_Name(); //������� ��������� �������� ��������
    Habitation Get_H(); //������� ��������� ����� ��������

    static Plant* In_Plant(ifstream& ifst); //������� ����� ��������
    virtual void In_Data(ifstream& ifst) = 0; //����� ����������� ������� ����� ��������,
                                              //��� ����� ���������� ������� ������ ��������
    virtual void Out_Data(string Name, Habitation H, ofstream& ofst) = 0; //����� ����������� ������� ������ ��������,
                                              //��� ����� ���������� ������� ������ ��������
    virtual int Plant_consonant_letters(string Name) = 0; //������� �������� ����� ��������� ���� � �������� ��������
    bool Compare(Plant& Other); //������� ��������� ����� ��������� ���� � ��������� ��������
    virtual void Out_Only_Tree(string Name, Habitation H, ofstream& ofst); //������� ������ ������ ��������
protected:
    Plant() {};
};

//����� "������"
class Tree : public Plant {
    long int Age; //������� ������
public:
    void In_Data(ifstream& ifst); //������� ����� ������
    void Out_Data(string Name, Habitation H, ofstream& ofst); //������� ������ ������
    int Plant_consonant_letters(string Name); //������� �������� ����� ��������� ���� � �������� ��������
    void Out_Only_Tree(string Name, Habitation H, ofstream& ofst); //������� ������ ������ ��������
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
    void Out_Data(string Name, Habitation H, ofstream& ofst); //������� ������ ����������
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
    void Out_Data(string Name, Habitation H, ofstream& ofst); //������� ������ ������
    int Plant_consonant_letters(string Name); //������� �������� ����� ��������� ���� � �������� ��������
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
    void Out_Only_Tree(ofstream& ofst); //������� ������ ������ ��������
    Container(); //�����������
    ~Container() { Clear_Container(); } //����������  
};

#endif // HEADER_H