/*Ingresar la cantidad de pupusas que los clientes desean, 
si quiere que sean de arroz o de maíz,si las quieren con Coca-Cola o no, 
y de qué ingredientes las quieren, que permite agregarlas a la lista y mostrar las órdenes.*/

#include <iostream>
#include <iomanip>
#define maxchar 50

using namespace std;

struct nodo
{
    int numP;
    char masa[maxchar];
    char bebida[maxchar];
    char ingredientes[maxchar];
    struct nodo *sgte;
};
typedef struct nodo *PLista;

//prototipos de funciones
void menu(void);
void ordenar(PLista &);
void mostrarOrder(PLista);

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
            ordenar(lista);
            break;

        case 2:
            if (lista == NULL)
            {
                cout << "No se ha ordenado nada\n";
            }
            else
            {
                mostrarOrder(lista);
            }
            break;

        case 3:
            return 0;

        default:
            cout << "INGRESE UNA OPCION VALIDA.\n";
            break;
        }

        system("pause");
        system("cls");

    } while (opcion != 4);

    system("pause");

    return 0;
}

void menu(void)
{
    cout << "1. PEDIR ORDEN DE PUPUSAS" << endl;
    cout << "2. MOSTRAR ORDENES" << endl;
    cout << "3. SALIR " << endl;

    cout << "Ingrese opcion: ";
}

void ordenar(PLista &lista)
{

    PLista t, q = new (struct nodo);

    cout << "Cuantas pupusas desea: " << endl;
    cin >> q->numP;
    cin.ignore();
    cout << "Las desea de maiz o arroz:";
    cin.getline(q->masa, maxchar);
    cin.ignore();
    cout << "De que ingredientes las quiere:";
    cin.getline(q->ingredientes, maxchar);
    cin.ignore();
    cout << "Desea una CocaCola o no? :";
    cin.getline(q->bebida, maxchar);
    cin.ignore();

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

void mostrarOrder(PLista q)
{
    int i = 1;

    while (q != NULL)
    {

        cout << "ORDEN [" << i << "] " << endl;
        cout << "Numero de pupusas: " << q->numP << endl;
        cout << "Pupusas de : " << q->masa << endl;
        cout << "Ingredientes : " << q->ingredientes << endl;
        cout << "CocaCola: " << q->bebida << endl;
        q = q->sgte;

        i++;
    }
}
