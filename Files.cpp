//
// Created by ultim on 4/2/2018.
//

#include "Files.h"
#include <stdio.h>

Files::Files( char* file){
    this->path = file;
    this->fp = NULL;
}

void Files::Open() {
    if( strlen( this->path ) ){
        this->fp = fopen( this->path, "r+" );
    }
}

void Files::Close() {
    if( this->fp ){
        fclose( this->fp );
    }
}

void Files::Write( int offset, char* data, int size ) {
    if( this->fp ){
        fseek( this->fp, offset, SEEK_SET );
        fwrite( data, size, 1, this->fp );
    }
}

char* Files::Read( int offset, int size ) {
    char* data = new char( size );
    if( this->fp ){
        fseek( this->fp, offset, SEEK_SET );
        fread( data, 1, size, this->fp );
    }
    return data;
}

void Files::format() {
    if( strlen( this->path ) ){
        this->fp = fopen( this->path, "w+" );
        fseek( this->fp, 1024*3, SEEK_SET );
        fputc( '\0', this->fp );
        this->Close();
    }
}

bool Files::fileExist() {
    FILE* fpe;
    if( (fpe = fopen( this->path, "r" ) ) ){
        fclose( fpe );
        return true;
    }
    return false;
}

