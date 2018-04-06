//
// Created by ultim on 4/2/2018.
//

#include "Nodo.h"
#include <string.h>
#include <stdio.h>
#include "Files.h"


Nodo::Nodo(int n){
    value=n;
    hijoizquierdo=0;
    hijoderecho=0;
    tamizq=0;
    tamder=0;
}

void Nodo::save( Files * archivo) {
    char* data = new char[ 30 ];
    archivo->Open();

    data = this->toChar();

    archivo->Write( ( this->key * 30 ) + 10, data, 30 );

    archivo->Close();
}

void Nodo::cargar(int i , Files *archivo) {

    char* data = new char[ 30 ];
    archivo->Open();

    data = archivo->Read( ( i * 30 ) + 10, 30 );

    initFromChar( data );

    archivo->Close();
}

void Nodo::initFromChar(char * data){
    int pos = 0;

}


char * Nodo::toChar(){


}


