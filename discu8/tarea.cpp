#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct nodo{
     int nro;
     struct nodo *izq, *der;
}*ABB;

struct nodoCola{
    ABB ptr;
    struct nodoCola *sgte;
};
struct cola{
    struct nodoCola *delante;
    struct nodoCola *atras;
};

//protoipos

nodo *crearnodo(int);


ABB crearNodo(int x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
void insertar(ABB &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
           cout<<"\n\t  Insertado..!"<<endl<<endl;
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}

void preOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void enOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}

void postOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          enOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}

bool busquedaRec(ABB arbol, int dato)
{
     int r=0;   // 0 indica que lo encontre

     if(arbol==NULL)
        return r;

     if(dato<arbol->nro)
         r = busquedaRec(arbol->izq, dato);

     else if(dato> arbol->nro)
         r = busquedaRec(arbol->der, dato);

     else
        r = 1;   // son iguales, lo encontre

     return r;
}

ABB unirABB(ABB izq, ABB der)
{
    if(izq==NULL) return der;
    if(der==NULL) return izq;

    ABB centro = unirABB(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}

void elimina(ABB &arbol, int x)
{
     if(arbol==NULL) return;

     if(x<arbol->nro)
         elimina(arbol->izq, x);
     else if(x>arbol->nro)
         elimina(arbol->der, x);

     else
     {
         ABB p = arbol;
         arbol = unirABB(arbol->izq, arbol->der);
         delete p;
     }
}


void menu()
{
     //system("cls");
     cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";
     cout << "\t [1]  Insertar elemento                  \n";
     cout << "\t [2]  Recorridos de profundiad           \n";
     cout << "\t [3]  Buscar elemento                    \n";
     cout << "\t [4]  Eliminar elemento                  \n";
     cout << "\t [5] SALIR                              \n";

     cout << "\n\t Ingrese opcion : ";
}

void menu2()
{
     //system("cls");   // para limpiar pantalla
     cout << endl;
     cout << "\t [1] En Orden     \n";
     cout << "\t [2] Pre Orden    \n";
     cout << "\t [3] Post Orden   \n";
     cout << "\n\t     Opcion :  ";
}

int main()
{
    ABB arbol = NULL;
    int x;
    int op, op2;


    //system("color f9");   // poner color a la consola
    do
    {
          menu();  cin>> op;
          cout << endl;

          switch(op)
          {
               case 1:
                    cout << " Ingrese valor : ";  cin>> x;
                    insertar( arbol, x);
                    break;

               case 2:
                    menu2();  cin>> op2;

                    if(arbol!=NULL)
                    {
                         switch(op2)
                         {
                             case 1:
                                 enOrden(arbol); break;
                             case 2:
                                 preOrden(arbol); break;
                             case 3:
                                 postOrden(arbol); break;
                         }
                    }
                    else
                        cout << "\n\t Arbol vacio..!";
                    break;

               case 3:
                    bool band;

                    cout<<" Valor a buscar: "; cin>> x;

                    band = busquedaRec(arbol,x);

                    if(band==1)
                       cout << "\n\tEncontrado...";
                    else
                       cout << "\n\tNo encontrado...";
                    break;

               case 4:
                    cout<<" Valor a eliminar: "; cin>> x;
                    elimina(arbol, x);
                    cout << "\n\tEliminado..!";
                    break;

               case 5:
                    return 0;
          }

          cout<<"\n\n\n";
          //system("pause");  // hacer pausa y presionar una tecla para continuar
    }while(op!=11);

}