#include<stdio.h> 
int main (int argc, char **argv) { 
//Organizacion de archivos en un n archivo por medio de procesos
int i;  
  for (i=1;i<(argc-1);++i) 
    printf("El archivo a leer es : %s\n",argv[i]);
}
