/// Ejemplo de herencia simple a diferentes niveles o generaciones
#include <iostream>

using namespace std;

class Arbol
{
protected:
    int Edad;
    float Altura;
    string Nombre;
public:
    Arbol(int Ed, float Alt, string Nom);
    void ImprimeArbol();
};

Arbol::Arbol(int Ed, float Alt, string Nom)
{
    Edad=Ed;
    Altura=Alt;
    Nombre = Nom;
}

void Arbol::ImprimeArbol()
{
    cout << "Nombre: " << Nombre << endl;
    cout << "Edad: " << Edad << endl;
    cout << "Altura: " << Altura << endl;
}

/// primer nivel de la herencia
class Frutal : private Arbol
{
protected:
    string EstacionFruto;
public:
    Frutal(int Ed, float Alt, string Nom, string EstFr);
    void ImprimeFrutal();
};

/// declaracion del metodo constructor, invoca al constructor de la clase base
Frutal::Frutal(int Ed, float Alt, string Nom, string EstFr): Arbol(Ed, Alt, Nom)
{
    ///copiar a EstacionFrute la variable EstFr
    EstacionFruto = EstFr;
}

void Frutal::ImprimeFrutal()
{
    //ImprimeArbol();
    cout << "Nombre: " << Nombre << endl;
    cout << "Edad: " << Edad << endl;
    cout << "Altura: " << Altura << endl;
    cout << "Estacion del agno en la que da frutos mas jugosos y sabrosos : " << EstacionFruto << endl;
}

/// segundo nivel de herencia
class Citrico : public Frutal
{
protected:
    string NombreCitrico;
public:
    Citrico(int Ed, float Alt, string Nom, string EstFr, string NomCit);
    void ImprimeCitrico();
};

Citrico::Citrico(int Ed, float Alt, string Nom, string EstFr, string NomCit): Frutal(Ed, Alt, Nom, EstFr)
{
    NombreCitrico = NomCit;
}

void Citrico::ImprimeCitrico()
{
    Frutal::ImprimeFrutal();

    ///NOTA1: El siguiente código genera error de compilación, dado que los atributos
    ///       Nombre, Edad y Altura, ya no fueron heredados a esta clase.
    /*
    cout << "Nombre: " << Nombre << endl;
    cout << "Edad: " << Edad << endl;
    cout << "Altura: " << Altura << endl;
    */

    ///NOTA2: El siguiente código no genera error, dado que el atributo EstacionFruto
    ///       si fue heredado a esta clase, pero el dato ya es mostrado con usando el
    ///       método Frutal::ImprimeFrutal();
    /*
    cout << "Estacion del agno en la que da frutos mas jugosos y sabrosos : " << EstacionFruto << endl;
    */

    ///NOTA3: El dato que falta mostra ren Frutal::ImprimeFrutal(); es el de esta clase,
    ///       es decir, NombreCitrico
    cout << "Nombre del Citrico: " << NombreCitrico << endl;
}

/// Ejemplo de una posible ejecucion
int main()
{
    Arbol ObjArbol(2, 3.55, "Alamo");
    Frutal ObjFrutal(3, 2.56, "Manzano", "Otogno");
    Citrico ObjCitrico(1, 2.2, "Limonero", "Invierno", "Limon");

    ObjArbol.ImprimeArbol();

    cout << endl;

    ObjFrutal.ImprimeFrutal();

    cout << endl;

    ObjCitrico.ImprimeCitrico();

    system("pause");
    return 0;
}
