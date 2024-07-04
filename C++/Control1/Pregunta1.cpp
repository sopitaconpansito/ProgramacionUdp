#include <iostream>
#include <math.h>
using namespace std;

void raices(int a, int b, int c, int &tipo, float &raiz1, float &raiz2) // se ocupa ampersand para cambiar los valores 
{
    // primera parte de la funcion detarminar si es raiz imaginaria usando discriminate
    
    
    float discriminante = pow(b,2) - (4*a*c);

    if (discriminante < 0)
    {
        tipo = 1;
    }
    else
    {
        tipo = 2;
        raiz1 = (-b + sqrt(discriminante))/ (2*a);
        raiz2 = (-b - sqrt(discriminante))/ (2*a);
    }
}

int main()
 {
  int a, b, c, tipo;
  float raiz1, raiz2;
  cout << "Ecuacion de segundo grado" << endl;
  cout << "Ingrese a " << endl;
  cin >> a;
  cout << "Ingrese b " << endl;
  cin >> b;
  cout << "Ingrese c " << endl;
  cin >> c;
  raices(a, b, c, tipo, raiz1, raiz2); // llama a la funcion raices enviandole parametros
  if (tipo == 1) // primera parte del main, definir raiz tipo imaginaria
  {
  cout << "Las raices son imaginarias" << endl;
  }
  else
  {
  cout << "Las raices son reales" << endl;
  cout << "Raiz 1:" << raiz1 << endl;
  cout << "Raiz 2:" << raiz2 << endl;
  }
 }