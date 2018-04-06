//
// Created by ultim on 4/5/2018.
//

#ifndef ED2_PROYECTO_AVL_H
#define ED2_PROYECTO_AVL_H
#include "structs.h"

#include "structs.h"
#include "ManejarAvl.h"

class ArbolAvl
{
public:
    ArbolAvl()
    {
        _raiz = NULL;
        manager = new ManagerListaNombre();
        char* fileName = new char[strlen("AVL_Apellido.dat")];
        memcpy(fileName,"AVL_Apellido.dat",strlen("AVL_Apellido.dat"));
        //  file = new data_file(fileName);
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
    void imprimirRegistro(registroP x)
    {
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
    void prueba()
    {
        int i = 0;
        int cantRegis = (file->getEndingPos()-4)/44;
        cout<<"----------------------------------"<<endl;
        cout<<"Padre actual: "<<getRegistroArbol(*file,charToInt(file->read(0,4))).lastName<<" pos: "<<charToInt(file->read(0,4)) <<endl;
        bool cont = true;
        while(cont)
        {
            registroArbol act = getRegistroArbol(*file,i);
            int izq = act.hijo_izquierdo;
            int der = act.hijo_derecho;
            registroArbol lastIzq,lastDer;
            cout<<i<<". "<<act.lastName<<" sus hijos son: izq  "<<izq<<" der  "<<der<<" posRegisNombre: "<<act.posRegisListaNombre<<endl;

            i++;

            if(i >= cantRegis)
                cont = false;
        }
    }
    registroArbol getRegistroArbol(DataFile file, int pos)
    {
        registroArbol retorno;
        int posPuntero =  4 + (pos*sizeof(registroArbol));
        memcpy(retorno.lastName,file.read(posPuntero,sizeof(retorno.lastName)),sizeof(retorno.lastName));
        posPuntero += sizeof(retorno.lastName) + 2;
        memcpy(&retorno.hijo_derecho,file.read(posPuntero,sizeof(int)),4);
        posPuntero += sizeof(int);
        memcpy(&retorno.hijo_izquierdo,file.read(posPuntero,sizeof(int)),4);
        posPuntero += sizeof(int);
        memcpy(&retorno.posRegisListaNombre,file.read(posPuntero,sizeof(int)),4);
        return retorno;
    }
    char* readChar(int desde, int cantLeer,char* read)
    {
        char* ans = new char[cantLeer];
        int pos = 0;
        for(int i = desde +1; i <= (desde + cantLeer); i++)
        {
            ans[pos] = read[i];
            pos++;
        }
        return ans;

    }
    char* getLastNameRegis(DataFile file,int pos)
    {
        int posPuntero =  pos*sizeof(registroP)+34;
        char* lastName = file.read(posPuntero,30);
        return lastName;
    }
    char* getNameRegis(DataFile file,int pos)
    {
        int posPuntero =  pos*sizeof(registroP)+4;
        char* name = file.read(posPuntero,30);
        return name;
    }
    registroP getRegistroItem(int pos)
    {
        char* fileName = new char[sizeof("datab.dat")];
        memcpy(fileName,"datab.dat",sizeof("datab.dat"));
        DataFile filee(fileName);
        delete[] fileName;
        registroP retorno;
        int posPuntero =  pos*sizeof(registroP);
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
        memcpy(&retorno.day,filee.read(posPuntero,sizeof(short int)),sizeof(short int));
        posPuntero+=sizeof(short int);
        memcpy(&retorno.month,filee.read(posPuntero,sizeof(short int)),sizeof(short int));
        posPuntero+=sizeof(short int);
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
    void agregarNuevoRegistro(registroP nuevo)
    {
        char* arch = new char[sizeof("datab.dat")];
        memcpy(arch,"datab.dat",sizeof("datab.dat"));
        DataFile fileRegistros(arch);
        int i = fileRegistros.getEndingPos()/sizeof(registroP);
        fileRegistros.lastToWrite(reinterpret_cast<char*>(&nuevo),sizeof(registroP));
        listaNombre itmNew;
        memcpy(itmNew.name,nuevo.name,30);
        memcpy(itmNew.lastName,nuevo.lastName,30);
        manager->agregarNuevo(itmNew,i,_raiz);
        if(buscar(nuevo.lastName) == -1)
        {
            structs* nu = new structs(nuevo.lastName);
            nu->posRegisListaNombre = manager->getLastPos();
            agregarNodo(nu);
        }
    }
    void agregarNodo(structs* nuevo)
    {
        if(buscar(nuevo->lastName) != -1)
            return;
        if(_raiz != NULL)
        {
            char* last = new char[30];
            memcpy(last,_raiz->lastName,30);
            if(agg(&_raiz,nuevo) == -1)
            {
                delete[] last;
                return;
            }
            if(strcmp(last,_raiz->lastName) != 0)
            {
                int pos = getRegistroPosFromFile(*file,_raiz->lastName);
                file->write(reinterpret_cast<char*>(&pos),0,4);
            }
            delete[] last;

        }
        else
        {
            int pos = 0;
            file->open();
            file->write(reinterpret_cast<char*>(&pos),0,4);
            agg(&_raiz,nuevo);
        }
    }
    int buscar(char last[30])
    {
        if(_raiz == NULL)
            return -1;
        return buscar(last,&(*_raiz));
    }

    int buscarPrimerPosListaNombre(char last[30],structs* raiz)
    {
        if(raiz == NULL)
            return -1;
        if(strcmp(last,raiz->lastName) == 0)
            return raiz->posRegisListaNombre;
        if(strcmp(last,raiz->lastName) > 0 )
            return buscar(last,raiz->hijo_derecho);
        return buscar(last,raiz->hijo_izquierdo);
    }
    void imprimirPreOrder()
    {
        cout<<"\nDatos en el arbol[PreOrder]: \n";
        imprimirArbolPre(_raiz);
    }
    void imprimirPreOrder(char lastName[30])
    {
        cout<<"\nDatos en el subArbol[PreOrder]: "<<lastName<<endl;
        imprimirArbolPre(buscarR(lastName,_raiz));
    }
    void imprimirPosOrder()
    {
        cout<<"Datos en el arbol[PosOrder]: \n";
        imprimirArbolPos(_raiz);
    }
    void imprimirPosOrder(char lastName[30])
    {
        cout<<"\nDatos en el subArbol[PosOrder]: "<<lastName<<endl;
        imprimirArbolPos(buscarR(lastName,_raiz));
    }
    void imprimirInOrder()
    {
        cout<<"Datos en el arbol[InOrder]: \n";
        imprimirArbolIn(_raiz);
    }
    void imprimirInOrder(char lastName[30])
    {
        cout<<"\nDatos en el subArbol[InOrder]: "<<lastName<<endl;
        imprimirArbolIn(buscarR(lastName,_raiz));
    }
    void imprimirRegistrosMesYear(short int mes, short int year)
    {
        char* arch = new char[sizeof("datab.dat")];
        memcpy(arch,"datab.dat",sizeof("datab.dat"));
        DataFile fileRegistros(arch);
        int cantRegistros = fileRegistros.getEndingPos()/sizeof(registroP);
        cout<<"\tMes: "<<mes<<" Year: "<<year<<endl;
        for(int i = 0; i < cantRegistros; i++)
        {
            registroP temp = getRegistroItem(i);
            if(temp.month == mes && temp.year == year)
            {
                imprimirRegistro(temp);
            }
        }
    }

    void cargarArbolDe(string nameArchivo)
    {
        ifstream fi(nameArchivo.c_str());
        if(fi)
        {
            char* arch = new char[strlen(nameArchivo.c_str())];
            strcpy(arch,nameArchivo.c_str());
            DataFile fileRegistros(arch);
            int cantRegistros = fileRegistros.getEndingPos()/sizeof(registroP);
            structs* nuevo;
            int repes = 0;
            delete[] arch;
            for(int i = 0; i < cantRegistros; i++)
            {
                char* lastName = getLastNameRegis(fileRegistros,i);
                char* name = getNameRegis(fileRegistros,i);
                listaNombre itmNew;
                memcpy(itmNew.name,name,30);
                memcpy(itmNew.lastName,lastName,30);
                manager->agregarNuevo(itmNew,i,_raiz);
                if(buscar(lastName) == -1)
                {
                    nuevo = new structs(lastName);
                    nuevo->posRegisListaNombre = manager->getLastPos();
                    agregarNodo(nuevo);
                }
                else
                {
                    repes++;
                    cout<<"repetidos: "<<repes<<" - "<<lastName<<endl;
                }
                delete[] lastName;
                delete[] name;
            }
        }
    }
    void eliminar(char last[30])
    {
        if(buscar(last) == -1)
            return;
        elimi(last,&_raiz);
    }

    void guardarArbol()
    {
        int posInicial = -1;
        file->open();
        file->write(reinterpret_cast<char*>(&posInicial),0,sizeof(int));
        if(posInicial == -1)
            return;

    }
    DataFile* file;

    ManagerListaNombre* manager;
    structs* _raiz;
private:

    void cargarArbol()
    {
        int posRaiz = charToInt((*file).read(0,4));
        if(posRaiz == -1)
            return;
        registroArbol raiz = getRegistroArbol(*file,posRaiz);
        _raiz = new structs(raiz.lastName);
        cargarHijos(raiz,&_raiz);
    }

    structs* minNode(structs* sr)
    {
        structs* curr = sr;
        while(curr->hijo_izquierdo != NULL)
            curr = curr->hijo_izquierdo;
        return curr;
    }
    structs* elimi(char last[30], structs** sr)
    {
        if(*sr == NULL)
            return *sr;
        if(strcmp((*sr)->lastName,last) == 0)
        {
            structs* padre = padreDe(_raiz,*sr);
            if((*sr)->hijo_izquierdo == NULL || (*sr)->hijo_derecho == NULL)
            {
                structs* tmp = (*sr)->hijo_derecho != NULL?(*sr)->hijo_derecho:(*sr)->hijo_izquierdo;
                if(tmp == NULL)
                {
                    if(padre->hijo_derecho != NULL && (strcmp((*sr)->lastName,padre->hijo_derecho->lastName) == 0) )
                    {
                        padre->alturaDer = 0;
                    }
                    else
                        padre->alturaIzq = 0;
                    tmp = *sr;
                    *sr = NULL;
                }
                else
                {
                    if(padre->hijo_derecho != NULL && (strcmp((*sr)->lastName,padre->hijo_derecho->lastName) == 0))
                    {
                        padre->alturaDer = 1;
                    }
                    else
                        padre->alturaIzq = 1;
                    **sr = *tmp;
                }
                structs* tmpa = padreDe(_raiz,padre);
                char* lastNam = new char[30];
                memcpy(lastNam,padre->lastName,30);
                if(tmpa != NULL)
                {
                    if(tmpa->hijo_derecho != NULL && (strcmp(tmpa->hijo_derecho->lastName,lastNam) == 0))
                    {
                        tmpa->hijo_derecho = padre;
                        tmpa->alturaDer = max(padre->alturaDer,padre->alturaIzq)+1;
                    }
                    else
                    {
                        tmpa->hijo_izquierdo = padre;
                        tmpa->alturaIzq = max(padre->alturaDer,padre->alturaIzq)+1;
                    }
                }
                delete[] lastNam;
                actualizarHijosFile(padre,padre->hijo_derecho,padre->hijo_izquierdo);
                delete tmp;
            }
            else
            {
                bool raizEli = false;
                structs* min = minNode((*sr)->hijo_derecho);
                if(strcmp(_raiz->lastName,(*sr)->lastName) == 0)
                {
                    int pos = getRegistroPosFromFile(*file,min->lastName);
                    file->write(reinterpret_cast<char*>(&pos),0,4);
                    raizEli = true;
                }
                memcpy((*sr)->lastName,min->lastName,30);
                (*sr)->hijo_derecho = elimi(min->lastName,&(*sr)->hijo_derecho);
                if((*sr)->hijo_derecho != NULL)
                    balancear(&(*sr)->hijo_derecho);
                balancear(sr);
                if(!raizEli)
                    actualizarHijosFile(padre,padre->hijo_derecho,padre->hijo_izquierdo);
            }
        }
        else if(strcmp((*sr)->lastName,last) > 0)
        {
            (*sr)->hijo_izquierdo = elimi(last,&(*sr)->hijo_izquierdo);
        }
        else if(strcmp((*sr)->lastName,last) < 0)
        {
            (*sr)->hijo_derecho = elimi(last,&(*sr)->hijo_derecho);
        }
        return *sr;
    }
    void rotacionDer(structs** sr)
    {
        structs* padreSr = padreDe(_raiz,*sr);
        structs* sigIzq = (*sr)->hijo_izquierdo;
        (*sr)->hijo_izquierdo = sigIzq->hijo_derecho;
        if((*sr)->hijo_izquierdo == NULL)
            (*sr)->alturaIzq = 0;
        else
        {
            (*sr)->alturaIzq = max((*sr)->hijo_izquierdo->alturaIzq,(*sr)->hijo_izquierdo->alturaDer)+1;
        }
        actualizarHijosFile(*sr,(*sr)->hijo_derecho,sigIzq->hijo_derecho);
        sigIzq->hijo_derecho = *sr;
        if(sigIzq->hijo_derecho == NULL)
            sigIzq->alturaDer = 0;
        else
        {
            sigIzq->alturaDer = max(sigIzq->hijo_derecho->alturaIzq,sigIzq->hijo_derecho->alturaDer)+1;
        }
        actualizarHijosFile(sigIzq,*sr,sigIzq->hijo_izquierdo);
        if(padreSr != NULL)
        {
            if(padreSr->hijo_derecho != NULL && (strcmp(padreSr->hijo_derecho->lastName,(*sr)->lastName) == 0))
                actualizarHijosFile(padreSr,sigIzq,padreSr->hijo_izquierdo);
            else
                actualizarHijosFile(padreSr,padreSr->hijo_derecho,sigIzq);

        }
        *sr = sigIzq;
    }
    void rotacionIzq(structs** sr)
    {
        structs* padreSr = padreDe(_raiz,*sr);
        structs* sigDer = (*sr)->hijo_derecho;
        (*sr)->hijo_derecho = sigDer->hijo_izquierdo;
        if((*sr)->hijo_derecho == NULL)
            (*sr)->alturaDer = 0;
        else
        {
            (*sr)->alturaDer = max((*sr)->hijo_derecho->alturaIzq,(*sr)->hijo_derecho->alturaDer)+1;
        }
        actualizarHijosFile(*sr,sigDer->hijo_izquierdo,(*sr)->hijo_izquierdo);
        sigDer->hijo_izquierdo = *sr;
        if(sigDer->hijo_izquierdo == NULL)
            sigDer->alturaIzq = 0;
        else
        {
            sigDer->alturaIzq = max(sigDer->hijo_izquierdo->alturaIzq,sigDer->hijo_izquierdo->alturaDer)+1;
        }
        actualizarHijosFile(sigDer,sigDer->hijo_derecho,*sr);
        if(padreSr != NULL)
        {
            if(padreSr->hijo_derecho != NULL && (strcmp(padreSr->hijo_derecho->lastName,(*sr)->lastName) == 0))
                actualizarHijosFile(padreSr,sigDer,padreSr->hijo_izquierdo);
            else
                actualizarHijosFile(padreSr,padreSr->hijo_derecho,sigDer);

        }
        *sr = sigDer;
    }
    void rotDobleIzq(structs** sr)
    {
        rotacionDer(&(*sr)->hijo_derecho);
        rotacionIzq(&(*sr));
    }
    void rotDobleDer(structs** sr)
    {
        rotacionIzq(&(*sr)->hijo_izquierdo);
        rotacionDer(&(*sr));
    }
    void balancear(structs** sr)
    {
        if(abs((*sr)->alturaIzq - (*sr)->alturaDer) < 2)
        {
            actualizarHijosFile(*sr,(*sr)->hijo_derecho,(*sr)->hijo_izquierdo);
            return;
        }
        if((*sr)->alturaDer > (*sr)->alturaIzq)
        {
            if((*sr)->hijo_derecho->alturaDer >= (*sr)->hijo_derecho->alturaIzq)
            {
                rotacionIzq(sr);
            }
            else
            {
                rotDobleIzq(sr);
            }
        }
        else
        {
            if((*sr)->hijo_izquierdo->alturaIzq >= (*sr)->hijo_izquierdo->alturaDer)
            {
                rotacionDer(sr);
            }
            else
            {
                rotDobleDer(sr);
            }
        }
    }
    structs* padreDe(structs* raiz,structs* hijo)
    {

        if(raiz == NULL || raiz == hijo)
            return NULL;
        if(raiz->hijo_izquierdo == hijo)
            return raiz;
        if(raiz->hijo_derecho == hijo)
            return raiz;
        else
        {
            structs* padre = padreDe(raiz->hijo_izquierdo,hijo);
            if(padre == NULL)
            {
                return padreDe(raiz->hijo_derecho,hijo);
            }
            return padre;
        }
    }
    int abs(int x)
    {
        if(x < 0)
            return x*-1;
        return x;
    }
    int max(int x, int y)
    {
        if(x>y)
            return x;
        return y;
    }
    int agg(structs** raiz,structs* nuevo)
    {
        if(*raiz == NULL)
        {
            *raiz = nuevo;
            registroArbol itm;
            strcpy(itm.lastName,nuevo->lastName);
            itm.posRegisListaNombre = nuevo->posRegisListaNombre;
            file->lastToWrite(reinterpret_cast<char*> (&itm),sizeof(registroArbol));
            return 0;
        }
        if(strcmp((*raiz)->lastName,nuevo->lastName) > 0)
        {
            (*raiz)->alturaIzq = agg(&(*raiz)->hijo_izquierdo,nuevo)+1;
            balancear(raiz);
            return max((*raiz)->alturaDer,(*raiz)->alturaIzq);
        }
        if(strcmp((*raiz)->lastName,nuevo->lastName) < 0)
        {
            (*raiz)->alturaDer = agg(&(*raiz)->hijo_derecho,nuevo)+1;
            balancear(raiz);
            return max((*raiz)->alturaDer,(*raiz)->alturaIzq);
        }
        return -1;
    }
    int buscar(char last[30],structs* raiz)
    {
        if(raiz == NULL)
            return -1;
        if(strcmp(last,raiz->lastName) == 0)
            return 1;
        if(strcmp(last,raiz->lastName) > 0 )
            return buscar(last,raiz->hijo_derecho);
        return buscar(last,raiz->hijo_izquierdo);
    }
    structs* buscarR(char last[30],structs* raiz)
    {
        if(raiz == NULL)
            return NULL;
        if(strcmp(last,raiz->lastName) == 0)
            return raiz;
        if(strcmp(last,raiz->lastName) > 0 )
            return buscarR(last,raiz->hijo_derecho);
        return buscarR(last,raiz->hijo_izquierdo);
    }
    void imprimirArbolPre(structs* sb)
    {
        if(sb == NULL)
        {
            return;
        }
        cout<<sb->lastName<<",";

        imprimirArbolPre(sb->hijo_izquierdo);
        imprimirArbolPre(sb->hijo_derecho);
    }
    void imprimirArbolPos(structs* sb)
    {
        if(sb == NULL)
        {
            return;
        }
        imprimirArbolPos(sb->hijo_izquierdo);
        imprimirArbolPos(sb->hijo_derecho);
        cout<<sb->lastName<<",";

    }
    void imprimirArbolIn(structs* sb)
    {
        if(sb == NULL)
        {
            return;
        }
        imprimirArbolIn(sb->hijo_izquierdo);
        cout<<sb->lastName<<",";
        imprimirArbolIn(sb->hijo_derecho);

    }
    int charToInt(char* x)
    {
        int i = (x[3] << 24) | (x[2] << 16) | (x[1] << 8) | (x[0]);
        // delete[] x;
        return i;
    }
    int cargarHijos(registroArbol raiz,structs** raizItem)
    {
        if(raiz.hijo_derecho == -1 && raiz.hijo_izquierdo == -1)
            return 0;
        if(raiz.hijo_derecho != -1)
        {
            //voy por aca!!
            registroArbol hijoDer = getRegistroArbol(*file,raiz.hijo_derecho);
            structs* raizRetorno = new structs(hijoDer.lastName);
            raizRetorno->posRegisListaNombre = hijoDer.posRegisListaNombre;
            (*raizItem)->hijo_derecho = raizRetorno;
            (*raizItem)->alturaDer = cargarHijos(hijoDer,&raizRetorno) +1;
        }
        if(raiz.hijo_izquierdo != -1)
        {
            registroArbol hijoIzq = getRegistroArbol(*file,raiz.hijo_izquierdo);
            structs* raizRetorno = new structs(hijoIzq.lastName);
            raizRetorno->posRegisListaNombre = hijoIzq.posRegisListaNombre;
            (*raizItem)->hijo_izquierdo = raizRetorno;
            (*raizItem)->alturaIzq = cargarHijos(hijoIzq,&raizRetorno) +1;
        }
        if((*raizItem)->hijo_derecho != NULL && (*raizItem)->hijo_izquierdo != NULL)
        {
            return max((*raizItem)->alturaDer,(*raizItem)->alturaIzq);
        }
        bool isDer = (*raizItem)->hijo_derecho != NULL?true:false;
        if(isDer)
            return (*raizItem)->alturaDer;
        return (*raizItem)->alturaIzq;
    }
    void actualizarHijosFile(structs* sr,structs* hijo_der = NULL,structs* hijo_izq = NULL)
    {
        if(sr == NULL)
            return;
        int posInFile = getRegistroPosFromFile(*file,sr->lastName);
        if( posInFile != -1)
        {
            registroArbol itm = getRegistroArbol(*file,posInFile);
            itm.hijo_derecho = -1;
            itm.hijo_izquierdo = -1;
            memcpy(itm.lastName,sr->lastName,30);
            if(hijo_der != NULL)
            {
                itm.hijo_derecho = getRegistroPosFromFile(*file,hijo_der->lastName);

            }
            if(hijo_izq != NULL)
                itm.hijo_izquierdo = getRegistroPosFromFile(*file,hijo_izq->lastName);
            int setOff = 4+(posInFile*sizeof(registroArbol));
            file->write(reinterpret_cast<char*>(&itm),setOff,sizeof(registroArbol));
        }
    }
    int getRegistroPosFromFile(DataFile file,char last[30])
    {
        if(last == NULL)
            return -1;
        int posPuntero = 4;
        int pos = 0;
        int posFinal = file.getEndingPos();
        while(posPuntero <= posFinal)
        {
            char* lastName = file.read(posPuntero,30);
            if(strcmp(lastName,last) == 0)
            {
                delete[] lastName;
                return pos;
            }
            pos++;
            posPuntero+= sizeof(registroArbol);
            delete[] lastName;
        }
        return -1;
    }
};
#endif //ARBOL_AVL




