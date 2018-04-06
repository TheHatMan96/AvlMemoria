//
// Created by ultim on 4/5/2018.
//

#ifndef ED2_PROYECTO_REGISTROREPETIDOS_H
#define ED2_PROYECTO_REGISTROREPETIDOS_H


#include "Avl.h"
#include "DataFile.h"

class RegistroRepetidos
{
public:
    DataFile* file;
    RegistroRepetidos()
    {
        char* fileName = new char[strlen("Lista_Repetidos.dat")];
        memcpy(fileName,"Lista_Repetidos.dat",strlen("Lista_Repetidos.dat"));
        file = new DataFile(fileName);
        file->open();
        delete[] fileName;
    }
    void imprimirRegistro(int pos)
    {
        registroP x = getRegistroItem(pos);
        cout<<"\t\t***********"<<endl;
        cout<<"\t\tName: "<<x.name<<endl;
        cout<<"\t\tLastName: "<<x.lastName<<endl;
        cout<<"\t\tCreditCard: "<<x.credit_card<<endl;
        cout<<"\t\tDate: "<<x.date<<endl;
        cout<<"\t\tDate2: "<<x.day<<"/"<<x.month<<"/"<<x.year<<endl;
        cout<<"\t\tPaymentType: "<<x.payment_type<<endl;
        cout<<"\t\tTotal: "<<x.total<<endl;
        cout<<"\t\tBusinessType: "<<x.business_type<<endl;
        cout<<"\t\tBusinessName: "<<x.business_name<<endl;
    }
    registroP getRegistroItem(int pos)
    {
        char* fileName = new char[sizeof("datab.dat")];
        memcpy(fileName,"datab.dat",sizeof("datab.dat"));
        DataFile filee(fileName);
        delete[] fileName;
        registroP retorno;
        int posPuntero =  pos*sizeof(registroP);
        // retorno.id = charToInt(file.leer(posPuntero,sizeof(int)));
        memcpy(&retorno.id,filee.read(posPuntero,sizeof(int)),sizeof(int));
        posPuntero+=sizeof(int);
        memcpy(retorno.name,filee.read(posPuntero,sizeof(retorno.name)),sizeof(retorno.name));
        posPuntero+= sizeof(retorno.name);
        memcpy(retorno.lastName,filee.read(posPuntero,sizeof(retorno.lastName)),sizeof(retorno.lastName));
        posPuntero+= sizeof(retorno.lastName);
        memcpy(retorno.credit_card,filee.read(posPuntero,sizeof(retorno.credit_card)),sizeof(retorno.credit_card));
        posPuntero+= sizeof(retorno.credit_card);
        memcpy(retorno.date,filee.read(posPuntero,sizeof(retorno.date)),sizeof(retorno.date));
        posPuntero+= sizeof(retorno.date) +1;
        // retorno.day = charToInt(file.leer(posPuntero,sizeof(short int)));
        memcpy(&retorno.day,filee.read(posPuntero,sizeof(short int)),sizeof(short int));
        posPuntero+=sizeof(short int);
        // retorno.month = charToInt(file.leer(posPuntero,sizeof(short int)));
        memcpy(&retorno.month,filee.read(posPuntero,sizeof(short int)),sizeof(short int));
        posPuntero+=sizeof(short int);
        // retorno.year = charToInt(file.leer(posPuntero,sizeof(short int)));
        memcpy(&retorno.year,filee.read(posPuntero,sizeof(short int)),sizeof(short int));
        posPuntero+=sizeof(short int);
        memcpy(retorno.payment_type,filee.read(posPuntero,sizeof(retorno.payment_type)),sizeof(retorno.payment_type));
        posPuntero+= sizeof(retorno.payment_type)+2;
        strcpy(reinterpret_cast<char*>(&retorno.total),filee.read(posPuntero,sizeof(double)));
        posPuntero+=sizeof(double);
        memcpy(retorno.business_type,filee.read(posPuntero,sizeof(retorno.business_type)),sizeof(retorno.business_type));
        posPuntero+= sizeof(retorno.business_type);
        memcpy(retorno.business_name,filee.read(posPuntero,sizeof(retorno.business_name)),sizeof(retorno.business_name));
        posPuntero+= sizeof(retorno.business_name);
        return retorno;

    }
    void imprimirPosYSiguientes(int pos)
    {
        ifstream f("Lista_Repetidos.dat");
        if(f)
        {
            int cantRegis = file->getEndingPos()/sizeof(listaRepetidos);
            if(pos >= cantRegis)
                return;
            listaRepetidos temp = getItem(pos);

            while(temp.siguiente != -1)
            {
                imprimirRegistro(temp.posRegisDatab);
                temp = getItem(temp.siguiente);
            }
            imprimirRegistro(temp.posRegisDatab);


        }
    }
    listaRepetidos getItem(int pos)
    {
        listaRepetidos n;
        ifstream f("Lista_Repetidos.dat");
        if(f)
        {
            int cantRegis = file->getEndingPos()/sizeof(listaRepetidos);
            if(pos >= cantRegis)
                return n;
            int posPuntero =  pos*sizeof(listaRepetidos);
            memcpy(&n.posRegisDatab,file->read(posPuntero,sizeof(int)),sizeof(int));
            posPuntero+= sizeof(int);
            memcpy(&n.siguiente,file->read(posPuntero,sizeof(int)),sizeof(int));
        }
        return n;
    }
    void actualizarItemSiguiente(int posItem,int siguiente)
    {
        listaRepetidos itm = getItem(posItem);
        itm.siguiente = siguiente;
        int setOff = (posItem*sizeof(listaRepetidos));
        file->write(reinterpret_cast<char*>(&itm),setOff,sizeof(listaRepetidos));
    }
    void agregarNuevo(listaRepetidos nuevo)
    {
        file->lastToWrite(reinterpret_cast<char*>(&nuevo),sizeof(listaRepetidos));
    }
    int getUltimoPosActual()
    {
        ifstream f("Lista_Repetidos.dat");
        if(f)
        {
            int cantRegis = file->getEndingPos()/sizeof(listaRepetidos);
            return (cantRegis-1);
        }
        return -1;
    }

};


#endif //ED2_PROYECTO_REGISTROREPETIDOS_H
