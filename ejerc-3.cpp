/*
 * Una empresa consta de 3 sucursales; y por cada sucursal, se tiene a las más 4 áreas de ventas;
y en cada área de venta laboran a los más 20 empleados.
Se desea almacenar los sueldos de todos empleados. Luego por cada sucursal y área
indicar el # de empleados que ganan más (o tienen el mayor sueldo
 */
#include <iostream>
using namespace std;
int main() {
    // declarando variables
    float empresa[3][4][20];
    int nareas[3];
    int nempleados[3][4];
    int num;
    // ingresando datos
    for (int i = 0; i < 3; i++) {
        cout << "ingrese la cantidad de areas por sucursal #" << (i+1) << ": ";
        cin >> num;
        nareas[i] = num;
        for (int j = 0; j < nareas[i]; j++) {
            cout << "ingrese el numero de empleados por area " << (j+1) << ": ";
            cin >> num;
            nempleados[i][j] = num;
            for (int k = 0; k < nempleados[i][j]; k++) {
                cout << "ingrese el sueldo del empleado #" << (k+1) << ": ";
                cin >> empresa[i][j][k];
            }
        }
    }
    // imprimiendo resultados
    for (int i = 0; i < 3; i++) {
        cout << "---Sucursal " << (i+1) << "---" << endl;
        for (int j = 0; j < nareas[i]; j++) {
            cout << "Area " << (j+1) << endl;
            int mayor = empresa[i][j][0];
            int cont;
            for (int k = 1; k < nempleados[i][j]; k++) {
                if (empresa[i][j][k] > mayor) {
                    mayor = empresa[i][j][k];
                    cont = 1;
                } else if (empresa[i][j][k] == mayor) {
                    cont++;
                }
            } 
            cout << "el nro de empleados que tienen el mayor sueldo (" << mayor << ") en la sucursal " << (i+1) << " del area " << (j+1) <<  " es de: " << cont << endl;
        }
    }
}