#include<iostream>
#include<math.h>

using namespace std;

/**
    Se define la clase Figura, la cual se usar� como base para declarar las clases derivadas:
    Triangulo, Rectangulo y Cuadrado. La clase base es una clase abstracta ya que no se
    crear�n instancias de ella, sino que se utiliza para crear una abstracci�n de un nivel
    superior de todas las figuras geom�tricas. La clase abstracta contiene un m�todo virtual
    puro llamado CalcularArea().
**/

/// Definici�n de la clase abstracta Figura
class Figura
{
   public:
     Figura();
     virtual float CalcularArea()=0;
};

/// Declaraci�n del m�todo constructor por defecto
Figura::Figura()
{ }

/**
   Definici�n de la clase Triangulo, derivada de la clase abstracta Figura. Un tri�ngulo
   se representa por medio de la longitud de su base y de su altura. La clase incluye adem�s,
   un m�todo virtual llamado CalcularArea().
**/
class Triangulo : public Figura
{
   private:
     float Base, Altura;
   public:
     Triangulo(float, float);
     virtual float CalcularArea();
};

/// Declaraci�n del m�todo constructor con par�metros
Triangulo::Triangulo(float Ba, float Alt)
{
   Base=Ba;
   Altura=Alt;
}

/// M�todo que calcula el �rea de un tri�ngulo
float Triangulo::CalcularArea()
{
   return (Base*Altura/2);
}

/// Definici�n de la clase Equilatero, derivada de la clase Triangulo
class TrianguloEquilatero : public Triangulo
{
   public:
     TrianguloEquilatero(float, float);
     float CalcularArea();
};

/// Declaraci�n del m�todo constructor con par�metros. Invoca al m�todo constructor de la clase base
TrianguloEquilatero::TrianguloEquilatero(float Ba, float Alt) : Triangulo(Ba, Alt)
{ }

/// M�todo que calcula el �rea de un tri�ngulo equil�tero
float TrianguloEquilatero::CalcularArea()
{
   return Triangulo::CalcularArea();
}

/// Definici�n de la clase TrianguloRectangulo, derivada de la clase Triangulo
class TrianguloRectangulo : public Triangulo
{
   private:
     float Cateto1, Cateto2, Hipotenusa;
   public:
     TrianguloRectangulo(float, float);
     float CalcularArea();
};

/// Declaraci�n del m�todo constructor con par�metros. Invoca al m�todo constructor de la clase base
TrianguloRectangulo::TrianguloRectangulo(float Cat1, float Cat2) : Triangulo(Cat1, Cat2)
{
   Cateto1=Cat1;
   Cateto2=Cat2;
   Hipotenusa=sqrt(Cat1*Cat1+Cat2*Cat2);
}

/// M�todo que calcula el �rea de un tri�ngulo rect�ngulo
float TrianguloRectangulo::CalcularArea()
{
   return (Cateto1*Cateto2);
}

/// Definici�n de la clase Rectangulo, derivada de la clase abstracta
class Rectangulo : public Figura
{
   private:
     float Largo, Alto;
   public:
     Rectangulo(float, float);
     float CalcularArea();
};

/// Declaraci�n del m�todo constructor con par�metros
Rectangulo::Rectangulo(float Lar, float Al)
{
   Largo=Lar;
   Alto=Al;
}

/// M�todo que calcula el �rea de un rect�ngulo
float Rectangulo::CalcularArea()
{
   return (Largo*Alto);
}

/// Definici�n de la clase Cuadrado, derivada de la clase Rectangulo
class Cuadrado : public Rectangulo
{
   public:
     Cuadrado(float);
     float CalcularArea();
};

/// Declaraci�n del m�todo constructor con par�metros. Invoca al m�todo constructor de la clase base
Cuadrado::Cuadrado(float Lado) : Rectangulo(Lado, Lado)
{ }

/// M�todo que calcula el �rea de un cuadrado, haciendo uso del m�todo heredado de la clase Rectangulo
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
