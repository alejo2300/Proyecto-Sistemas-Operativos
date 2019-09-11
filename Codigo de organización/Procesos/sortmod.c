#include<stdio.h> 
int main (int argc, char **argv) { 
/* programa que imprime los argumentos de la l�nea de comandos */ 
int i; 
  printf("argc = %d\n",argc); 
  for (i=0;i<argc;++i) 
    printf("argv[%d]:%s\n",i,argv[i]);
}
