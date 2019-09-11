#include<stdio.h> 
int main (int argc, char **argv) { 
/* programa que imprime los argumentos de la l�nea de comandos */ 
int i; 
  printf("argc = %d\n",argc); 
  for (i=1;i<(argc-1);++i) 
    printf("El archivo a leer es : %s\n",argv[i]);
}
