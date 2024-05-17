#include <stdio.h>

void logo(){

}

void decrypt(const char* targetSymbol ,const char* inputFileName){
    FILE *inputFile, *outputFile;

    inputFile = fopen(inputFileName, "r");
    outputFile = fopen("decrypted.txt", "w");


    fclose(inputFile);
    fclose(outputFile);
}

int main(){
    logo();

    char inputFileName[] = "input.txt";

    int start = 1;
    int value;
    char targetSymbol;


    while(start){
        printf("\n| MENU |\n");
        printf(" 1 -> Encrypt\n");
        printf(" 2 -> Decrypt\n");
        printf(" 0 -> Exit\n\n");

        printf("Enter value : ");
        scanf("%d", &value);

        switch(value) {
            case 1:
                break;
            case 2:
                printf(" Target Symbol for decrypt = ");
                scanf("%c", &targetSymbol);
                decrypt(&targetSymbol, inputFileName);
                break;
            case 0:
                start = 0;
                break;
            default:
                printf("Enter 1 , 2 or 0 !!!\n");
                break;
        }
    }
    return 0;
}
