#include "Header.h"

Container::Container() {
    Head = new Node();
    Head->Cont = NULL;
    Head->Next = NULL;
}

void Container::In_Container(ifstream& ifst) {
    Node* Temp_Node = Head;
    
    while (!ifst.eof()) {
        if ((Temp_Node->Cont = Plant::In_Plant(ifst))) {
            Temp_Node->Next = new Node();
            Temp_Node = Temp_Node->Next;
            Len++;
        }
    }
}

void Container::Out_Container(ofstream& ofst) {
    ofst << "Container contains " << Len
        << " elements." << endl << endl;

    Node* Temp_Node = Head;

    for (int i = 0; i < Len; i++) {
        ofst << i << ": ";
        Temp_Node->Cont->Out_Data(Temp_Node->Cont->Get_Name(), Temp_Node->Cont->Get_Habitation(), ofst);
        Temp_Node = Temp_Node->Next;
    }
}

void Container::Clear_Container() {
    for (int i = 0; i < Len; i++) {
        free(Head->Cont);
        Head = Head->Next;
    }

    Len = 0;
}

string Plant::Get_Name() {
    return Name;
}

Habitation Plant::Get_Habitation() {
    return H;
}

Plant* Plant::In_Plant(ifstream& ifst) {
    Plant* P;
    int K;

    ifst >> K;
    if (K == 1) {
        P = new Tree;
    }
    else if (K == 2) {
        P = new Shrub;
    }
    else {
        return 0;
    }

    ifst >> P->Name;

    string Habitant = "";

    ifst >> Habitant;

    if (Habitant == "Tundra") {
        P->H = TUNDRA;
    }
    else if (Habitant == "Desert") {
        P->H = DESERT;
    }
    else if (Habitant == "Steppe") {
        P->H = STEPPE;
    }
    else if (Habitant == "Taiga") {
        P->H = TAIGA;
    }

    P->In_Data(ifst);
    
    return P;
}

void Tree::In_Data(ifstream& ifst) {
    ifst >> Age;
}

void Shrub::In_Data(ifstream& ifst) {
    string Month = "";

    ifst >> Month;

    if (Month == "Jenuary") {
        M = JENUARY;
    }
    else if (Month == "February") {
        M = FEBRUARY;
    }
    else if (Month == "March") {
        M = MARCH;
    }
    else if (Month == "April") {
        M = APRIL;
    }
    else if (Month == "May") {
        M = MAY;
    }
    else if (Month == "June") {
        M = JUNE;
    }
    else if (Month == "July") {
        M = JULY;
    }
    else if (Month == "August") {
        M = AUGUST;
    }
    else if (Month == "September") {
        M = SEPTEMBER;
    }
    else if (Month == "October") {
        M = OCTOBER;
    }
    else if (Month == "November") {
        M = NOVEMBER;
    }
    else if (Month == "December") {
        M = DECEMBER;
    }
}

void Tree::Out_Data(string Name, Habitation H, ofstream& ofst) {
    ofst << "It's a tree with name: " << Name << endl;
    ofst << "Tree's age is " << Age << endl;
    ofst << "Tree's habitation is ";

    if (H == TUNDRA) {
        ofst << "Tundra";
    }
    else if (H == DESERT) {
        ofst << "Desert";
    }
    else if (H == STEPPE) {
        ofst << "Steppe";
    }
    else if (H == TAIGA) {
        ofst << "Taiga";
    }

    ofst << endl << endl;
}

void Shrub::Out_Data(string Name, Habitation H, ofstream& ofst) {
    ofst << "It's a shrub with name: " << Name << endl;
    ofst << "Shrub's flowering month is ";

    if (M == JENUARY) {
        ofst << "Jenuary";
    }
    else if (M == FEBRUARY) {
        ofst << "February";
    }
    else if (M == MARCH) {
        ofst << "March";
    }
    else if (M == APRIL) {
        ofst << "April";
    }
    else if (M == MAY) {
        ofst << "May";
    }
    else if (M == JUNE) {
        ofst << "June";
    }
    else if (M == JULY) {
        ofst << "July";
    }
    else if (M == AUGUST) {
        ofst << "August";
    }
    else if (M == SEPTEMBER) {
        ofst << "September";
    }
    else if (M == OCTOBER) {
        ofst << "October";
    }
    else if (M == NOVEMBER) {
        ofst << "November";
    }
    else if (M == DECEMBER) {
        ofst << "December";
    }

    ofst << endl;

    ofst << "Shrub's habitation is ";

        if (H == TUNDRA) {
            ofst << "Tundra";
        }
        else if (H == DESERT) {
            ofst << "Desert";
        }
        else if (H == STEPPE) {
            ofst << "Steppe";
        }
        else if (H == TAIGA) {
            ofst << "Taiga";
        }

    ofst << endl << endl;
}