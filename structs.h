//
// Created by ultim on 4/5/2018.
//

#include <iostream>
#include <string.h>
#include "DataFile.h"

#ifndef ED2_PROYECTO_STRUCTS_H
#define ED2_PROYECTO_STRUCTS_H


class structs {
public:

public:
    char lastName[30];
    structs* hijo_derecho;
    structs* hijo_izquierdo;
    int alturaIzq;
    int alturaDer;
    int posRegisListaNombre;
    structs(char lastName[30])
    {
        hijo_derecho = NULL;
        hijo_izquierdo = NULL;
        strcpy(this->lastName,lastName);
        alturaDer = 0;
        alturaIzq = 0;
        this->posRegisListaNombre = -1;
    }
};

struct registroArbol
{
    char lastName[30];
    int hijo_derecho = -1;
    int hijo_izquierdo = -1;
    int posRegisListaNombre = -1;
};

struct registroP
{
    int id;
    char name[30];
    char lastName[30];
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

struct listaNombre
{
    char lastName[30];
    char name[30];
    int siguiente = -1;
    int posPrimerListaRepe = -1;
};

struct listaRepetidos
{
    int posRegisDatab = -1;
    int siguiente = -1;
};

#endif //ED2_PROYECTO_STRUCTS_H
