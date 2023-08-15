#include <iostream>

using namespace std;
/// Ejemplo de clases amigas

/**  Se definen las clases Medico y Paciente, en donde esta ultima es una
    clase amiga de la primera. Por lo tanto, la clase Paciente podrá tener
    acceso a todos los miembros de la clase Medico
**/

/// prototipo de la clase Paciente, mas adelante se presenta su definicion
class Paciente;

/// clase Medico
class Medico
{
   private:
      string NombreCompleto, Especialidad;
   public:
      Medico();
      Medico(string NomCom, string Esp);
      string ObtenerNombreCompleto();
      string ObtenerEspecialidad();
      void ImprimeDatos();
      /// clase amiga que tiene acceso a los miembros privados de la clase Medico
      friend class Paciente;
};

/// Declaracion del metodo constructor por omision
Medico::Medico()
{}

/// Declaracion del metodo constructor con parametros
Medico::Medico(string NomCom, string Esp)
{
    NombreCompleto = NomCom;
    Especialidad = Esp;
}

/// Metodo que permite a los usuarios externos de la clase, conocer el nombre del medico
string Medico::ObtenerNombreCompleto()
{
    return NombreCompleto;
}

/// Metodo que permite a los usuarios externos de la clase, conocer la especialidad del medico
string Medico::ObtenerEspecialidad()
{
    return Especialidad;
}

/// Metodo que imprime los valores de los atributos de un medico
void Medico::ImprimeDatos(void)
{
    cout << "Nombre completo del medico: " << NombreCompleto << endl;
    cout << "Especialidad: " << Especialidad << endl << endl;
}

/// Definicion de la clase Paciente
class Paciente
{
   private:
      string NombreCompleto;
      int Edad;
      string Padecimiento;
      Medico MedicoEspecialista;
   public:
      Paciente();
      Paciente(string NomCom, int Ed, string Pad);
      string ObtenerNombreCompleto();
      int ObtenerEdad();
      string ObtenerPadecimiento();
      void AsociarMedico();
      void ImprimeDatos();
};

/// Declaracion del metodo constructor por omision
Paciente::Paciente()
{}

/// Declaracion del metodo constructor con parametros
Paciente::Paciente(string NomCom, int Ed, string Pad)
{
    NombreCompleto = NomCom;
    Edad = Ed;
    Padecimiento = Pad;
}

/// Metodo que permite a los usuarios externos a la clase, conocer el nombre del paciente
string Paciente::ObtenerNombreCompleto()
{
    return NombreCompleto;
}

/// Metodo que permite a los usuarios externos a la clase, conocer la edad del paciente
int Paciente::ObtenerEdad()
{
    return Edad;
}

/// Metodo que permite a los usuarios externos a la clase, conocer el padecimiento del paciente
string Paciente::ObtenerPadecimiento()
{
    return Padecimiento;
}

/// Metodo que asocia un medico especialista a cada paciente. Podemos observar que
/// el miembro MedicoEspecialista (de tipo apuntador a un objeto tipo Medico) tiene
/// acceso a los miembros privados de la clase Medico
void Paciente::AsociarMedico()
{
    cout << "Nombre completo del Medico: ";
    cin >> MedicoEspecialista.NombreCompleto;
    cout << "Especialidad: ";
    cin >> MedicoEspecialista.Especialidad;
}

/// Metodo que imprime los valores de los atributos de un paciente
void Paciente::ImprimeDatos()
{
    cout << "\nNombre Completo: " << NombreCompleto << endl;
    cout << "Edad: " << Edad << endl;
    cout << "Padecimiento: " << Padecimiento << endl;
    cout << "Datos del Medico Especialista: " << endl;
    MedicoEspecialista.ImprimeDatos();
}

/// Posible ejemplo
int main()
{
    Paciente ObjPacienteA("Juanito Perez", 25, "Gastritis"), ObjPacienteB("Lupita Luna", 38, "Gripe");

    ObjPacienteA.AsociarMedico();
    ObjPacienteB.AsociarMedico();

    ObjPacienteA.ImprimeDatos();
    ObjPacienteB.ImprimeDatos();

	system("pause");
    return 0;
}
