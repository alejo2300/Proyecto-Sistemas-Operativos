#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (int argc, char **argv) {
//Organizacion de archivos en un n archivo por medio de procesos
    int i;
    FILE *archivo;
    int pos=0;
    for (i=1;i<(argc-1);++i){
        printf("El archivo a leer es : %s\n",argv[i]);
        archivo=fopen(argv[i],"r");
        char cline[100];
        while(!feof(archivo)){
            fgets(cline,100,archivo);
            pos++;

            printf("%s",cline);
        }
        if(archivo==NULL){
            printf("Error al abrir el archivo %s\n",argv[i]);
        }
    }
}









