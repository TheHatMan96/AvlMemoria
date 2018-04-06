//
// Created by ultim on 4/5/2018.
//

#ifndef ED2_PROYECTO_MANEJARAVL_H
#define ED2_PROYECTO_MANEJARAVL_H

#include "Avl.h"
#include "RegistroRepetidos.h"

class ManejarAvl
{
public:
    DataFile* file;
    RegistroRepetidos* managerRepetidos;
    ManejarAvl()
    {
        char* fileName = new char[strlen("Lista_Nombre.dat")];
        memcpy(fileName,"Lista_Nombre.dat",strlen("Lista_Nombre.dat"));
        file = new DataFile(fileName);
        //file->
        managerRepetidos = new RegistroRepetidos();
        delete[] fileName;
    }
    void imprimirTodo()
    {
        ifstream f("Lista_Nombre.dat");
        if(f)
        {
            int cantRegis = file->getEndingPos()/sizeof(listaNombre);
            cout<<"Elementos en Lista_Nombre.dat: "<<endl;
            for(int i = 0; i < cantRegis; i++)
            {
                listaNombre tmp = getItem(i);
                cout<<i<<". "<<tmp.name<<" "<<tmp.lastName<<" Sig:"<<tmp.siguiente<<endl;
            }
        }
    }
    void imprimirConApellido(char lastName[30],structs* raiz)
    {
        listaNombre n;
        ifstream f("Lista_Nombre.dat");
        if(f)
        {
            int posLastName = buscarApellido(lastName,raiz);
            if(posLastName != -1)
            {
                cout<<"\t\t*****Apellido: "<<lastName<<"*****"<<endl;
                listaNombre tmp = getItem(posLastName);
                while(tmp.siguiente != -1)
                {
                    cout<<"\t\t"<<posLastName<<". "<<tmp.name<<" "<<tmp.lastName<<" Sig:"<<tmp.siguiente;
                    cout<<" PosPrimerListaRepe "<<tmp.posPrimerListaRepe<<endl;
                    posLastName = tmp.siguiente;
                    tmp = getItem(tmp.siguiente);
                }
                cout<<"\t\t"<<posLastName<<". "<<tmp.name<<" "<<tmp.lastName<<" Sig:"<<tmp.siguiente;
                cout<<" PosPrimerListaRepe "<<tmp.posPrimerListaRepe<<endl;
            }
            else
            {
                cout<<"\t\tNo existe este apellido"<<endl;
            }
        }
    }
    listaNombre getItem(int pos)
    {
        listaNombre n;
        ifstream f("Lista_Nombre.dat");
        if(f)
        {
            int cantRegis = file->getEndingPos()/sizeof(listaNombre);
            if(pos >= cantRegis)
                return n;
            int posPuntero =  pos*sizeof(listaNombre);
            memcpy(n.lastName,file->read(posPuntero,sizeof(n.lastName)),sizeof(n.lastName));
            posPuntero+= sizeof(n.lastName);
            memcpy(n.name,file->read(posPuntero,sizeof(n.name)),sizeof(n.name));
            posPuntero+= sizeof(n.name);
            memcpy(&n.siguiente,file->read(posPuntero,sizeof(int)),sizeof(int));
            posPuntero+= sizeof(int);
            memcpy(&n.posPrimerListaRepe,file->read(posPuntero,sizeof(int)),sizeof(int));
        }
        return n;
    }
    char* getLastName(int pos)
    {
        int posPuntero =  pos*sizeof(listaNombre);
        char* lastName = file->read(posPuntero,30);
        return lastName;
    }
    char* getName(int pos)
    {
        int posPuntero =  pos*sizeof(listaNombre)+30;
        char* name = file->read(posPuntero,30);
        return name;
    }
    //esta funcion buscar retornara la posicion donde se encuentra ese item en caso de encontrarlo
    int buscar(char name [30],char lastName[30],structs* raiz)
    {
        ifstream f("Lista_Nombre.dat");
        if(f)
        {
            int buscaApellido = buscarApellido(lastName,raiz);
            if(buscaApellido == -1)
            {
                return -1;
            }
            else
            {
                listaNombre temp = getItem(buscaApellido);
                bool cont = true;
                while(cont)
                {
                    if(strcmp(temp.name,name) == 0)
                    {
                        return buscaApellido;
                    }
                    else
                    {
                        if(temp.siguiente == -1)
                        {
                            cont = false;
                        }
                        else
                        {
                            buscaApellido = temp.siguiente;
                            temp = getItem(temp.siguiente);
                        }
                    }

                }
            }

        }
        return -1;
    }
    int getLastPos()
    {
        ifstream f("Lista_Nombre.dat");
        if(f)
        {
            int cantRegis = file->getEndingPos()/sizeof(listaNombre);
            return (cantRegis-1);
        }
        return -1;
    }

    int buscarApellido(char lastName[30],structs* raiz)
    {
        ifstream f("Lista_Nombre.dat");
        if(f)
        {
            return buscarApelli(lastName,raiz);
        }
        return -1;
    }
    int buscarApelli(char last[30],structs* raiz)
    {
        if(raiz == NULL)
            return -1;
        if(strcmp(last,raiz->lastName) == 0)
        {
            return raiz->posRegisListaNombre;
        }
        if(strcmp(last,raiz->lastName) > 0 )
            return buscarApelli(last,raiz->hijo_derecho);
        return buscarApelli(last,raiz->hijo_izquierdo);
    }
    void actualizarItemSiguiente(int posItem,int siguiente)
    {
        listaNombre itm = getItem(posItem);
        itm.siguiente = siguiente;
        int setOff = (posItem*sizeof(listaNombre));
        file->write(reinterpret_cast<char*>(&itm),setOff,sizeof(listaNombre));
    }
    void agregarNuevo(listaNombre nuevo,int posRegisDataB,structs* raiz)
    {
        int busqueda = buscar(nuevo.name,nuevo.lastName,raiz);
        if(busqueda == -1)
        {
            //fin agregar repetidos
            listaRepetidos* nuevoRepe = new listaRepetidos;
            nuevoRepe->posRegisDatab = posRegisDataB;
            nuevo.posPrimerListaRepe = managerRepetidos->getUltimoPosActual()+1;
            managerRepetidos->agregarNuevo(*nuevoRepe);
            delete nuevoRepe;
            //fin agregar repetidos
            int buscaApellido = buscarApellido(nuevo.lastName,raiz);
            if(buscaApellido != -1)
            {
                listaNombre tmp = getItem(buscaApellido);
                int posItemActualizar = buscaApellido;
                while(tmp.siguiente != -1)
                {
                    tmp = getItem(tmp.siguiente);
                    posItemActualizar = tmp.siguiente;
                }
                int posFinal = file->getEndingPos()/sizeof(listaNombre);
                actualizarItemSiguiente(posItemActualizar,posFinal);
                file->lastToWrite(reinterpret_cast<char*>(&nuevo),sizeof(listaNombre));
            }
            else
            {
                file->lastToWrite(reinterpret_cast<char*>(&nuevo),sizeof(listaNombre));
            }
        }
        else
        {
            //aca debe ir lo que se hara de guardar en el archivo de repetidos
            // ya que si entra aca, significa que ya existe un registro con ese
            //nombre y con ese apellido
            listaNombre tmp = getItem(busqueda);
            int temp = tmp.posPrimerListaRepe;
            int itmActualizar = temp;
            bool cont = true;
            while(cont)
            {
                listaRepetidos x = managerRepetidos->getItem(temp);
                if(x.siguiente == -1)
                {
                    itmActualizar = temp;
                    cont = false;
                    break;
                }
                else
                {
                    temp = x.siguiente;
                }

            }
            managerRepetidos->actualizarItemSiguiente(itmActualizar,managerRepetidos->getUltimoPosActual()+1);
            listaRepetidos* tmpNe = new listaRepetidos;
            tmpNe->posRegisDatab = posRegisDataB;
            managerRepetidos->agregarNuevo(*tmpNe);
            delete tmpNe;

        }
    }

};


#endif //ED2_PROYECTO_MANEJARAVL_H
