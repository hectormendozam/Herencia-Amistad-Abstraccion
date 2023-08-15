#include<iostream>

using namespace std;
/** Ejemplo de funciones amigas

   Definimos la clase Ejemplo, en la cual se incluye la declaración de la función
   Suma como una función amiga de la misma. Esto permitirá que dicha función
   pueda tener acceso a todos los miembros de la clase.
**/

/// clase Ejemplo
class Ejemplo
{
   private:
      int Atrib1, Atrib2;
   public:
      Ejemplo();
      Ejemplo(int, int);
      void imprime();
      friend int suma(int, Ejemplo);
};

/// Declaracion del metodo constructor por omision (o por defecto)
Ejemplo::Ejemplo()
{}

/// Declaracion del metodo constructor con parámetros
Ejemplo::Ejemplo(int Num1, int Num2)
{
    Atrib1=Num1;
    Atrib2=Num2;
}

/// Metodo que imprime los valores del atributo de la clase Ejemplo
void Ejemplo::imprime()
{
    cout<< "Valor del primer atributo: " << Atrib1 << endl;
    cout<< "Valor del segundo atributo: " << Atrib2 << endl;
}

/** Funcion entera declarada como amiga de la clase Ejemplo, lo que permite
   que pueda sumar sus atributos a un entero de manera directa. En este caso
   el parametro Valor es un objeto de tipo Ejemplo y la funcion obtiene como
   resultado la suma de sus atributos mas un numero dado tambien como parametro **/
int suma(int Dato, Ejemplo Valor)
{
   return (Dato+Valor.Atrib1+Valor.Atrib2);
}

/// Ejemplo de prueba
int main()
{
  Ejemplo objEjemplo(2,5);

  int resultado = suma(10, objEjemplo);
  cout << "El resultado de la suma es: " << resultado << endl;

  system("pause");
  return 0;
}
