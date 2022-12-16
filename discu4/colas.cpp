#include <iostream>
using namespace std;

struct nodo
{
    char caracter;
    nodo *sig;
};

class heap
{
    nodo *inicio, *fin;

public:
    heap()
    {
        inicio = NULL;
        fin = NULL;
    }
    void insert(char caracter)
    {
        nodo *newnodo = new nodo;
        newnodo->caracter = caracter;
        newnodo->sig = NULL;

        if (inicio == NULL)
        {
            inicio = newnodo;
        }
        else
        {
            fin->sig = newnodo;
        }

        fin = newnodo;
    }

    char pop(){
        
        char n=inicio->caracter;
        nodo *aux =inicio;

        if(inicio==fin){
            inicio=NULL;
            fin=NULL;
        }
        else{
            inicio =inicio->sig;
        }

        delete aux;
        return n;
    }

    void print(){
        nodo *aux =inicio;
        while(aux){
            cout <<aux->caracter<< "";
            aux=aux->sig;
        }
        delete aux;
    }
};

int main()
{
    heap heap;
    bool flag =true;
    int opc;

    while(flag){
        cout<<"\n1. Insertar en la cola"<<endl;
        cout<<"2.Mostrar la cola"<<endl;
        cout<<"3.Obterner el uktimo elemento de la cola" <<endl;
        cin>>opc;

        switch(opc){
            case 1:
            char carac;
            cin>> carac;
            heap.insert(carac);
            break;
            
            case 2:
            heap.print();
            break;
        }
    }

    return 0;
}