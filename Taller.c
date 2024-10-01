#include <stdio.h>

int main (int argc, char *argv[]) {
    char Nombres[5][20];
    char Materias [3][20];
    double Notas[5][3];
    for (int i = 0; i < 3; i++)
    {
        printf("Ingrese las materias %d: ", i++);
        fflush(stdin);
        fgets(Materias[i],20,stdin);
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese los nombres %d: ", i++);
        fflush(stdin);
        fgets(Nombres[i],20,stdin);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
           for (int i = 0; i < 3; i++)
           {
             
           }
        
        }
        
    }
    


    return 0;
}