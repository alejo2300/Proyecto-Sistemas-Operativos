#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    char cline[100];//Var guardado linea de monento
    FILE *archivo,*resultado;//Declaracion de archivos lectura y resultado
    char all[10000][100];//Estructura de guardado de datos
    int pos=0;//Contador de datos
    if ( (pid=fork()) == 0 )
    { /* hijo */
        printf("Soy el hijo (%d, hijo de %d)\n", getpid(),getppid());
        //Ordenamiento
        char cpy[100];

        for(int i=0;i<pos;i++){
            for(int j=i;j<pos;j++){
                if((strcmp(all[i],all[j]))>0) {
                    strcpy(cpy, all[j]);
                    strcpy(all[j],all[i]);
                    strcpy(all[i],cpy);
                }
            }
        }

        printf("\nValores ya ordenados:\n");
        int nar;
        nar=argc-1;
        resultado = fopen(argv[nar], "a+");
        for(int i=0;i<pos;i++){
            printf("%s",all[i]);
            fputs( all[i], resultado );
        }
        fclose(resultado);


    }
    else
    { /* padre */
        printf("Soy el padre (%d, hijo de %d)\n", getpid(),getppid());
        for (int i=1;i<(argc-1);++i) {//For archivos de texto
            printf("El archivo a leer es : %s\n", argv[i]);
            archivo = fopen(argv[i], "r");
            while (feof(archivo) == 0) {
                if (NULL != fgets(cline, 100, archivo)) {
                    printf("%s", cline);
                    strcpy(all[pos],cline);//Llevar al resultado
                    ++pos;

                }
            }
            if (archivo == NULL) {
                printf("Error al abrir el archivo %s\n", argv[i]);
            }
            fclose(archivo);
        }
        printf("\n");

    }

    return 0;
}