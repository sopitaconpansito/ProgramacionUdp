#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void llenar(int x[100])
{
    srand(time(NULL));
    int ceros = 0;
    for (int i = 0; i < 100; i++)
    {
        int fila, columna;
        int valor = rand() % (10);
        x[i] = valor;
        if(valor == 0)
        {
            ceros++;
            if (ceros > 5)
            {
                x[i] = 1;
            }
        }
    }
}
void mostrar(int x[100])
{
    for(int i = 0; i < 100; i++)
    {
        cout << x[i] << " ";
    }
cout << endl;
}
void pagar(int actual)
{
    if (actual == 99)
    {
        cout << "Premio mayor" << endl;
    }
    else if (actual > 99)
    {
        cout << "Premio de consuelo" << endl;
    }
    else if (actual == 0)
    {
        cout << "Perdió" << endl;
    }
}
void jugar(int juego[100], int partida)
{
    
    if (partida < 0 || partida > 10)
    {
        cout << "Partida no válida" << endl;
        return;
    }
    else
    {
        int actual = partida;
        while (true)
        {
            actual = actual + juego[actual];
            if (actual == 99 || actual > 99 || actual == 0)
            {
                pagar(actual);
                break;
            }
        }
    }
}



int main()
{
  int juego[100], partida;
  llenar(juego);
  //mostrar(juego)
  mostrar(juego);
  cout << "Ingrese desde que celda quiere partir (entre 0 y 10)" << endl;
  cin >> partida;
  jugar(juego, partida);
  
  /*Toma el valor inicial (partida) y avanza la cantidad de celdas según el valor
  de la celda de partida, luego vuelve a avanzar la cantidad de celdas de acuerdo
  al valor de la celda y así sucesivamente
  La idea es llegar justo a la celda 99, si es así, premio mayor, si
  se pasa de la celda 99 premio de consuelo, si llega a una celda 0, pierde el juego
  vea el ejemplo en excel que aclara el juego*/
 }