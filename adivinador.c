#include <stdio.h>
#include <stdlib.h> //Biblioteca para system()
#include <string.h>
#include <unistd.h> // Si, es parte del ANSI.


#define MAX 1000
#define TRUE 1
#define FALSE 0

char array(char s[]); //Prototipo.
void core();
void gotoxy(int x, int y);

//Dirección a la que apunta gotoxy() en la terminal.
void gotoxy(int x, int y)
{
        printf("%c[%d;%df",0x1B,y,x);
}

/* Esta función funcionará en terminales ANSI que además respeten el
 * estándar POSIX, funcionará en todos los sitemas operativos ya que
 * ANSI soporta las secuencias de escape*/




//Estructura principal del código.
int main(void){
  char k;


  system("/bin/stty raw");
  char r = getchar();
  if(r == '1'){
    core();

  }else{

    do{
      printf("Tu no eres digno de hablar con Huitzilopochtli >:V\n\r\n");
      system("/bin/stty raw");
      k=getchar();

    }while(k != '2');

    core();
  }

  printf("\n");
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

//Funcionamiento Principal
void core()
{
  //Arreglos uno con el mensaje a pantalla y otro vacío.
  char inv[MAX] = {"Oh gran Huitzilopochtli dime: "}, save[MAX];
  int c,d, i = -1, j = 0;
  char q[] = {"\U0001F61C \U0001F61C \U0001F61C"};

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

  printf("\n\n\r");
  array(save); //Llamada y parametrización.
  int l, large = strlen(q);
  for(l = 0; l < large; l++){ //Impresión del Emoji.
    printf("%c", q[l]);
  }
  printf("\n\n");

  system("/bin/stty cooked");
  printf("\n\r");
}
