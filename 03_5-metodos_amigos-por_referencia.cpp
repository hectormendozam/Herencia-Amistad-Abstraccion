/**
* Ejemplo de metodos amigos con paso de parámetros por REFERENCIA
**/
#include <iostream>

using namespace std;

class Numero;

class Cambio
{
    public:
    Cambio();
    void establecer(double, Numero*);
};

class Numero
{
    private:
		double x;
	public:
		Numero(double);
		void mostrar();
		///Se establece que es un método amigo
		friend void Cambio::establecer(double, Numero*);
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

void Cambio::establecer(double a, Numero *objeto)
{
    ///se modifica el atributo porque este método es amigo de la clase Número
	objeto->x = a;
	//cout << "El numero es: " << objeto->x << endl;
}

int main()
{
    setlocale(LC_ALL, "");
	cout << "Creamos el objeto Pi" << endl;
	Numero Pi(7.8);
	Pi.mostrar();

	cout << "Modificamos con la funcion amiga" << endl;
	Cambio c1;

	///Utilizamos el método amigo.
	c1.establecer(3.14, &Pi);

	/// El estado del objeto SÍ se modifica, ya que
	/// se pasa la referencia en memoria del objeto
	Pi.mostrar();

	return 0;
}
