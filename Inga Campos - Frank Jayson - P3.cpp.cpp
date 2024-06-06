#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Empleado {
    string nombre;
    char tipo; 
    double sueldoBasico;
    double deduccionAFP;
    double deduccionSeguro;
    double bonificacion;
    double sueldoNeto;
};

double calcularDeduccionAFP(double sueldoBasico) {
    return sueldoBasico * 0.08;
}

double calcularDeduccionSeguro(double sueldoBasico) {
    return sueldoBasico * 0.05;
}

double calcularBonificacion(double sueldoBasico, char tipo) {
    if (tipo == 'C') {
        return sueldoBasico * 0.08;
    } else if (tipo == 'N') {
        return sueldoBasico * 0.12;
    }
    return 0;
}

double calcularSueldoNeto(double sueldoBasico, double deduccionAFP, double deduccionSeguro, double bonificacion) {
    return sueldoBasico - deduccionAFP - deduccionSeguro + bonificacion;
}

void mostrarDetallesEmpleado(const Empleado& empleado) {
    cout << "Nombre: " << empleado.nombre << endl;
    cout << "Tipo de Empleado: " << (empleado.tipo == 'C' ? "Contratado" : "Nombrado") << endl;
    cout << fixed << setprecision(2);
    cout << "Sueldo Básico: $" << empleado.sueldoBasico << endl;
    cout << "Deduccion AFP: $" << empleado.deduccionAFP << endl;
    cout << "Deduccion Seguro: $" << empleado.deduccionSeguro << endl;
    cout << "Bonificacion: $" << empleado.bonificacion << endl;
    cout << "Sueldo Neto: $" << empleado.sueldoNeto << endl;
    cout << "-------------------------" << endl;
}

void mostrarResumen(int totalContratados, int totalNombrados, double totalSueldosContratados, double totalSueldosNombrados) {
    cout << "Resumen Consolidado:" << endl;
    cout << "Cantidad de empleados contratados: " << totalContratados << endl;
    cout << "Cantidad de empleados nombrados: " << totalNombrados << endl;
    cout << fixed << setprecision(2);
    cout << "Total acumulado de sueldos netos de empleados contratados: $" << totalSueldosContratados << endl;
    cout << "Total acumulado de sueldos netos de empleados nombrados: $" << totalSueldosNombrados << endl;
}

int main() {
    int numEmpleados;

    cout << "Ingrese el numero de empleados que desea ingresar: ";
    cin >> numEmpleados;

    vector<Empleado> empleados(numEmpleados);

    for (int i = 0; i < numEmpleados; ++i) {
        cout << "\nIngrese el nombre del empleado: ";
        cin >> empleados[i].nombre;
        cout << "Ingrese el tipo de empleado (C-contratado, N-nombrado): ";
        cin >> empleados[i].tipo;
        cout << "Ingrese el sueldo básico del empleado: ";
        cin >> empleados[i].sueldoBasico;

        empleados[i].deduccionAFP = calcularDeduccionAFP(empleados[i].sueldoBasico);
        empleados[i].deduccionSeguro = calcularDeduccionSeguro(empleados[i].sueldoBasico);
        empleados[i].bonificacion = calcularBonificacion(empleados[i].sueldoBasico, empleados[i].tipo);
        empleados[i].sueldoNeto = calcularSueldoNeto(empleados[i].sueldoBasico, empleados[i].deduccionAFP, empleados[i].deduccionSeguro, empleados[i].bonificacion);
    }

    int totalContratados = 0, totalNombrados = 0;
    double totalSueldosContratados = 0, totalSueldosNombrados = 0;

    for (int i = 0; i < numEmpleados; ++i) {
        mostrarDetallesEmpleado(empleados[i]);
        if (empleados[i].tipo == 'C') {
            totalContratados++;
            totalSueldosContratados += empleados[i].sueldoNeto;
        } else if (empleados[i].tipo == 'N') {
            totalNombrados++;
            totalSueldosNombrados += empleados[i].sueldoNeto;
        }
    }

    mostrarResumen(totalContratados, totalNombrados, totalSueldosContratados, totalSueldosNombrados);

    return 0;
}

