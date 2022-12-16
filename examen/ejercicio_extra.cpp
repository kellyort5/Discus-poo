/*Elabore un programa que contenga, dentro de su clase, dos funciones miembro y un
puntero a lista simple. La primera función lee notas de un estudiante de una materia en
un ciclo desde teclado y las introduce en la lista, en un nuevo nodo cada una. La segunda
función imprime en pantalla el promedio de una materia en un ciclo dado.
Su programa contará con lo siguiente:
(5%) La estructura de nodo de la lista.
5%) La clase, con sus partes privada y pública definidas.
(10%) El cuerpo de la función de lectura (si desea puede ser una función que itera y otra
función que lee), se deberá validar que la nota esté en el rango [0,0, 10,0], tener el nombre
de la materia y el ciclo entre el rango [1,2] . 
(15%) El cuerpo de la función imprime el
promedio de una materia en un ciclo.
(5%) La función main, que define el objeto e invoca a
ambas funciones miembro.*/

#include <iostream>
#include <iomanip>
using namespace std;

struct nodo
{
    float nota;
    int ciclo;
    char materia;
    nodo *sig;
};

class lista
{
private:
    nodo *pInicio;

public:
    lista();
    ~lista();
    void insertaNodo(void);
    void insInicio(float);
    //void mostrarn(void);
};

int main(void)
{
    cout << endl;
    cout << "ADMINISTRACION DE NOTAS" << endl;

    lista objListaSimple;
    cout << "Incertar notas en la lista: " << endl;
    objListaSimple.insertaNodo();
    //objListaSimple.mostrarn();

    cout << endl;
    return 0;
}

lista::lista(void)
{
    pInicio = NULL;
}

lista::~lista(void){
    cout << "Destructor ejecutandose" << endl;
    nodo *p;
    while (pInicio)
    {
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}    

void lista::insertaNodo(void)
{
    float nota;
    int ciclo;
    char materia;

    cout << "Ingrese el nombre de la materia: " <<endl;
    cin>>materia;
    cout <<"ingrese el ciclo que esta cursando: "<<endl;
    cin >>ciclo;
    cout << "Digite la nota o Ctrl-z para terminar: ";
    while (cin >> nota)
    {
        insInicio(nota);
        cout << "Digite la nota o Ctrl-z para terminar: ";
    }
}

void lista::insInicio(float nota)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->nota = nota;
    nuevo->sig = pInicio;
    pInicio = nuevo;

}
