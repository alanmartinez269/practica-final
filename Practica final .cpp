#include <iostream>
using namespace std;

int main() {
    int n, aprob = 0, reprob = 0;
    float calificaciones[20][4]; 
    float promedios[20];         
    float sumaTot = 0, notamax = -1, notamin = 101;

    do {
        cout << "Cantidad de estudiantes (max 20): "; cin >> n;
    } while (n < 1 || n > 20);

    //Ingreso de datos y almacenamiento en el arreglo
    int i = 0;
    do {
        float sumaEst = 0;
        cout << "\nEstudiante " << i + 1 << ":" << endl;
        
        for (int j = 0; j < 4; j++) {
            do {
                cout << "  Nota " << j + 1 << ": "; cin >> calificaciones[i][j];
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 100) 
                    cout << "Cantidad invalida" << endl;
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 100);
            
            // Esta parte aqui es para que el programa determine la nota mas alta y la mas baja.
            if (calificaciones[i][j] > notamax) notamax = calificaciones[i][j];
            if (calificaciones[i][j] < notamin) notamin = calificaciones[i][j];
            
            sumaEst += calificaciones[i][j];
        }
        
        promedios[i] = sumaEst / 4;
        sumaTot += promedios[i];
        
        // Contador de aprobados/reprobados
        if (promedios[i] >= 70) aprob++; else reprob++;
        
        i++;
    } while (i < n);

    //este bucle es para mostrar el resultado de los estudiantes.
    cout << "Reporte de calificaciones por estudiantes" << endl;
    for (int k = 0; k < n; k++) {
        cout << "Estudiante " << k + 1 << endl;
        cout << "Notas: " << endl;
        for (int m = 0; m < 4; m++) {
            cout << "" << calificaciones[k][m] << ""<<endl;
        }
        cout << "Promedio: " << promedios[k] << endl;
    }

    cout << "Resultados" << endl;
    cout << "Promedio general del grupo: " << sumaTot / n << endl;
    cout << "Calificacion mas alta: " << notamax << endl;
    cout << "Calificacion mas baja: " << notamin << endl;
    cout << "Estudiantes que Aprobaron: " << aprob << endl;
    cout << "Estudiantes que Reprobaron: " << reprob << endl;

    return 0;
}