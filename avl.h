//
// Created by ultim on 4/2/2018.
//

#ifndef FINALPROYECT_AVL_H
#define FINALPROYECT_AVL_H


#ifndef ARBOLAVL_AVL_H
#define ARBOLAVL_AVL_H

#include "Nodo.h"
#include "Files.h"



class avl {

public:

    avl();

    Nodo * path;
    Files *archivo;
    int h;
    int maxValue(int a , int b);
    void rd_Izq(Nodo ** sr);
    void rd_Der(Nodo **sr);
    void rs_Izq(Nodo **sr);
    void rs_Der(Nodo **sr);
    void balanceo(Nodo **sr);
    int insertar(Nodo **sr, Nodo *nuevo);
    Nodo *search(int num);
    void add(int num);
    Nodo * searchp(int n, int m);
    int getRoot();
    void setRoot(int root);
};


#endif //FINALPROYECT_AVL_H
