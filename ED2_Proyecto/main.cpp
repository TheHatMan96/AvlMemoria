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
        cout<<"\n*****Menu Principal*****"<<endl;
        cout<<"\n*****Daniel Medina******"<<endl;
        cout<<"\n*****Estructura de Datos 2******"<<endl;

        cout<<"1. Nuevos registros\n2.Busquedas\n3.Eliminar Apellido"<<endl;
        cout<<"4.Imprimir\n5.Salir"<<endl;
        cout<<"Escoja una opcion: ";
        cin>>opc;
        switch (opc)
        {
            case  1:
                cout<<"1. Manual\n\t2. Automatica"<<endl;
                cout<<"Eliga su opcion: ";
                cin>>opc2;
                if(opc2 == 1)
                {
                    cout<<"\tIngrese los datos: "<<endl;
                    cout<<"\tid: ";
                    cin>>nuevo.id;
                    cout<<"\tname: ";
                    cin>>nuevo.name;
                    cout<<"\tlastname: ";
                    cin>>nuevo.lastName;
                    cout<<"\tcredit Card: ";
                    cin>>nuevo.credit_card;
                    cout<<"\tdate(dd/mm/yyyy): ";
                    cin>>nuevo.date;
                    cout<<"\tday: ";
                    cin>>nuevo.day;
                    cout<<"\tmonth: ";
                    cin>>nuevo.month;
                    cout<<"\tyear: ";
                    cin>>nuevo.year;
                    cout<<"\tpayment Type: ";
                    cin>>nuevo.payment_type;
                    cout<<"\ttotal: ";
                    cin>>nuevo.total;
                    cout<<"\tbusiness type: ";
                    cin>>nuevo.business_type;
                    cout<<"\tbusiness name: ";
                    cin>>nuevo.business_name;
                    arbol->agregarNuevoRegistro(nuevo);
                }
                else if(opc2 == 2)
                {
                    cout<<"\tEscriba el nombre del archivo: ";
                    cin>>archivoData;
                    arbol->cargarArbolDe(archivoData);
                }
                else
                {
                    cout<<"\tEsa no es una opcion!!"<<endl;
                }
                break;
            case  2:
                cout<<"\t1.Buscar Apellido \n2.Buscar Apellido y el nombre mas Imprimir registros ";
                cout<<"\n3.Buscar Registros por Mes y anio|imprimirlos todos"<<endl;
                cout<<"\tEscoja su opcion: ";
                cin>>opc2;
                if(opc2 == 1)
                {
                    cout<<"\t\tEscriba el apellido: ";
                    cin>>lastName;
                    arbol->manager->imprimirConApellido(lastName,arbol->_raiz);
                }
                else if(opc2 == 2)
                {
                    cout<<"\tEscriba el Nombre ";
                    cin>>name;
                    cout<<"\tEscriba el apellido  ";
                    cin>>lastName;
                    int pos = arbol->manager->buscar(name,lastName,arbol->_raiz);
                    if(pos == -1)
                        cout<<"\tNo se encuentra ese registro con ese nombre y el apellido"<<endl;
                    else
                    {
                        listaNombre tmp = arbol->manager->getItem(pos);
                        cout<<"\t\t"<<name<<" "<<lastName<<endl;
                        arbol->manager->managerRepetidos->imprimirPosYSiguientes(tmp.posPrimerListaRepe);

                    }
                }
                else if(opc2 == 3)
                {
                    cout<<"\tIngrese el numero del mes a imprimir(1-12) ";
                    cin>>mes;
                    cout<<"\nIngrese el numero del anio a imprimir ";
                    cin>>year;
                    arbol->imprimirRegistrosMesYear(mes,year);
                }
                else
                {
                    cout<<"\tVuelva Intentar!!"<<endl;
                }
                break;
            case  3:
                cout<<"\tEscriba para eliminar el apellido del nodo   ";
                cin>>lastName;
                arbol->eliminar(lastName);
                break;
            case  4:
                cout<<"\t1.Print arbol\n\t2. Print Sub arbol"<<endl;
                cout<<"\tEscoja una opcion opcion: ";
                cin>>opc2;
                if(opc2 == 1)
                {
                    cout<<"\t1.InOrder\n\t2.PreOrder\n\t3.postOrder"<<endl;
                    cout<<"\t\tEscoja una opcion: ";
                    cin>>opc3;
                    if(opc3 == 1)
                        arbol->imprimirInOrder();
                    else if(opc3 == 2)
                        arbol->imprimirPreOrder();
                    else if(opc3 == 3)
                        arbol->imprimirPosOrder();
                    else
                        cout<<"\t\tVuelva a intentarlo!"<<endl;

                }
                else if(opc2 == 2 )
                {
                    cout<<"\tEscriba el apellido a partir del cual desea imprimir el subArbol  ";
                    cin>>lastName;
                    existe = arbol->buscar(lastName);
                    if(existe != -1)
                    {
                        cout<<"\t1. InOrder\n\t2. PreOrder\n\t3. postOrder"<<endl;
                        cout<<"\tEscoja su opcion: ";
                        cin>>opc3;
                        if(opc3 == 1)
                            arbol->imprimirInOrder(lastName);
                        else if(opc3 == 2)
                            arbol->imprimirPreOrder(lastName);
                        else if(opc3 == 3)
                            arbol->imprimirPosOrder(lastName);
                        else
                            cout<<"\t\tVuelva a intentarlo!"<<endl;
                    }
                    else
                    {
                        cout<<"\tNo se encuentra ese apellido!!"<<endl;
                    }
                }
                else
                {
                    cout<<"\tVuelva a intentarlo!!"<<endl;
                }
                break;
        }
    }while(opc != 5);
    return 0;
}