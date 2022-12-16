#include <iostream>
#include <string>
using namespace std;

struct perfil
{
    string usuario;
    string admi;
    int id;
};

int menu()
{
    int opcion = 0;
    cout << "Por favor elija una opcion" << endl;
    cout << "1) Agregar usuario." << endl;
    cout << "2) Mostrar lista de usuarios de inicio a fin." << endl;
    cout << "3) Mostrar lista de usuarios de fina inicio." << endl;
    cout << "4) Salir." << endl;
    cin >> opcion;
    cin.ignore();
    return opcion;
}

perfil solicitar(void)
{
    perfil p;
    cout << "Ingrese el nombre de usuario: " << endl;
    getline(cin, p.usuario);
    cout << "Indique si es administrador, cliente o trabajador: " << endl;
    getline(cin, p.admi);
    cout << "Ingrese ID: " << endl;
    cin >> p.id;
    cin.ignore();
    return p;
}

void mostrarperfil(perfil p)
{
    cout << "Nombre de usuario: " << p.usuario << endl;
    cout << "Perfil: " << p.admi << endl;
    cout << " ID: " << p.id << endl;
}

typedef perfil T;

struct nodo
{
    T dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble
{
private:
    nodo *pInicio;

public:
    ListaDoble();
    void insert(T);
    void traversalForward(void);
    void traversalReverse(void);
};

int main(void)
{
    ListaDoble ad;

    perfil p;

    switch (menu())
    {
    case 1:
        p = solicitar();
        ad.insert(p);
        cout << "perfil almacenado exitosamente!" << endl;
        break;
    case 2:
        ad.traversalForward();
        break;

    case 3:
        ad.traversalReverse();

    case 4:
        return 0;
        break;
    default:
        cout << "La opcion no es valida, favor intente de nuevo." << endl;
        break;
    }

    return 0;
}

ListaDoble::ListaDoble(void)
{
    pInicio = NULL;
}

void ListaDoble::insert(T dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if (!pInicio)
    {
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else
    {
        nodo *saltarin = pInicio;
        while (saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}

void ListaDoble::traversalForward(void)
{
    nodo *saltarin = pInicio;
    while (saltarin != NULL)
    {
        mostrarperfil(saltarin->dato);
        saltarin = saltarin->sig;
    }
}

void ListaDoble::traversalReverse(void)
{
    if (!pInicio)
        return;
    nodo *p = pInicio;
    nodo *q = NULL;
    while (p)
    {
        q = p;
        p = p->sig;
    }
    while (q)
    {
        mostrarperfil(q->dato);
        q = q->ant;
    }
}
