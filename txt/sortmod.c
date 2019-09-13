#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (int argc, char **argv) {
//Organizacion de archivos en un n archivo por medio de procesos
    int i;
    FILE *f;
    for (i=1;i<(argc-1);++i){
        printf("El archivo a leer es : %s\n",argv[i]);
        f=fopen(argv[i],"rb");
        char cadena[100],sbcadena[50];
        while(feof(f)==0){
            fscanf(f,"%s",&cadena);
            fscanf(f,"%s",&sbcadena);
            strcat(cadena," ");
            strcat(cadena,sbcadena);
            printf("%s\n",cadena);
        }
        if(f==NULL){
            printf("Error al abrir el archivo %s\n",argv[i]);
        }
    }
}









