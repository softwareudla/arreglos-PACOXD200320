#include <stdio.h>

int main () {
    char Nombres[5][20]; // Alumnos
    char Materias[3][20]; // Materias
    double Notas[5][3]; // Notas de los alumnos en las 3 materias
    double sumaNotas[3] = {0}; // Para almacenar la suma de notas por materia
    double maxNotas[3] = {0,0,0}; // Para almacenar la nota máxima por materia
    double minNotas[3] = {11,11,11}; // Para almacenar la nota mínima por materia
    double promedioAlumno[5] = {0}; // Promedio de cada alumno
    double NotaMinima = 6.0; // Nota mínima para aprobar

    // Ingreso de nombres de materias
    for (int i = 0; i < 3; i++) {
        printf("Ingrese el nombre de la materia %d: ", i+1);
        fflush(stdin);
        fgets(Materias[i], 20, stdin);
    }

    // Ingreso de nombres de los alumnos
    for (int i = 0; i < 5; i++) {
        printf("Ingrese el nombre del alumno %d: ", i+1);
        fflush(stdin);
        fgets(Nombres[i], 20, stdin);
    }

    // Ingreso de las notas de los alumnos para cada materia
    for (int i = 0; i < 5; i++) {
        printf("\nAlumno: %s", Nombres[i]);
        for (int j = 0; j < 3; j++) {
            do {
                printf("Ingrese la nota de %s para la materia %s (de 0 a 10): ", Nombres[i], Materias[j]);
                scanf("%lf", &Notas[i][j]);

                // Verificación del rango de la nota
                if (Notas[i][j] < 0 || Notas[i][j] > 10) {
                    printf("Error: La nota debe estar entre 0 y 10. Por favor, intente de nuevo.\n");
                }
            } while (Notas[i][j] < 0 || Notas[i][j] > 10);

            // Sumar la nota para el cálculo del promedio por materia
            sumaNotas[j] += Notas[i][j];

            // Acumular la nota para el promedio del alumno
            promedioAlumno[i] += Notas[i][j];

            // Verificar si es la nota máxima
            if (Notas[i][j] > maxNotas[j]) {
                maxNotas[j] = Notas[i][j];
            }

            // Verificar si es la nota mínima
            if (Notas[i][j] < minNotas[j]) {
                minNotas[j] = Notas[i][j];
            }
        }

        // Calcular el promedio del alumno
        promedioAlumno[i] /= 3;
    }

    // Mostrar promedios, máximos y mínimos de cada materia
    for (int j = 0; j < 3; j++) {
        printf("\nResultados para la materia %s:\n", Materias[j]);
        printf("Promedio: %.2lf\n", sumaNotas[j] / 5);
        printf("Nota máxima: %.2lf\n", maxNotas[j]);
        printf("Nota mínima: %.2lf\n", minNotas[j]);
    }

    // Mostrar qué estudiantes aprobaron y cuáles no
    printf("\n--- Resultados de los estudiantes ---\n");
    for (int i = 0; i < 5; i++) {
        printf("\nEstudiante: %s", Nombres[i]);
        printf("Promedio general: %.2lf\n", promedioAlumno[i]);
        if (promedioAlumno[i] >= NotaMinima) {
            printf("Resultado: Aprobado\n");
        } else {
            printf("Resultado: Reprobado\n");
        }
    }

    return 0;
}
