/*Elabore una función que, dado un número entero que se obtiene desde teclado, 
realice un conteo como el siguiente: Suponiendo que el valor ingresado es 3:  1 2 3 2 1 */
#include <iostream>
using namespace std;

//prototipo de funcion
void contador(int, int);

int main()
{
  int n;
  cout << "Ingrese un numero entero: " << endl;
  cin >> n;
  cout << endl;
  contador(n, 1);
  cout << endl;

  return 0;
}
void contador(int x, int i)
{
  if (i < x)
  {
    cout << i << endl;
    contador(x, i + 1);
  }
  else if (x != 0)
  {
    cout << x << endl;
    contador(x - 1, i);
  }
}