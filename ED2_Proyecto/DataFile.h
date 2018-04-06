//
// Created by ultim on 4/5/2018.
//

#ifndef ED2_PROYECTO_DATAFILE_H
#define ED2_PROYECTO_DATAFILE_H


#include <fstream>
#include <cstring>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class DataFile
{
public:
    DataFile(char* direccion);
    void open();
    void close();
    void write(char* i,int pos,int b);
    void lastToWrite(char* i, int b);
    char* read(int pos, int b);
    int getEndingPos();

    char* dir;
    ofstream* tmp;
};



#endif //ED2_PROYECTO_DATAFILE_H
