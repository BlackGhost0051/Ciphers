// Match counting is a method that helps to determine the key length when using an XOR cipher. Let's understand how it works:
// We apply the XOR operation to the ciphertext using the ciphertext itself as the key with different offsets.
// Count the number of matching bytes between the result and the original ciphertext.
// If the offset is a multiple of the key length, more than 6% of bytes will match. If not, then less than 0.4% will match (assuming that the plain ASCII text is encoded with a random key).
// This method is particularly useful when we are dealing with English texts, where there are 1.3 bits of valid information per byte. The large redundancy allows us to determine the encryption method.
// The minimum offset from one value multiple of the key length to another is the key length. We then shift the ciphertext by this length and perform an XOR operation on the shifted and original ciphertexts. The result is to remove the key and get the plaintext subjected to the XOR operation with itself shifted by the key length.


#include <stdio.h>

void printBinary(char ch) {
    for (int j = 7; j >= 0; j--) {
        printf("%d", (ch >> j) & 1);
    }
}

int length(char *tab){
  int n = 0;
  while(tab[n] != '\0'){n++;}
  return n;
}


void test(char *file_name){
  int i = 0, j = 0, k = 0, c_rep; // count repetitions
  char c;
  FILE *file;
  char key[1000];

  file = fopen(file_name,"r");

  if(file == NULL){
    printf("Error file not found");
  }

  while((c = fgetc(file)) != EOF){
    printf("%c", c);
    key[j] = c;
    j++;
  }
  int key_length = length(key);
  printf("\n\n");

  for(k=1; k <= key_length; k++){
    printf("\t=========== %d ===========\n", k);
    rewind(file);
    while((c = fgetc(file)) != EOF){

      unsigned char xor = c^key[i];

      printf("%c = ", c);
      printBinary(c);
      printf("\t%c = ",key[i]);
      printBinary(key[i]);
      printf("\t%c = ", xor);
      printBinary(xor);
      printf("\n");

      i++;
      if(i >= k){ // is the value of k key_lenght
        i = 0;
      }
    }
  }


  fclose(file);
  return;
}



int main(){
  char file_name[] = "cyphertext.txt";
  test(file_name);

  return 0;
}
