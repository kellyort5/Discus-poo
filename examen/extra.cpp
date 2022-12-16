#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

struct nodo
{
    float nota;              
    char materia[40];   
    int ciclo;
    nodo *sgte;
};

class lista
{
    private: 
    nodo *PLista;

    public:
    void registrar();
    void mostrar();
};

int main(void)
{
    lista objListasim;
    objListasim.registrar();
    objListasim.mostrar();

    return 0;
}

void lista::registrar(void){
    nodo *q=new(nodo), *t;
    char materia[40];
    float nota;
    int ciclo;

    cout << "REGISTRO DE NOTAS"<<endl<<endl;
    cout <<"Ingrese el nombre de la materia: "<<endl;
    cin >> q->materia;
    cout <<"Ingrese el ciclo que esta cursando: "<<endl;
    cin >> q->ciclo;
    cout <<"Ingrese la nota o ctrl-z para terminar: "<<endl;
    while (cin >> q-> nota)
    {
        cout << "Digite la nota o Ctrl-z para terminar: " <<endl;
    }
    
    q->sgte = NULL;

    if (PLista == NULL)
    {
        PLista = q;
    }
    else
    {
        t = PLista;

        while (t->sgte != NULL)
        {

            t = t->sgte;
        }

        t->sgte = q;
    }

}

void lista::mostrar(void)
{
    nodo *q;

    int i = 1;
    float h;

    while (q != NULL)
    {
        h = q->nota+(q->nota / h);

        cout << "NOMBRE DE LA PERSONA [" << i << "] "<<endl;
        cout << "materia: " << q->materia << endl;
        cout << "promedio de nota: " << h << endl;
        cout << "ciclo: "<< setfill('0')<<setw(2) << q->ciclo << endl;

        q = q->sgte;

        i++;
    }
}

