#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (int argc, char **argv) {
//Organizacion de archivos en un n archivo por medio de procesos
    char cline[100];
    int i;
    FILE *archivo;
    for (i=1;i<(argc-1);++i){
        printf("El archivo a leer es : %s\n",argv[i]);
        archivo=fopen(argv[i],"r");
        while(feof(archivo)==0){
            if(NULL!=fgets(cline,100,archivo))
            printf("%s",cline);
        }
        if(archivo==NULL){
            printf("Error al abrir el archivo %s\n",argv[i]);
        }
	fclose(archivo);
    }
}









