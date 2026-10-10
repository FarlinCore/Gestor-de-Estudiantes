
#include <stdio.h>
struct Estudiante {
    unsigned int matricula;
    char nombre[40];
    char carrera[40];
    float promedio;
};

void limpiarBuffer() {
    while(getchar()!='\n');
}

void registrarEstudiante(struct Estudiante estudiante[])
{
    printf("--- Registro de Estudiantes ---\n");
    for(unsigned int i=0;i<5;i++)
    {
        printf("-- Estudiante #%u\n", i + 1);

        printf("Matricula: ");
        while((scanf("%u",&estudiante[i].matricula)) != 1)
        {
            printf("\nColoca una matricula valida\n");
            printf("Matricula: ");
            limpiarBuffer();
        }

        printf("Nombre: ");
        scanf(" %[^\n]",estudiante[i].nombre);
        limpiarBuffer();

        printf("Carrera: ");
        scanf(" %[^\n]",estudiante[i].carrera);
        limpiarBuffer();

        printf("Promedio: ");

        while (scanf("%f", &estudiante[i].promedio) != 1 ||
               estudiante[i].promedio < 0 ||
               estudiante[i].promedio > 100)
        {
            printf("Promedio invalido. Introduce un valor entre 0 y 100: ");
            limpiarBuffer();
        }

        limpiarBuffer();

    }
}

void mostrarEstudiante(struct Estudiante estudiante[])
{
    printf("\n==== Estudiantes Registrados ==== \n");
    for(unsigned int i=0;i<5;i++)
    {
        printf("---> Estudiante #%u <--- \n", i + 1);
        printf("Matricula: %u-%u-%u\n",
            estudiante[i].matricula / 1000000,
            (estudiante[i].matricula / 10000) % 100,
            estudiante[i].matricula % 10000);

        printf("Nombre: %s\n", estudiante[i].nombre);
        printf("Carrera: %s\n", estudiante[i].carrera);
        printf("Promedio: %.2f\n\n", estudiante[i].promedio);
    }
}

void buscarEstudiante(struct Estudiante estudiante[])
{
    unsigned int opcion;
    printf("\n==== Buscar Estudiante ==== \n");
    printf("Matricula del estudiante: ");
    scanf("%u", &opcion);

    for(unsigned int i=0;i<5;i++)
    {
        if(estudiante[i].matricula == opcion)
        {
            printf("Matricula: %u-%u-%u\n",
                estudiante[i].matricula / 1000000,
                (estudiante[i].matricula / 10000) % 100,
                estudiante[i].matricula % 10000);
            printf("Nombre: %s\n", estudiante[i].nombre);
            printf("Carrera: %s\n", estudiante[i].carrera);
            printf("Promedio: %.2f\n\n", estudiante[i].promedio);
            return;
        }
    }

    printf("\n--> Estudiante no encontrado: Esta matricula no existe!\n\n");
}

void determinarPromedioMayor(struct Estudiante estudiante[])
{
    float promedioMayor = 0;
    unsigned int indiceEstudiante = 0;
    for (unsigned int i=0;i<5;i++)
    {
        if (estudiante[i].promedio > promedioMayor) {
            promedioMayor = estudiante[i].promedio;
            indiceEstudiante = i;
        }
    }
    printf("====Mayor Promedio Academico====\n");

    printf("---El estudiante con promedio mayor es: \n");
    printf("Nombre: %s\n", estudiante[indiceEstudiante].nombre);
    printf("Matricula: %u-%u-%u\n",
        estudiante[indiceEstudiante].matricula / 1000000,
        (estudiante[indiceEstudiante].matricula / 10000) % 100,
        estudiante[indiceEstudiante].matricula % 10000);
    printf("Promedio:  %.2f\n", promedioMayor);
    printf("Carrera: %s\n\n",
           estudiante[indiceEstudiante].carrera);
}

int main(void) {

    printf("===BIENVENIDO AL SISTEMA GESTOR DE ESTUDIANTES===\n");

    struct Estudiante estudiantes[5];

    registrarEstudiante(estudiantes);

    while (1)
    {
        unsigned int opcion;
        printf("1. Mostrar Lista de Estudiantes\n");
        printf("2. Buscar Estudiante\n");
        printf("3. Determinar Promedio Academico mas alto\n");
        printf("4. Salir\n");

        printf("Coloque una opcion =>");
        if (scanf("%u", &opcion) != 1) {
            printf("Entrada invalida.\n");
            limpiarBuffer();
            continue;
        }

        limpiarBuffer();

        if (opcion < 1 || opcion > 4) {
            printf("Selecciona una opcion del 1 al 4.\n");
            continue;
        }

        switch (opcion)
        {
            case 1: mostrarEstudiante(estudiantes);
                break;
            case 2: buscarEstudiante(estudiantes);
                break;
            case 3:
                determinarPromedioMayor(estudiantes);
                break;
            case 4:
                printf("******GRACIAS POR USAR NUESTRO PROGRAMA******\n");
                return 0;
            default:
                printf("Opcion Invalida\n");
                break;
        }
    }
    return 0;
}
