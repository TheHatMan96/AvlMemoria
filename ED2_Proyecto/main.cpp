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

        cout<<"1.Insertar Nuevos registros\n2.Busquedas\n3.Eliminar Nodo(Apellido)"<<endl;
        cout<<"4.Imprimir\n5.Salir"<<endl;
        cout<<"Escriba el numero de su eleccion: ";
        cin>>opc;
        switch (opc)
        {
            case  1:
                cout<<"\t1.Insercion Manual\n\t2.Insercion Automatica"<<endl;
                cout<<"\tEliga su opcion: ";
                cin>>opc2;
                if(opc2 == 1)
                {
                    cout<<"\t\tA continuacion ingrese lo que se le vaya solicitando: "<<endl;
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
                    cout<<"\tEscriba el nombre del archivo del cual se cargaran los regsitros: ";
                    cin>>archivoData;
                    arbol->cargarArbolDe(archivoData);
                }
                else
                {
                    cout<<"\tLo sentimos esa no es ninguna opcion!!"<<endl;
                }
                break;
            case  2:
                cout<<"\t1.Buscar Apellido e imprimir nombres\n\t2.Buscar por Apellido y Nombre e Imprimir registros en datab.dat";
                cout<<"\n\t3.Buscar Registros por Mes y ano e imprimirlos todos"<<endl;
                cout<<"\tEscoja su opcion: ";
                cin>>opc2;
                if(opc2 == 1)
                {
                    cout<<"\t\tEscriba el apellido que desea buscar e imprimir: ";
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
                        cout<<"\tNo hay registros que coincidan con ese nombre y apellido"<<endl;
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
                    cout<<"\n\tIngrese el numero del ano a imprimir(yyyy) ";
                    cin>>year;
                    arbol->imprimirRegistrosMesYear(mes,year);
                }
                else
                {
                    cout<<"\tLo siento esa no es una opcion valida!!"<<endl;
                }
                break;
            case  3:
                cout<<"\tEscriba el apellido del nodo a eliminar  ";
                cin>>lastName;
                arbol->eliminar(lastName);
                break;
            case  4:
                cout<<"\t1.Imprimir todo el arbol\n\t2.Imprimir Sub arbol"<<endl;
                cout<<"\tEscoja su opcion: ";
                cin>>opc2;
                if(opc2 == 1)
                {
                    cout<<"\t\t1.Imprimir InOrder\n\t\t2.Imprimir PreOrder\n\t\t3.Imprimir postOrder"<<endl;
                    cout<<"\t\tEscoja su opcion: ";
                    cin>>opc3;
                    if(opc3 == 1)
                        arbol->imprimirInOrder();
                    else if(opc3 == 2)
                        arbol->imprimirPreOrder();
                    else if(opc3 == 3)
                        arbol->imprimirPosOrder();
                    else
                        cout<<"\t\tLo siento esa no es una opcion valida!!"<<endl;

                }
                else if(opc2 == 2 )
                {
                    cout<<"\tEscriba el apellido a partir del cual desea imprimir el subArbol  ";
                    cin>>lastName;
                    existe = arbol->buscar(lastName);
                    if(existe != -1)
                    {
                        cout<<"\t\t1.Imprimir InOrder\n\t\t2.Imprimir PreOrder\n\t\t3.Imprimir postOrder"<<endl;
                        cout<<"\t\tEscoja su opcion: ";
                        cin>>opc3;
                        if(opc3 == 1)
                            arbol->imprimirInOrder(lastName);
                        else if(opc3 == 2)
                            arbol->imprimirPreOrder(lastName);
                        else if(opc3 == 3)
                            arbol->imprimirPosOrder(lastName);
                        else
                            cout<<"\t\tLo siento esa no es una opcion valida!!"<<endl;
                    }
                    else
                    {
                        cout<<"\tNo existe ningun apellido que coincida!!"<<endl;
                    }
                }
                else
                {
                    cout<<"\tLo siento esa no es una opcion valida!!"<<endl;
                }
                break;
        }
    }while(opc != 5);
    return 0;
}