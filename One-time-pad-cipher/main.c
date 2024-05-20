#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//char alphabet[] = "abcdefghijklmnopqrstuvwxyz"; // Uncomment if you need a lowercase alphabet
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void logo(){

}

void encrypt(const char *inputFileName, const char *keyFileName){
    char c, key;
    FILE *inputFile, *keyFile, *outputFile;

    inputFile = fopen(inputFileName, "r");
    keyFile = fopen(keyFileName, "r");
    outputFile = fopen("encrypted.txt", "w");

    if( inputFile == NULL ){
        printf("Error open input file!");
        return;
    } 
    if ( keyFile == NULL ) {
        printf("Error open key file!");
        return;
    }

    while((c = fgetc(inputFile)) != EOF){
        if(key != EOF){
            if( 'A' <= c && c <= 'Z' ){
                key = fgetc(keyFile);
                c = 'A' + (c - 'A' + key) % 26;
                fputc(c, outputFile);
            } else if('a' <= c && c <= 'z'){
                key = fgetc(keyFile);
                c = 'a' + (c - 'a' + key) % 26;
                fputc(c, outputFile);
            } else {
                fputc(c, outputFile);
            }
        } else {
            printf("Key is smaller than the text !!!");
            return;
        }
    }

    fclose(inputFile);
    fclose(keyFile);
    fclose(outputFile);
}

void decrypt(const char *inputFileName, const char *keyFileName){

}

void genKeyFile(const char *inputFileName, const char *keyGenFileName){
    char c;
    FILE *inputFile, *keyGenFile;

    inputFile = fopen(inputFileName, "r");
    keyGenFile = fopen(keyGenFileName, "w");

    if(inputFile == NULL){
        printf("Error open input file!");
        return;
    }

    srand(time(NULL));

    while((c = fgetc(inputFile)) != EOF){
        if( 'A' <= c && c <= 'Z' ){
            int randomNumber = (rand() % 26);
            fputc(alphabet[randomNumber], keyGenFile);
        } else if('a' <= c && c <= 'z'){
            int randomNumber = (rand() % 26);
            fputc(alphabet[randomNumber], keyGenFile);
        } /*else {
            fputc(c, keyGenFile);
        }*/
    }

    fclose(inputFile);
    fclose(keyGenFile);

    printf("\nKey generated in %s\n", keyGenFileName);
}

int main(){
    logo();

    char inputFileName[] = "input.txt";
    char keyFileName[] = "key.txt";
    char keyGenFileName[] = "keyGen.txt";

    int start = 1;
    int value;


    while (start){
        printf("\n| MENU |\n");
        printf(" 1 -> Encrypt\n");
        printf(" 2 -> Decrypt\n");
        printf(" 3 -> Generate KEY\n");
        printf(" 0 -> Exit\n\n");

        printf("Enter value : ");
        scanf("%d", &value);


        switch (value){
        case 1:
            encrypt(inputFileName, keyFileName);
            break;
        case 2:
            break;
        case 3:
            genKeyFile(inputFileName, keyGenFileName);
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