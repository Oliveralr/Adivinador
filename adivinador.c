#include <stdio.h>
#include <stdlib.h> //Librería para system()
#include <string.h>

#define MAX 1000
#define TRUE 1
#define FALSE 0

char array(char s[]); //Prototipo.
void gotoxy(int x, int y);

void gotoxy(int x, int y){
  printf("%c[%d;%df",0x1B,y,x); //Dirección a la que apunta gotoxy() en la terminal.
}

int main(void){

  //Arreglos uno con el mensaje a pantalla y otro vacío.
  char inv[MAX] = {"Oh gran Huitzilopochtli dime: "}, save[MAX];
  int c,d, i = -1, j = 0, col = 0;

  gotoxy(1,1); for(col=0; col < 70; col++) printf(" ");
  printf("\n");
  gotoxy(2,2); for(col=0; col < 70; col++) printf(" ");
  printf("\n");

  system("/bin/stty raw");
  c = getchar();
  if(c == '1'){
    system("/bin/stty raw"); //Ejecución de System().
    while((c=getchar())!= '.') {
      i += 1;
      save[i] = c;    //Recolleción de caracteres a un arreglo.
      printf("%c",inv[i]);
  }

    system("/bin/stty raw");
    while((d=getchar())!= '.') { //texto de "humo".
      printf("%c", d);
  }

    printf("\t\t");
    array(save); //Llamada y parametrización.
    printf("\n\n");

    system("/bin/stty cooked"); 
    printf("\n");
  }

  else {
  
    printf("Tu no eres digno de hablar con Huitzilopochtli >:V\n");
    system("/bin/stty cooked");
    printf("\n");
  }

  //system("/bin/stty cooked");
  
  return 0; 

}

//Impresión Básica de un Arreglo.
char array(char s[]){
  int k, len = strlen(s);

  for(k = 0; k < len; k++){
    printf("%c",s[k]);
  }
  return TRUE;
}
