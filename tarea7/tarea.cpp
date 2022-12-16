#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct nodo
{
    int nro;
    struct nodo *izq, *der;
} *ABB;

// protoipos
nodo *crearnodo(int);
nodo *unirABB(nodo *, nodo *);
void insertar(nodo *&, int);
void preOrden(nodo *);
void inOrden(nodo *);
void postOrden(nodo *);
bool buscar(nodo *, int);
void elimina(nodo *&, int);
void menu();
void menu2();

ABB arbol = NULL;

int main()
{
    int x;
    int op, op2;

    do
    {
        menu();
        cin >> op;

        switch (op)
        {
        case 1:
            cout << " Ingrese valor : ";
            cin >> x;
            insertar(arbol, x);
            break;

        case 2:
            menu2();
            cin >> op2;

            if (arbol != NULL)
            {
                switch (op2)
                {
                case 1:
                    inOrden(arbol);
                    break;
                case 2:
                    preOrden(arbol);
                    break;
                case 3:
                    postOrden(arbol);
                    break;
                }
            }
            else
                cout << "\n\t Arbol vacio..!";
            break;

        case 3:
            bool band;

            cout << " Valor a buscar: ";
            cin >> x;

            band = buscar(arbol, x);

            if (band == 1)
                cout << "\n\tEncontrado...";
            else
                cout << "\n\tNo encontrado...";
            break;

        case 4:
            cout << " Valor a eliminar: ";
            cin >> x;
            elimina(arbol, x);
            cout << "\n\tEliminado..!";
            break;

        case 5:
            return 0;
        }

        cout << endl;
    } while (op != 5);
}

void menu()
{
    cout << "\n\t  ..[ ARBOL BINARIO DE BUSQUEDA ].." << endl;
    cout << "\t [1]  Insertar elemento" << endl;
    cout << "\t [2]  Mostrar elementos en el arbol" << endl;
    cout << "\t [3]  Buscar elemento" << endl;
    cout << "\t [4]  Eliminar elemento" << endl;
    cout << "\t [5] SALIR " << endl;

    cout << "\tIngrese opcion : ";
}

void menu2()
{
    cout << endl;
    cout << "\t [1] Mostrar en In-orden. " << endl;
    cout << "\t [2] Mostrar en Pre-orden. " << endl;
    cout << "\t [3] Mostrar en Post-orden." << endl;
    cout << "\tOpcion: ";
}

ABB crearnodo(int x)
{
    ABB nuevoNodo = new (struct nodo);
    nuevoNodo->nro = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}
void insertar(ABB &arbol, int x)
{
    if (arbol == NULL)
    {
        arbol = crearnodo(x);
        cout << "\n\t  Insertado..!" << endl
             << endl;
    }
    else if (x < arbol->nro)
        insertar(arbol->izq, x);
    else if (x > arbol->nro)
        insertar(arbol->der, x);
}

void preOrden(ABB arbol)
{
    if (arbol != NULL)
    {
        cout << arbol->nro << " ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void inOrden(ABB arbol)
{
    if (arbol != NULL)
    {
        inOrden(arbol->izq);
        cout << arbol->nro << " ";
        inOrden(arbol->der);
    }
}

void postOrden(ABB arbol)
{
    if (arbol != NULL)
    {
        inOrden(arbol->izq);
        inOrden(arbol->der);
        cout << arbol->nro << " ";
    }
}

bool buscar(ABB arbol, int dato)
{
    int r = 0;

    if (arbol == NULL)
        return r;
    if (dato < arbol->nro)
        r = buscar(arbol->izq, dato);
    else if (dato > arbol->nro)
        r = buscar(arbol->der, dato);
    else
        r = 1;
    return r;
}

ABB unirABB(ABB izq, ABB der)
{
    if (izq == NULL)
        return der;
    if (der == NULL)
        return izq;

    ABB centro = unirABB(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}

void elimina(ABB &arbol, int x)
{
    if (arbol == NULL)
        return;

    if (x < arbol->nro)
        elimina(arbol->izq, x);
    else if (x > arbol->nro)
        elimina(arbol->der, x);

    else
    {
        ABB p = arbol;
        arbol = unirABB(arbol->izq, arbol->der);
        delete p;
    }
}
