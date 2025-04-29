#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;
    int notas[n][6];
    // INGRESANDO NOTAS
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            int nota;
            do {
                cout << "Ingrese la nota #" << j+1 << " para el estudiante " << i+1 << ": ";
                cin >> nota;
            } while (!(nota>=0 && nota<5));
            notas[i][j] = nota;
        }
    }

    // NOTA FINAL DE CADA ALUMNO
    for (int i = 0; i < n; i++) {
        notas[i][5] = 0;
        for (int j = 0; j < 5; j++) {
            notas[i][5] += notas[i][j];
        }
    }

        // IMPRIMIR LA MATRIZ DE NOTAS
        cout << "-- MATRIZ DE NOTAS --" << endl;
        for (int i = 0; i < n; i++) {
            cout << "ALUMNO #" << i+1 << ": ";
            for (int j = 0; j < 5; j++) {
                cout << notas[i][j] << " ";
            }
            cout << " | Nota final: " << notas[i][5];
            cout << endl;
        }

    // CANTIDAD DE APROBADOS
    int aprobados = 0;
    for (int i = 0; i < n; i++) {
        if (notas[i][5] >= 10) {
            aprobados++;
        }
    }

    double estudiantes = n;

    // PORCENTAJE APROBADOS
    double porcentaje_aprobados = (aprobados / estudiantes) * 100;
    // PORCENTAJE DESAPROBADOS
    double porcentaje_desaprobados = 100 - porcentaje_aprobados;
    // IMPRIMIR PORCENTAJES DE APROBADOS Y DESAPROBADOS
    cout << "Porcentaje de aprobados: " << porcentaje_aprobados << "%." << endl;
    cout << "Porcentaje de desaprobados: " << porcentaje_desaprobados << "%." << endl;
    
    // PREGUNTAS FACILES Y DIFICILES
    double recurrencia[5] = {0, 0, 0, 0, 0};
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < n; i++) {
            recurrencia[j] += notas[i][j];
        }
        cout << "PREGUNTA " << (j+1) << ": " << recurrencia[j] << " | ";
    }
    cout << endl;
    // ENCONTRANDO LA FACIL Y DIFICIL
    int mayor, menor;
    mayor = recurrencia[0];
    for (int i = 0; i < 4; i++) {
        if (recurrencia[i+1] > recurrencia[i]) {
            mayor = recurrencia[i + 1]; 
        }
    }
    menor = recurrencia[0];
    for (int i = 0; i < 4; i++) {
        if (recurrencia[i] > recurrencia[i+1]) {
            menor = recurrencia[i+1]; 
        }
    }
    // IMPRIMIENDO RESULTADO FINAL
    cout << "Las preguntas mas faciles fueron: ";
    for (int i = 0; i < 5; i++) {
        if (mayor == recurrencia[i]) {
            cout << (i + 1) << " ";
        }
    }
    cout << endl;
    cout << "Las preguntas mas dificiles fueron: ";
    for (int i = 0; i < 5; i++) {
        if (menor == recurrencia[i]) {
            cout << (i + 1) << " ";
        }
    }
    cout << endl;
    return 0;
}