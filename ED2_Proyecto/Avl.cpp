//
// Created by ultim on 4/5/2018.
//

#include "Avl.h"
#include "structs.h"
#include "ManejarAvl.h"

Avl::Avl() {
    _raiz = NULL;
    manager = new ManagerListaNombre();
    char* fileName = new char[strlen("AVL_Apellido.dat")];
    memcpy(fileName,"AVL_Apellido.dat",strlen("AVL_Apellido.dat"));
    DataFile *file = new DataFile(fileName);
    delete[] fileName;
    ifstream f("AVL_Apellido.dat");
    if(f)
    {
        cargarArbol();
    }
    else
    {
        file->open();
    }
}

void Avl::printRegistro(registroP rp) {
    cout<<"***********"<<endl;
    cout<<"Name: "<<x.name<<endl;
    cout<<"LastName: "<<x.lastName<<endl;
    cout<<"CreditCard: "<<x.credit_card<<endl;
    cout<<"Date: "<<x.date<<endl;
    cout<<"Date2: "<<x.day<<"/"<<x.month<<"/"<<x.year<<endl;
    cout<<"PaymentType: "<<x.payment_type<<endl;
    cout<<"Total: "<<x.total<<endl;
    cout<<"BusinessType: "<<x.business_type<<endl;
    cout<<"BusinessName: "<<x.business_name<<endl;
}

void Avl::prueba() {
    int i = 0;
    int cantRegis = (file->getPosFinal()-4)/44;
    cout<<"----------------------------------"<<endl;
    cout<<"Padre actual: "<<getRegistroArbol(*file,charToInt(file->leer(0,4))).lastName<<" pos: "<<charToInt(file->leer(0,4)) <<endl;
    bool cont = true;
    while(cont)
    {
        registroArbol act = getRegistroArbol(*file,i);
        int izq = act.hijo_izquierdo;
        int der = act.hijo_derecho;
        registroArbol lastIzq,lastDer;
        cout<<i<<". "<<act.lastName<<" sus hijos son: izq  "<<izq<<" der  "<<der<<" posRegisNombre: "<<act.posRegisListaNombre<<endl;
}

registroArbol Avl::getRarbol(DataFile f, int pos) {
    return registroArbol();
}

char *Avl::readAVL(int i, int cantidad, char *read) {
    return nullptr;
}

char *Avl::getlastname(DataFile f, int pos) {
    return nullptr;
}

char *Avl::getname(DataFile, int pos) {
    return nullptr;
}

registroP Avl::getRegistro(int pos) {
    return registroP();
}

void Avl::nuevoRegistro(registroP rp) {

}

void Avl::agregarNodo(structs *n) {

}

int Avl::buscar(char *end) {
    return 0;
}

int Avl::primerposicionlistas(char *end, structs *r) {
    return 0;
}

void Avl::PreOrder() {

}

void Avl::PreOrder(char *end) {

}

void Avl::PosOrder() {

}

void Avl::PosOrder(char *end) {

}

void Avl::InOrder() {

}

void Avl::InOrder(char *end) {

}

void Avl::RegistroMesAnio() {

}

void Avl::cargarArbolDe(string name) {

}

void Avl::eliminar(char *end) {

}

void Avl::save() {

}

void Avl::cargarArbol() {

}

structs *Avl::minimoDelNodo(structs *sr) {
    return nullptr;
}

structs *Avl::eliminarmas(char *end, structs **sr) {
    return nullptr;
}

void Avl::rotacion_der(structs **sr) {

}

void Avl::rotacion_izq(structs **sr) {

}

void Avl::RD_derecha(structs **sr) {

}

void Avl::RD_izquierda(structs **sr) {

}

void Avl::balanceo(structs **sr) {

}

structs *Avl::padrede(structs raiz, structs hijo) {
    return nullptr;
}

int Avl::abs(int x) {
    return 0;
}

int Avl::maximo(int x, int y) {
    return 0;
}

int Avl::agg(structs **sr, structs *nuevo) {
    return 0;
}

int Avl::buscar(char *las, structs *raiz) {
    return 0;
}

void Avl::imprimirArbolPre(structs *sb) {

}

void Avl::imprimirArbolPos(structs *sb) {

}

void Avl::imprimirArbolesIn(structs *sb) {

}

int Avl::charToInt(char *x) {
    return 0;
}

int Avl::cargarHijos(structs raiz, structs **ri) {
    return 0;
}

void Avl::actualizarHijosFile(structs *sr, structs *hijo_der, structs *hijo_izq) {

}

void Avl::getposfromfile(DataFile f, char *end) {

}
