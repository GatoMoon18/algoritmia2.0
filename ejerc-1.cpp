/**
 * Una empresa comercializadora de instrumentos musicales tiene las ventas mensuales en dinero,
 * por  cada tipo de instrumentos que vende (Cuerda, Viento, Percusión y Electrónicos).
 * Desarrollar un  algoritmo que determine cuál fue el mes en que ocurrió la mayor venta total y cuál
 * fue la línea de  instrumentos que tuvo la menor venta anual.
 */
#include <iostream>
using namespace std;
int main() {
    int i, j;
    float ventas[5][13], max, min;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 13; j++) {
            ventas[i][j] = 0;
        }
    }
    for (i = 1; i < 5; i++) {
        for (j = 1; j < 13; j++) {
            cout << "Ingrese la venta [" << i << "][" << j << "]: ";
            cin >> ventas[i][j];
            // ventas mensuales.
            ventas[0][j] += ventas[i][j];
            // ventas de equipo.
            ventas[i][0] += ventas[i][j]; 
        }
    }

    max = ventas[0][1];
    for (j = 2; j<13; j++) {
        if (ventas[0][j] > max) {
            max = ventas[0][j];
        }
    }

    cout << "ventas:" << endl;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 13; j++) {
            cout << ventas[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "El mes con mayor venta fue: " << max << endl;   
    for (j = 1; j <5; j++) {
        if (ventas[0][j] == max) {
            cout << ventas[0][j] << " ";
        }
    }
    cout << endl;
    min = ventas[1][0];
    for (i = 2; i < 5; i++) {
        if (ventas[i][0] < min) {
            min = ventas[i][0];
        }
    }
    cout << "El equipo con la menor venta anual ";
    for (i = 1; i < 5; i++) {
        if (ventas[i][0] == min) {
            cout << "'" << i << "'" << ": ";
            cout << ventas[i][0] << "; ";
        }
    }
    cout << endl;
    return 0;
}