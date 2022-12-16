/*Dados dos números enteros llamados mayor y menor, obtener el máximo común divisor (mcd) 
 de ambos por el método de Euclides. Para resolver este problema se procede así: 
 a) se realiza la división entera del mayor entre el menor, 
 b) si el residuo es cero, el mcd está en la variable llamada menor, despliega el resultado y termina el programa, 
 c) pero si el residuo no es cero, el valor de menor pasa a mayor y el valor de residuo pasa a menor, 
 d) repetir el paso a*/
#include <iostream>
using namespace std;

//prototipo de funcion
int mcd(int, int);

int main()
{
    int mayor, menor, resultado;

    cout << "CALCULO DEL MAXIMO COMUN DIVISOR" <<endl<<endl;
    cout << "Ingrese el valor del primer numero: " << endl;
    cin >> mayor;
    cout << "Ingrese el valor del segundo numero: " << endl;
    ;
    cin >> menor;

    /* Si N es mayor que M */
    if (menor > mayor)
    {
        resultado = mcd(menor, mayor);
    }
    else
    {
        resultado = mcd(mayor, menor);
    }

    cout << "El MCD es " << resultado;

    return 0;
}

int mcd(int m, int n)
{
    if (n == 0)
    {
        return m;
    }
    else
    {
        return mcd(n, m % n);
    }
}