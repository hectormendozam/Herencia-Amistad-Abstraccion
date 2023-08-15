/**
* Ejemplo de metodos amigos con paso de par�metros por VALOR
**/
#include <iostream>

using namespace std;

class Numero;

class Cambio
{
    public:
    Cambio();
    void establecer(double, Numero);
};

class Numero
{
    private:
		double x;
	public:
		Numero(double);
		void mostrar();
		///establecer es una funcion amiga
		friend void Cambio::establecer(double, Numero);
};

Numero::Numero(double b)
{
	x = b;
}

void Numero::mostrar()
{
	cout << "El numero es: " << x << endl;
}

Cambio::Cambio()
{}

void Cambio::establecer(double a, Numero objeto)
{
    ///se modifica el atributo porque este m�todo es amigo de la clase N�mero
	objeto.x = a;
	cout << "El numero es: " << objeto.x << " (impresi�n en m�todo establecer)" << endl;
}

int main()
{
    setlocale(LC_ALL, "");
	cout << "Creamos el objeto Pi" << endl;
	Numero Pi(7.8);
	Pi.mostrar();

	cout << "Modificamos con la funcion amiga" << endl;
	Cambio c1;
	///Utilizamos el m�todo amigo.
	c1.establecer(3.14, Pi);

	/// El estado del objeto NO se modifica, ya que
	/// se pasa el valor del objeto, es decir, una copia
	Pi.mostrar();

	return 0;
}
