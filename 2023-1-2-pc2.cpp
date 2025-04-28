// CREANDO UNA MATRIZ DE N A PARTIR DE LA SUMA DE LOS ELEMENTOS VECINOS DE CADA MATRIZ M (solo elementos aleatorios del 0 al 7)
#include <iostream>
using namespace std;
int main() {
    // SEMILLA DE NUMEROS ALEATORIOS
    srand(time(NULL));
    // GENERANDO LA MATRIZ M
    int M[5][5];
    int N[5][5];
    cout << "- MATRIZ M -" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            M[i][j] = rand() % 8;
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    // GENERACION DE MATRIZ N DONDE CADA ELEMENTO DE N ES LA MEDIANA DE LOS VECINOS DE M
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // PARA CADA ELEMENTO IDENTIFICAMOS A SUS VECINOS
            int vecinos[9];
            int contador = 0;
            // RECORREMOS LOS VECINOS
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = di + i;
                    int nj = dj + j;
                    // VERIFICAMOS QUE LAS COORDENADAS SE ENCUENTREN EN EL RANGO DE LA MATRIZ
                    if (ni >= 0 && ni < 5 && nj >= 0 && nj < 5) {
                        vecinos[contador] = M[ni][nj];
                        contador++;
                    }
                }
            }
            // ORDENAMOS LOS VECINOS DE MENOR A MAYOR
            for (int k = 0; k < contador-1; k++) {
                for (int l = k+1; l < contador; l++) {
                    if  (vecinos[l] < vecinos[k]) {
                        int aux = vecinos[l];
                        vecinos[l] = vecinos[k];
                        vecinos[k] = aux;
                    }
                }
            }
            // SACAMOS LA MEDIANA
            if (contador % 2 == 1) {
                N[i][j] = vecinos[contador/2];
            } else {
                double prom = (vecinos[contador/2] + vecinos[contador/2-1]) / 2.0f;
                N[i][j] = static_cast<int>(prom+0.5f);
            }
        }
    }
    // IMPRIMIENDO LA MATRIZ N
    cout << "- MATRIZ N -" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << N[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}