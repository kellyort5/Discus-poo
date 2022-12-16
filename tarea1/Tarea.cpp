#include <iostream>
#include <string.h>
#include <iomanip>
#define maxchar 50

using namespace std;

struct nodo
{
    int carnet;              
    char nombre[maxchar];   
    char apellido[maxchar]; 
    char correo[maxchar];    
    int telefono;
    int edad;
    struct nodo *sgte;
};
typedef struct nodo *PLista;

//prototipos de funciones
void menu(void);
void registrar(PLista &);
void eliminar(PLista &);
void mostrar(PLista );

int main(void)
{

    PLista lista = NULL;

    int opcion;

    do
    {
        menu();
        cin >> opcion;

        switch (opcion)
        {

        case 1:
            registrar(lista);
            break;

        case 2:
            if (lista == NULL)
            {

                cout << "No Hay personas Registradas\n";
            }
            else
            {

                mostrar(lista);
            }
            break;

        case 3:
            if (lista == NULL)
            {

                cout << "No Hay personas Registrados\n";
            }
            else
            {

                eliminar(lista);
            }
            break;

        case 4:
            return 0;

        default:
            cout << "INGRESE UNA OPCION VALIDA.\n";
            break;
        }

        system("pause");
        system("cls");

    } while (opcion != 6);

    system("pause");

    return 0;
}

void menu(void)
{
    cout <<" REGISTRO DE DATOS"<<endl<<endl;
    cout <<"1. INGRESAR DATOS DE PERSONA" << endl;
    cout <<"2. MOSTRAR LISTADO" << endl;
    cout <<"3. ELIMINAR PERSONA" << endl;
    cout <<"4. SALIR " << endl;

    cout << "Ingrese opcion: ";
}

void registrar(PLista &lista)
{

    PLista t, q = new (struct nodo);

    cout << "REGISTRO DE DATOS DE PERSONAS "<<endl;
    cin.ignore();
    cout << "NOMBRE:";
    cin.getline(q->nombre, maxchar);
    cin.ignore();
    cout << "APELLIDO:";
    cin.getline(q->apellido, maxchar);
    cin.ignore();
    cout << "EDAD:";
    cin >> q->edad;
    cin.ignore();
    cout << "CARNET:";
    cin >> q->carnet;
    cin.ignore();
    cout << "CORREO ELECTRONICO:";
    cin.getline(q->correo, maxchar);
    cin.ignore();
    cout << "TELEFONO:";
    cin >> q->telefono;

    system("cls");

    q->sgte = NULL;

    if (lista == NULL)
    {

        lista = q;
    }
    else
    {
        t = lista;

        while (t->sgte != NULL)
        {

            t = t->sgte;
        }

        t->sgte = q;
    }
}

void mostrar(PLista q)
{

    int i = 1;

    while (q != NULL)
    {

        cout << "DATOS DE LA PERSONA [" << i << "] "<<endl;
        cout << "NOMBRE: " << q->nombre << endl;
        cout << "APELLIDO: " << q->apellido << endl;
        cout << "EDAD: " << q->edad << endl;        
        cout << "CARNET: "<< setfill('0')<<setw(8) << q->carnet << endl;
        cout << "CORREO ELECTRONICO: " << q->correo << endl;
        cout << "TELEFONO: "<< setfill('0')<<setw(8) << q->telefono << endl;

        q = q->sgte;

        i++;
    }
}

void eliminar(PLista &lista)
{

    string nom;
    PLista q, t;
    q = lista;

    cout << "ELIMINAR A UNA PERSONA"<<endl<<endl;
    cout << "INGRESE EL NOMBRE DE LA PERSONA QUE DESEA ELIMINAR:";
    cin >> nom;

    while (q != NULL)
    {

        if (q->nombre == nom)
        {

            if (q == lista)
                lista = lista->sgte;

            else
                t->sgte = q->sgte;

            delete (q);

            cout << "REGISTRO ELIMINADO\n";

            return;
        }
        else
        {

            t = q;
            q = q->sgte;
        }
    }
    if (q == NULL)
        cout << "NOMBRE NO REGISTRADO\n";
}