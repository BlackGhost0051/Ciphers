#include <stdio.h>

void logo(){

}

int main(){
  logo();

  int start = 1;
  int value;
  char inputFileName[] = "input.txt";

  while(start){
    printf("\n| MENU |\n");
    printf(" 0 -> Exit\n\n");

    printf("Enter value : ");
    scanf("%d", &value);

    switch(value){
      case 0:
        start = 0;
        break;
      default: 
        printf("Enter 0 !!!\n");
        break;
    }
  }

  return 0;
}
