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
    virtual void Out_Only_Tree(string Name, ofstream& ofst); //������� ������ ������ ��������
protected:
    Plant() {};
};

//����� "������"
class Tree : public Plant {
    long int Age; //������� ������
public:
    void In_Data(ifstream& ifst); //������� ����� ������
    void Out_Data(string Name, ofstream& ofst); //������� ������ ������
    void Out_Only_Tree(string Name, ofstream& ofst); //������� ������ ������ ��������
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
    Shrub() {};
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
    void Out_Only_Tree(ofstream& ofst); //������� ������ ������ ��������
    Container(); //�����������
    ~Container() { Clear_Container(); } //����������  
};

#endif // HEADER_H