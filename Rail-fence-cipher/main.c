#include <stdio.h>

void logo(){
  printf("______      _ _    __                           _       _\n");
  printf("| ___ \\    (_) |  / _|                         (_)     | |\n");
  printf("| |_/ /__ _ _| | | |_ ___ _ __   ___ ___    ___ _ _ __ | |__   ___ _ __\n");
  printf("|    // _` | | | |  _/ _ \\ '_ \\ / __/ _ \\  / __| | '_ \\| '_ \\ / _ \\ '__|\n");
  printf("| |\\ \\ (_| | | | | ||  __/ | | | (_|  __/ | (__| | |_) | | | |  __/ |\n");
  printf("\\_| \\_\\__,_|_|_| |_| \\___|_| |_|\\___\\___|  \\___|_| .__/|_| |_|\\___|_|\n");
  printf("                                                 | |\n");
  printf("                                                 |_|\n");
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
