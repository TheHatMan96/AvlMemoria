//
// Created by ultim on 4/2/2018.
//

#ifndef FINALPROYECT_NODO_H
#define FINALPROYECT_NODO_H


#include "Files.h"

using namespace std;

class Nodo {
public:

    Nodo(int n);

    int value;
    int key;
    Nodo * hijoizquierdo;
    Nodo * hijoderecho;
    int tamizq;
    int tamder;

    char * toChar();
    void initFromChar(char* data);
    void save(Files * archivo);
    void cargar(int i , Files * archivo);
    Nodo * initAuxiliar(char * data, int pos);


};


#endif //FINALPROYECT_NODO_H
