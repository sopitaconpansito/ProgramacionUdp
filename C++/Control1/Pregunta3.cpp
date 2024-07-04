#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void llenar(int x[10][10])
 {
  srand(time(NULL));
  for (int i = 0; i < 10; i++)
   {
    for(int j = 0; j< 10; j++)
    {
    x[i][j] = 0;
    }
   }
   
   int fila = rand() % (10);
   int columna = rand() % (10);
   x[fila][columna] = 1;
   fila = rand() % (10);
   columna = rand() % (10);
   x[fila][columna] = 2;
 }
void mostrar(int x[10][10])
{
  for (int i = 0; i < 10; i++)
   {
    for(int j = 0; j< 10; j++)
    {
cout << x[i][j]<< " ";
    }
  cout << endl;
   }  
}

int distancia1del2(int x[10][10])
{
    int fila1 = -1, columna1 = -1, fila2 = -1, columna2 = -1;

    // Encuentra las posiciones de 1 y 2 en la matriz
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (x[i][j] == 1)
            {
                fila1 = i;
                columna1 = j;
            }
            if (x[i][j] == 2)
            {
                fila2 = i;
                columna2 = j;
            }
        }
    }

    // Verifica si 1 está adyacente a 2
    if ((abs(fila1 - fila2) == 1 && columna1 == columna2) || 
        (fila1 == fila2 && abs(columna1 - columna2) == 1))
    {
        int distancia = 1;
        return distancia;
    }

    // Verifica si 1 está en el perímetro de 2 cuadros de distancia de 2
    if ((abs(fila1 - fila2) <= 2 && abs(columna1 - columna2) <= 2))
    {
        int distancia = 2;
        return distancia;
    }

    // Si no cumple ninguna de las condiciones anteriores, retorna 3
    int distancia = 3;
    return distancia;
}

int main()
 {
  int matriz[10][10];
  llenar(matriz);
  //La función matriz llena la matriz con puros ceros, un 1 y un 2
  mostrar(matriz);
  
  int distancia = distancia1del2(matriz);
    cout << "La distancia entre 1 y 2 es: " << distancia << endl;
 }