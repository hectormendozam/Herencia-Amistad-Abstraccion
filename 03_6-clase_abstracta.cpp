#include<iostream>
#include<math.h>

using namespace std;

/**
    Se define la clase Figura, la cual se usará como base para declarar las clases derivadas:
    Triangulo, Rectangulo y Cuadrado. La clase base es una clase abstracta ya que no se
    crearán instancias de ella, sino que se utiliza para crear una abstracción de un nivel
    superior de todas las figuras geométricas. La clase abstracta contiene un método virtual
    puro llamado CalcularArea().
**/

/// Definición de la clase abstracta Figura
class Figura
{
   public:
     Figura();
     virtual float CalcularArea()=0;
};

/// Declaración del método constructor por defecto
Figura::Figura()
{ }

/**
   Definición de la clase Triangulo, derivada de la clase abstracta Figura. Un triángulo
   se representa por medio de la longitud de su base y de su altura. La clase incluye además,
   un método virtual llamado CalcularArea().
**/
class Triangulo : public Figura
{
   private:
     float Base, Altura;
   public:
     Triangulo(float, float);
     virtual float CalcularArea();
};

/// Declaración del método constructor con parámetros
Triangulo::Triangulo(float Ba, float Alt)
{
   Base=Ba;
   Altura=Alt;
}

/// Método que calcula el área de un triángulo
float Triangulo::CalcularArea()
{
   return (Base*Altura/2);
}

/// Definición de la clase Equilatero, derivada de la clase Triangulo
class TrianguloEquilatero : public Triangulo
{
   public:
     TrianguloEquilatero(float, float);
     float CalcularArea();
};

/// Declaración del método constructor con parámetros. Invoca al método constructor de la clase base
TrianguloEquilatero::TrianguloEquilatero(float Ba, float Alt) : Triangulo(Ba, Alt)
{ }

/// Método que calcula el área de un triángulo equilátero
float TrianguloEquilatero::CalcularArea()
{
   return Triangulo::CalcularArea();
}

/// Definición de la clase TrianguloRectangulo, derivada de la clase Triangulo
class TrianguloRectangulo : public Triangulo
{
   private:
     float Cateto1, Cateto2, Hipotenusa;
   public:
     TrianguloRectangulo(float, float);
     float CalcularArea();
};

/// Declaración del método constructor con parámetros. Invoca al método constructor de la clase base
TrianguloRectangulo::TrianguloRectangulo(float Cat1, float Cat2) : Triangulo(Cat1, Cat2)
{
   Cateto1=Cat1;
   Cateto2=Cat2;
   Hipotenusa=sqrt(Cat1*Cat1+Cat2*Cat2);
}

/// Método que calcula el área de un triángulo rectángulo
float TrianguloRectangulo::CalcularArea()
{
   return (Cateto1*Cateto2);
}

/// Definición de la clase Rectangulo, derivada de la clase abstracta
class Rectangulo : public Figura
{
   private:
     float Largo, Alto;
   public:
     Rectangulo(float, float);
     float CalcularArea();
};

/// Declaración del método constructor con parámetros
Rectangulo::Rectangulo(float Lar, float Al)
{
   Largo=Lar;
   Alto=Al;
}

/// Método que calcula el área de un rectángulo
float Rectangulo::CalcularArea()
{
   return (Largo*Alto);
}

/// Definición de la clase Cuadrado, derivada de la clase Rectangulo
class Cuadrado : public Rectangulo
{
   public:
     Cuadrado(float);
     float CalcularArea();
};

/// Declaración del método constructor con parámetros. Invoca al método constructor de la clase base
Cuadrado::Cuadrado(float Lado) : Rectangulo(Lado, Lado)
{ }

/// Método que calcula el área de un cuadrado, haciendo uso del método heredado de la clase Rectangulo
float Cuadrado::CalcularArea()
{
   return Rectangulo::CalcularArea();
}

/// Ejemplo de prueba
int main()
{
   TrianguloEquilatero TriaEq(5, 7);
   TrianguloRectangulo TriaRec(3, 4);
   Rectangulo Rectan(2, 3);
   Cuadrado Cuadr(5);

   cout << "\nArea del triangulo equilatero: " << TriaEq.CalcularArea();
   cout << "\nArea del triangulo rectangulo: " << TriaRec.CalcularArea();
   cout << "\nArea del rectangulo: " << Rectan.CalcularArea();
   cout << "\nArea del cuadrado: " << Cuadr.CalcularArea();
   cout << "\n";

   system("pause");
   return 0;
}
