// El restaurante “Rico y Barato” prepara menús. El menú consta de “n” platos que se preparan en base de “m” insumos.Para el control de sus existencias tiene una matriz, llamada “CANTIDAD”, que contiene la cantidad de cada insumo (en gramos) necesario para cada plato. Como los costos de los insumos (soles/kilo) varían constantemente, estos se encuentran en un arreglo llamado “COSTOS”. Se pide elaborar un programa en C++, que permita presentar el menú del día ordenado en orden ascendente con respecto del costo total de los insumos usados en la preparación de cada plato. Ejemplo: Si consideramos que el menú tiene 3 platos y se preparan en base de 4 insumos, la matriz “CANTIDAD” tendrá los siguientes elementos:
#include <iostream>
using namespace std;
int main() {
    // CREANDO LA MATRIZ CANTIDAD
    int m, n;
    cout << "Ingrese la cantidad de platos: ";
    cin >> n;
    cout << "Ingrese la cantidad de insumos: ";
    cin >> m;
    double CANTIDAD[m][n]; // [insumo][plato]
    double COSTO[m];
    // LEER LOS COSTOS DE LOS INSUMOS
    for (int i = 0; i < m; i++) {
        cout << "Ingrese el costo (por kg) del insumo #" << (i+1) << ": ";
        cin >> COSTO[i];
    }

    // INSERTANDO DATOS EN LA MATRIZ CANTIDAD
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Ingrese la cantidad del insumo #" << (i+1) << " para el plato #" << (j+1) << ": ";
            cin >> CANTIDAD[i][j];
        } 
    }
    // MOSTRAR LA MATRIZ CANTIDAD
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << CANTIDAD[i][j] << " ";
        }
        cout << endl;
    }

    // CALCULAR COSTO DE CADA PLATO
    double COSTO_TOTAL[n][2];
    for (int j = 0; j < n; j++) {
        COSTO_TOTAL[j][1] = j+1;
        double total = 0;
        for (int i = 0; i < m; i++) {
            total += (CANTIDAD[i][j] * COSTO[i]) / 1000;
        }
        COSTO_TOTAL[j][0] = total;
    }


    // ORDENAR PLATOS POR COSTO
    for (int j = 0; j < n-1; j++) {
        for (int k = j+1; k < n; k++) {
            if (COSTO_TOTAL[j][0] > COSTO_TOTAL[k][0]) {
                double aux = COSTO_TOTAL[k][0];
                COSTO_TOTAL[k][0] = COSTO_TOTAL[j][0];
                COSTO_TOTAL[j][0] = aux;
                double temp = COSTO_TOTAL[k][1];
                COSTO_TOTAL[k][1] = COSTO_TOTAL[j][1];
                COSTO_TOTAL[j][1] = temp;
            }
        }
    }

    // IMPRIMIR RESULTADOS
    cout << "-- RESULTADOS --" << endl;
    for (int j = 0; j < n; j++) {
        cout << "Orden: " << j+1 << " | " << "Plato: " << COSTO_TOTAL[j][1] << " | " << "Costo: " << COSTO_TOTAL[j][0] << endl;  
    }
    return 0;
}
