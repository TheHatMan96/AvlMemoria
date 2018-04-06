//
// Created by ultim on 4/2/2018.
//
#include "avl.h"
#include "Nodo.h"
#include <stdio.h>
#include <string.h>

avl :: avl(){
    h=0;

};

int avl ::maxValue(int a, int b) {

    return (a < b) ? a:b;

}

void avl ::rd_Izq(Nodo **sr) {
    rs_Der(&((*sr)->hijoderecho));
    rs_Izq(sr);
}

void avl :: rd_Der(Nodo ** sr){
    rs_Der(&((*sr)->hijoizquierdo));
    rs_Der(sr);

}

void avl :: rs_Der(Nodo ** sr){
    Nodo * hi = (*sr)->hijoizquierdo;
    (*sr)->hijoizquierdo = hi->hijoderecho;
    hi->hijoderecho=*sr;
    (*sr)=hi;
}

void avl :: rs_Izq(Nodo ** sr){
    Nodo * hd =(*sr)->hijoderecho;
    (*sr)->hijoderecho = hd->hijoizquierdo;
    hd->hijoizquierdo = *sr;
    (*sr)=hd;
}

void avl ::  balanceo(Nodo ** sr){
    int alturaIzq = (*sr)->tamizq;
    int alturaDer = (*sr)->tamder;

    if((alturaIzq - alturaDer) == 2){
        Nodo *__hi = (*sr)->hijoizquierdo;
        if(__hi->tamizq >= __hi->tamder)
            rs_Der(sr);
        else
            rd_Der(sr);
    }else if(alturaIzq -alturaDer == -2){
        Nodo * __hd = (*sr)->hijoderecho;
        if(__hd->tamizq <= __hd->tamder)
            rs_Izq(sr);
        else
            rd_Izq(sr);
    }
}

int avl :: insertar(Nodo ** sr, Nodo * nuevo ){
    if(*sr== NULL){
        *sr=nuevo;
        return 0;
    }
    if((*sr)->value > nuevo->value){
        h = insertar(&((*sr)->hijoizquierdo),nuevo);
        (*sr)->tamizq = h+1;
    }else{
        h = insertar(&((*sr)->hijoderecho),nuevo);
        (*sr)->tamder = h+1;
    }
    balanceo(sr);
    return maxValue((*sr)->tamizq,(*sr)->tamder);
}



