/**
Para el curso de Algoritmia se tiene las secciones U, V, W, las cuales a lo más tienen 30
alumnos. Se pide almacenar por sección las notas de la PC1.
Luego indicar la nota promedio por sección y finalmente eliminar las notas de aquellos
alumnos que están por debajo del promedio por cada sección.
U  V   W
12  11  13
07  02  04
    04  04
    10  02
*/

#include <iostream>
using namespace std;
int main() {
    // creando la matriz
    int a[3][30];
    int n[3];
    int num = 0;
    float prom[3];
    // ingresando los datos
    for (int i=0 ; i<3; i++) {
        cout << "--ingresando datos de la seccion " << (i+1) << "--" << endl;
        cout << "Cantidad de alumnos: ";
        cin >> num;
        n[i] = num;
        float s = 0;
        for (int j = 0; j < n[i]; j++) {
            cout << "Nota de alumno #" << (j+1) << ": ";
            cin >> a[i][j];
            s += a[i][j];
        }
        prom[i] = s/n[i];
    }
    // eliminando archivos
    for (int i = 0; i < 3; i++) {
        int j = 0;
        while (j < n[i]) {
            if (a[i][j] < prom[i]) {
                // eliminacion
                int pos = j;
                while (pos < n[i] - 1) {
                    a[i][pos] = a[i][pos+1];
                    pos++;
                }
                n[i]--; 
            } else {
                j++;
            }
        }
    }
    // imprimir
    for (int i=0; i<3; i++) {
        cout << "CLASE #" << (i+1) << ":" << endl;
        for (int j=0; j<n[i]; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}