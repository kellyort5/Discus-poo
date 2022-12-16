#include <iostream>
#include <string>
using namespace std;

struct vet
{
    int id, edad, peso;
    string nombre, raza;
};
struct nodo
{
    vet dato;
    nodo *sig;
    nodo *antes;

} * primero, *final;

int id;

void agregar(void)
{

    nodo *nuevo = new nodo();
    vet mascota;
    id++;
    mascota.id = id;
    cout << "ID usuario: " << mascota.id << endl;
    cout << "Favor ingrese el nombre del dueno: ";
    getline(cin, mascota.nombre);

    cout << "Favor ingrese raza de la mascota: ";
    getline(cin, mascota.raza);

    cout << "Favor ingrese peso de la mascota(libras): ";
    cin >> mascota.peso;
    cin.ignore();

    cout << "Favor ingrese edad de la mascota(anios): ";
    cin >> mascota.edad;
    cin.ignore();

    nuevo->dato = mascota;

    if (primero == NULL)
    {
        primero = nuevo;
        final = nuevo;
        primero->sig = primero;
        primero->antes = final;
    }
    else
    {
        final->sig = nuevo;
        nuevo->antes = final;
        nuevo->sig = primero;
        final = nuevo;
        primero->antes = final;
    }
}

void mostrar(void)
{
    nodo *saltarin = new nodo();
    saltarin = primero;
    bool encontrar = false;
    int valor = 0;
    cout << "Ingrese el ID del usuario que quiere ver: ";
    cin >> valor;
    cout << endl;
    cin.ignore();

    if (primero != NULL)
    {
        do
        {
            if (saltarin->dato.id == valor)
            {
                cout << "El id de la persona es: (" << saltarin->dato.id << ")" << endl;

                cout << "Nombre del dueno: " << saltarin->dato.nombre << endl;

                cout << "Raza de la mascota es: " << saltarin->dato.raza << endl;

                cout << "El peso de la mascota es: " << saltarin->dato.peso << " libras" << endl;

                cout << "La edad de la mascota es: " << saltarin->dato.edad << " anios" << endl;

                encontrar = true;
            }

            saltarin = saltarin->sig;

        } while (saltarin != primero && encontrar != true);

        if (!encontrar)
        {
            cout << "id no encontrado." << endl;
        }
    }
    else
    {
        cout << "La lista esta vacia. " << endl;
    }
}

void eliminarmascota(void)
{
    int id = 0;
    nodo *p = primero;
    nodo *q = NULL;

    cout << "Ingrese el ID que quiere eliminar : ";
    cin >> id;

    while ((p != NULL) && (p->dato.id != id))
    {
        q = p;
        p = p->sig;
    }
    if (p == NULL)
    {
        cout << "No hay persona con ese id" << endl;
        return;
    }
    if (primero->dato.id == id)
    {
        primero = primero->sig;
        delete (p);
        cout << "Se elimino el dueno en esta lista";
        return;
    }
    if (q == NULL)
        p = p->sig;
    else
        q->sig = p->sig;
    delete (p);
    cout << "Se elimino el dueno en esta lista";
}

void eliminarnodo()
{
    nodo *actual = new nodo();
    actual = primero;
    nodo *anterior = new nodo();
    anterior = NULL;
    bool encontrar = false;
    int valor = 0;
    cout << "Ingrese ID a borrar: ";
    cin >> valor;
    if (primero != NULL)
    {
        do
        {

            if (actual->dato.id == valor)
            {
                cout << "Usuario con el ID [" << valor << "] Encontrado" << endl;

                if (actual == primero)
                {
                    primero = primero->sig;
                    final->sig = primero;
                    delete actual;
                }
                else if (actual == final)
                {
                    anterior->sig = primero;
                    final = anterior;
                    delete actual;
                }
                else
                {
                    anterior->sig = actual->sig;
                    delete actual;
                }

                cout << "Usuario Eliminado";
                encontrar = true;
            }
            anterior = actual;
            actual = actual->sig;
        } while (actual != primero && encontrar != true);
        if (!encontrar)
        {
            cout << "Persona no encontrada";
        }
    }
    else
    {
        cout << "La lista de clientes esta vacia";
    }
}

int main()
{
    int opcion = 0;
    do
    {
        cout << "\n|--------------------------------------|";
        cout << "\n|     ADMINISTRACION DE VETERINARIA    |";
        cout << "\n|-------------------|------------------|";
        cout << "\n| 1. Insertar datos | 3. Eliminar      |";
        cout << "\n| 2. Buscar         | 4. Salir         |";
        cout << "\n|-------------------|------------------|";
        cout << "\n\n Escoja una Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            agregar();
            break;
        case 2:
            mostrar();
            break;
        case 3:
            eliminarmascota();
            break;
        case 4:
            opcion = 4;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (opcion != 4);

    return 0;
}