#include <iostream>
using namespace std;

class nodo
{
private:
    int dato;
    nodo *previo;
    nodo *next;

    friend class LinkedList;
};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    int getFront() const;

    int getBack() const;

    void addFront(int dt);

    void addBack(int dt);

    void removeFront();

    void removeBack();

    void printForward();

    void printReverse();

private:
    nodo *header;
    nodo *trailer;
};

int main(){
    LinkedList ll;
    ll.addFront(16);
    ll.addFront(23);
    ll.addFront(8);
    ll.addBack(12);
    ll.addBack(5);

    cout <<"Imprimir lod datos: "<<endl;
    ll.printForward();

    cout <<"Imprimir lod datos al reves: "<<endl;
    ll.printReverse();

    ll.removeFront();
    ll.removeBack();

    cout <<"El valor de HEAD es: "<<ll.getFront()<<endl;
    cout <<"El valor de TAIL es: "<<ll.getBack()<<endl;
}

LinkedList::LinkedList(){
    header =new nodo;
    trailer = new nodo;

    header->next=trailer;
    trailer->previo=header;

    header->previo=NULL;
    trailer->next=NULL;
}
int LinkedList::getFront() const{
    return header->next->dato;
}
int LinkedList::getBack() const{
    return trailer->previo->dato;
}
void LinkedList::addFront(int dt){
    nodo *nd= new nodo;
    nd->dato=dt;
    nd->previo=header;
    nd->next=header->next;
    header->next->previo=nd;
    header->next=nd;
}
void LinkedList::addBack(int dt){
    nodo *nd = new nodo;
    nd->dato=dt;
    nd->previo=trailer->previo;
    nd->next=trailer;
    trailer->previo->next=nd;
    trailer->previo=nd;
}
void LinkedList::removeFront(){
    nodo *nd = header->next->next;
    delete header->next;
    header->next=nd;
    nd->previo=header;
}
void LinkedList::removeBack(){
    nodo *nd =trailer->previo->previo;
    delete trailer->previo;
    trailer->previo=nd;
    nd->next=trailer;
}
void LinkedList::printReverse(){
    nodo *nd = trailer->previo;
    while(nd!=header){
        cout <<nd<<endl;
        nd=nd->previo;
    }
}
void LinkedList::printForward(){
    nodo *nd=header->next;
    while(nd!=trailer){
        cout <<nd->dato<<endl;
        nd=nd->next;
    }
}



LinkedList::~LinkedList(){
    while(header->next!=trailer){
        removeFront();
    }
    delete header;
    delete trailer;
}
