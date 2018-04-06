#include <iostream>
#include "Avl.h"

using namespace std;
int main()
{
    ArbolAvl* arbol = new ArbolAvl();
    int opc;
    do
    {
        int opc2,opc3;
        int existe;
        string archivoData;
        char lastName[30],name[30];
        short int mes,year;
        registroP nuevo;
        cout<<"*****Menu Principal*****"<<endl;
        cout<<"*****Daniel Medina******"<<endl;
        cout<<"*****Estructura de Datos 2******"<<endl;

        cout<<"1. Nuevos registros\n2.Busquedas\n3.Eliminar Apellido"<<endl;
        cout<<"4.Imprimir\n5.Salir"<<endl;
        cout<<"Escoja una opcion: ";
        cin>>opc;
        switch (opc)
        {
            case  1:
                cout<<"1. Manual\n2. Automatica"<<endl;
                cout<<"Eliga su opcion: ";
                cin>>opc2;
                if(opc2 == 1)
                {
                    cout<<"Ingrese los datos: "<<endl;
                    cout<<"id: ";
                    cin>>nuevo.id;
                    cout<<"name: ";
                    cin>>nuevo.name;
                    cout<<"lastname: ";
                    cin>>nuevo.lastName;
                    cout<<"credit Card: ";
                    cin>>nuevo.credit_card;
                    cout<<"date(dd/mm/yyyy): ";
                    cin>>nuevo.date;
                    cout<<"day: ";
                    cin>>nuevo.day;
                    cout<<"month: ";
                    cin>>nuevo.month;
                    cout<<"year: ";
                    cin>>nuevo.year;
                    cout<<"payment Type: ";

                    cin>>nuevo.payment_type;
                    cout<<"total: ";
                    cin>>nuevo.total;
                    cout<<"business type: ";
                    cin>>nuevo.business_type;
                    cout<<"business name: ";
                    cin>>nuevo.business_name;
                    arbol->agregarNuevoRegistro(nuevo);
                }
                else if(opc2 == 2)
                {
                    cout<<"Escriba el nombre del archivo: ";
                    cin>>archivoData;
                    arbol->cargarArbolDe(archivoData);
                }
                else
                {
                    cout<<"Esa no es una opcion!!"<<endl;
                }
                break;
            case  2:
                cout<<"1.Buscar Apellido 2.Buscar Apellido y el nombre mas Imprimir registros ";
                cout<<"3.Buscar Registros por Mes y anio|imprimirlos todos"<<endl;
                cout<<"Escoja su opcion: ";
                cin>>opc2;
                if(opc2 == 1)
                {
                    cout<<"Escriba el apellido: ";
                    cin>>lastName;
                    arbol->m->imprimirConApellido(lastName,arbol->rs);
                }
                else if(opc2 == 2)
                {
                    cout<<"Escriba el Nombre ";
                    cin>>name;
                    cout<<"Escriba el apellido  ";
                    cin>>lastName;
                    int pos = arbol->m->buscar(name,lastName,arbol->rs);
                    if(pos == -1)
                        cout<<"No se encuentra ese registro con ese nombre y el apellido"<<endl;
                    else
                    {
                        listaNombre tmp = arbol->m->getItem(pos);
                        cout<<"ff"<<name<<" "<<lastName<<endl;
                        arbol->m->managerRepetidos->imprimirPosYSiguientes(tmp.posPrimerListaRepe);

                    }
                }
                else if(opc2 == 3)
                {
                    cout<<"Ingrese el numero del mes a imprimir(1-12) ";
                    cin>>mes;
                    cout<<"Ingrese el numero del anio a imprimir ";
                    cin>>year;
                    arbol->imprimirRegistrosMesYear(mes,year);
                }
                else
                {
                    cout<<"Vuelva Intentar!!"<<endl;
                }
                break;
            case  3:
                cout<<"Escriba para eliminar el apellido del nodo   ";
                cin>>lastName;
                arbol->eliminar(lastName);
                break;
            case  4:
                cout<<"1.Print arbol\n2. Print Sub arbol"<<endl;
                cout<<"Escoja una opcion opcion: ";
                cin>>opc2;
                if(opc2 == 1)
                {
                    cout<<"1.InOrder\n2.PreOrder\n3.postOrder"<<endl;
                    cout<<"Escoja una opcion: ";
                    cin>>opc3;
                    if(opc3 == 1)
                        arbol->InOrder();
                    else if(opc3 == 2)
                        arbol->PreOrder();
                    else if(opc3 == 3)
                        arbol->PosOrder();
                    else
                        cout<<"Vuelva a intentarlo!"<<endl;

                }
                else if(opc2 == 2 )
                {
                    cout<<"Escriba el apellido a partir del cual desea imprimir el subArbol  ";
                    cin>>lastName;
                    existe = arbol->buscar(lastName);
                    if(existe != -1)
                    {
                        cout<<"1. InOrder\n2. PreOrder\n3. postOrder"<<endl;
                        cout<<"Escoja su opcion: ";
                        cin>>opc3;
                        if(opc3 == 1)
                            arbol->InOrder(lastName);
                        else if(opc3 == 2)
                            arbol->PreOrder(lastName);
                        else if(opc3 == 3)
                            arbol->PosOrder(lastName);
                        else
                            cout<<"Vuelva a intentarlo!"<<endl;
                    }
                    else
                    {
                        cout<<"No se encuentra ese apellido!!"<<endl;
                    }
                }
                else
                {
                    cout<<"Vuelva a intentarlo!!"<<endl;
                }
                break;
        }
    }while(opc != 5);
    return 0;
}