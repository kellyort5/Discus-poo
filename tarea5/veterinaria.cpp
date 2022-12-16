/*En donde se pida el id, nombre del dueño, raza, peso, edad de la mascota
Que pueda agregar, mostrar por id, y borrar.*/
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct veterinaria
{

   int id;
   char nom[20], raza[20];
   float peso, edad;

   struct veterinaria *avanc;
};

veterinaria *insinicio(void);

void mostrar(veterinaria *&cab, int i);

void eliminar(veterinaria *&cab, int i);

char opciones(veterinaria *cab)

{
   char a;

   cout << "\n|--------------------------------------|";
   cout << "\n|     ADMINISTRACION DE VETERINARIA    |";
   cout << "\n|-------------------|------------------|";
   cout << "\n| 1. Insertar datos | 3. Eliminar      |";
   cout << "\n| 2. Buscar         | 4. Salir         |";
   cout << "\n|-------------------|------------------|";
   cout << "\n\n Escoja una Opcion: ";

   cin >> a;

   return a;
}

int main(void)
{
   int i;

   char opcion;

   veterinaria *cab = NULL;

   do
   {
      opcion = opciones(cab);
      switch (opcion)
      {
      case '1':
         cab = insinicio();
         break;

      case '2':
         cout <<"Ingrese ID: "<<endl;
         cin >> i;

         //mostrar(*&cab, i);

         break;

      case '3':
         cout << "inserte id: " << endl;
         cin >> i;

         eliminar(*&cab, i);
         break;

      case '4':
         return 0;

      default:
         cout << "Opcion invalida" << endl;
         break;
      }
   } while (opcion != '4');
}

veterinaria *insinicio()
{
   veterinaria *crear;

   crear = new veterinaria;

   cout << "Ingrese ID: " << endl;
   cin >> crear->id;
   cout << "Ingrese nombre del dueno de la mascota: " << endl;
   cin >> crear->nom;
   cout << "Ingrese raza de la mascota: " << endl;
   cin >> crear->raza;
   cout << "Ingres edad de la mascota(anios): " << endl;
   cin >> crear->edad;
   cout << "Ingrese peso de la mascota(libras): " << endl;
   cin >> crear->peso;
   cout<<"Datos almacenados correctamente!!"<<endl;
   crear->avanc = crear;

   return crear;
}

void mostrar(veterinaria *&cab, int i,veterinaria p)
{
   veterinaria *aux;

   if (cab != NULL){
      aux=cab;
      do{
         if(aux->id==i){
            cout << "Nombre de dueno: " << p.nom << endl;
            cout << "Raza de la mascota: " << p.raza << endl;
            cout << "Edad de la mascota: " << p.edad << endl;
            cout << "Peso de la mascota: " << p.peso << endl;
         }
         else{
            aux=aux->avanc;
         }
      }while(aux!=cab);
   }
   else{
      cout<<"NO hay datos en la lista"<<endl;
   }
}

void eliminar(veterinaria *&cab, int i)
{
   veterinaria *q, *r;
   q = r = cab;

   if (cab == NULL)
      cout << "no hay datos";
   else if (cab->avanc == cab && cab->id == i)
   {
      delete (q);
   }
   else
      while ((q->id != i) && (q->avanc != cab))
      {
         q = q->avanc;
      }
   if (cab->avanc == q)
   {
      cab->avanc = q->avanc;
      delete (q);
   }
   else
   {
      while (r->avanc != q)
      {
         r = r->avanc;
      }
      r->avanc = q->avanc;
      delete (q);
   }
}
