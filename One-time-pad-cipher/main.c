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

    while ((c = fgetc(inputFile)) != EOF) {
        if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
            key = fgetc(keyFile);
            if (key == EOF) {
                printf("Key is smaller than the text!!!\n");
                fclose(inputFile);
                fclose(keyFile);
                fclose(outputFile);
                return;
            }

            if ('A' <= key && key <= 'Z') {
                key = key - 'A';
            } else if ('a' <= key && key <= 'z') {
                key = key - 'a';
            } else {
                printf("Invalid key character!\n");
                fclose(inputFile);
                fclose(keyFile);
                fclose(outputFile);
                return;
            }

            if ('A' <= c && c <= 'Z') {
                c = 'A' + (c - 'A' + key) % 26;
            } else if ('a' <= c && c <= 'z') {
                c = 'a' + (c - 'a' + key) % 26;
            }
        }
        fputc(c, outputFile); // comment if you need without space, '\n' ...
    }


    fclose(inputFile);
    fclose(keyFile);
    fclose(outputFile);
}

void decrypt(const char *inputFileName, const char *keyFileName){
    int key;
    char c;
    FILE *inputFile, *keyFile, *outputFile;

    inputFile = fopen(inputFileName, "r");
    keyFile = fopen(keyFileName, "r");
    outputFile = fopen("decrypted.txt", "w");

    if( inputFile == NULL ){
        printf("Error open input file!");
        return;
    } 
    if ( keyFile == NULL ) {
        printf("Error open key file!");
        return;
    }

    while ((c = fgetc(inputFile)) != EOF) {
        if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
            key = fgetc(keyFile);
            if (key == EOF) {
                printf("Key is smaller than the text!!!\n");
                fclose(inputFile);
                fclose(keyFile);
                fclose(outputFile);
                return;
            }

            if ('A' <= key && key <= 'Z') {
                key = key - 'A';
            } else if ('a' <= key && key <= 'z') {
                key = key - 'a';
            } else {
                printf("Invalid key character!\n");
                fclose(inputFile);
                fclose(keyFile);
                fclose(outputFile);
                return;
            }

            if ('A' <= c && c <= 'Z') {
                c = 'A' + (c - 'A' - key + 26) % 26;
            } else if ('a' <= c && c <= 'z') {
                c = 'a' + (c - 'a' - key + 26) % 26;
            }
        }
        fputc(c, outputFile); // comment if you need without space, '\n' ...
    }


    fclose(inputFile);
    fclose(keyFile);
    fclose(outputFile);
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
        } 
        /*else { // if you need to generate a key with other
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
            decrypt(inputFileName, keyFileName);
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