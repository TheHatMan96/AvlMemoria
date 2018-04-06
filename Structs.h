//
// Created by ultim on 4/4/2018.
//

#ifndef FINALPROYECT_STRUCTS_H
#define FINALPROYECT_STRUCTS_H

#include <iostream>

using namespace std;
struct struct_repetidos{
    int codiog=-1;
    int pos_archivo=-1;
    int siguiente=-1;
};
struct struct_apellido{
    char lastname[20];
    int hijo_izquierdo=-1;
    int hijo_derecho=-1;
    int ptr_lista_nobre=-1;
};

struct
class Structs {
    int id;
    char name[30];
    char lastname[30];
    char credit_card[25];
    char date[12];
    short int day;
    short int month;
    short int year;
    char payment_type[10];
    double total;
    char business_type[20];
    char business_name[50];

};


#endif //FINALPROYECT_STRUCTS_H
