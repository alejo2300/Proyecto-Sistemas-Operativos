#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (int argc, char **argv) {
//Organizacion de archivos en un n archivo por medio de procesos
    char cline[100];
    int i;
    FILE *archivo,*resultado;
    char all[10000][100];
    int pos=0;
    for (i=1;i<(argc-1);++i) {
        printf("El archivo a leer es : %s\n", argv[i]);
        archivo = fopen(argv[i], "r");
        while (feof(archivo) == 0) {
            if (NULL != fgets(cline, 100, archivo)) {
                printf("%s", cline);
                strcpy(all[pos],cline);
                ++pos;

            }
        }
        if (archivo == NULL) {
            printf("Error al abrir el archivo %s\n", argv[i]);
        }
        fclose(archivo);
    }
    printf("\n");


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









