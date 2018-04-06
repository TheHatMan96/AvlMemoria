//
// Created by ultim on 4/2/2018.
//

#ifndef FINALPROYECT_FILES_H
#define FINALPROYECT_FILES_H


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>


class Files {

public:
    FILE* fp;
    char* path;
    Files(char* file);
    void Open();
    void Close();
    void format();
    bool fileExist();
    void Write( int offset, char* data, int size );
    char* Read( int offset, int size );
};


#endif //FINALPROYECT_FILES_H
