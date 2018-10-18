#include <stdio.h>
#include <stdlib.h> //Librería para system()
#include <string.h>


#define MAX 1000
#define TRUE 1
#define FALSE 0

char array(char s[]); //Prototipo.
void core();
void gotoxy(int x, int y);

void gotoxy(int x, int y){
  printf("%c[%d;%df",0x1B,y,x); //Dirección a la que apunta gotoxy() en la terminal.
}

//Estructura principal del código.
int main(void){
  char k,ex;
  int col;

    //Estos gotoxy limpian la barra de comandos, dejando la terminal limpia.
    gotoxy(1,1); for(col=0; col < 110; col++) printf(" ");
    printf("\n");
    gotoxy(2,2); for(col=0; col < 110; col++) printf(" ");
    printf("\n");

    do{

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

      system("/bin/stty raw");

    } while((ex=getchar()) == '.');

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
  char inv[MAX] = {"Oh gran Huitzilopochtli dime: "}, save[MAX], a[MAX];
  int c,d, i = -1, j = 0, p = 0, w = 0, ty = strlen(a);
  char q[] = {"\U0001F61C \U0001F61C \U0001F61C"}, empty;

  system("/bin/stty raw"); //Ejecución de System().
  while((c=getchar())!= '.') {
      i += 1;
      save[i] = c;    //Recolección de caracteres a un arreglo.
      printf("%c",inv[i]);
  }

  system("/bin/stty raw");
  while((d=getchar())!= '.') { //texto de "humo".
      printf("%c", d);
      a[p] = d;
    
      //Fase de Borrado con BackSpace.
      if(d == '\b'){
        do{
          
         p--;
         a[p] = ' ';
         printf("%c",a[p]); 
        } while(d == '\b');
      }
      p++;
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
