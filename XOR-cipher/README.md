# XOR cipher

With this program, you can encrypt and decrypt text using the XOR cipher.

## Content 
1. [How does the program work?](#how-does-the-program-work)
2. [How to install and run?](#how-to-install-and-run)
    - [Linux](#linux)
    - [Windows](#windows)
3. [How does XOR algorithm work?](#how-does-xor-algorithm-work)
    - [Example encrypt](#example-encrypt)
    - [Example decrypt](#example-decrypt)


## How does the program work?

You need to have the **input.txt** file in the project folder.

In the program, select **Encrypt** or **Decrypt** and the program will encrypt or decrypt the contents of **input.txt** and create the corresponding file in which the result will be.

## How to install and run?
### Linux

1. **Open a terminal and navigate to the folder where your project is located using the `cd` command:** 

    ```bash
    cd XOR-cipher
    ```

2. **Use the GCC compiler to compile the program. Run the following command:** 

    ```bash
    gcc -o main main.c
    ```

3. **After compiling, run the following command to run the program:** 

    ```bash
    ./main
    ```

### Windows
1. Install linux. ^._.^
2. [Run program.](#linux)
3. ...

## How does XOR algorithm work?

XOR algorithm is a symmetric key cipher where each bit in the plaintext is XORed with the corresponding bit in the key.

- **Encryption formula (E)**: `E_i = M_i XOR K_i`
- **Decryption formula (D)**: `D_i = C_i XOR K_i`

Where:
- `E_i` represents the encrypted bit,
- `D_i` represents the decrypted bit,
- `M_i` represents the i-th bit of the original message,
- `C_i` represents the i-th bit of the encrypted message,
- `K_i` represents the i-th bit of the key.

### Example encrypt:

Let's take an example with a key "KEY":

<span style="color:red">( ! ! ! Don't pay attention to the encrypted text, we are interested in the bits ! ! ! )</span>


- Plaintext: "GHOST"
- Key: "KEY"
- Encrypted text: "S" 

    ```
    G -> 01000111
    H -> 01001000
    O -> 01001111
    S -> 01010011
    T -> 01010100
    
    K -> 01001011
    E -> 01000101
    Y -> 01011001
    ```

    If you want to get the bits of a character, use :

    ```C    
    #include <stdio.h>

    void printBits(char c) {
        for (int i = 7; i >= 0; --i) {
            putchar((c & (1 << i)) ? '1' : '0');
        }
    }


    int main() {
        char c = 'A'; // character
        printf("Binary representation of %c: ", c);
        printBits(c);
        return 0;
    }

    ```
        
    ```
    G -> ?      (01000111 XOR 01001011) = 00001100
    H -> ?      (01001000 XOR 01000101) = 00001101
    O -> ?      (01001111 XOR 01011001) = 00010110
    S -> ?      (01010011 XOR 01001011) = 00011000
    T -> ?      (01010100 XOR 01000101) = 00010001
    ```
    
### Example decrypt:
To decrypt the text, simply XOR the encrypted text with the key again:

- Ciphertext: "S"
- Key: "KEY"
- Decrypted text: "GHOST"

    ```
    G -> 01000111
    H -> 01001000
    O -> 01001111
    S -> 01010011
    T -> 01010100
    
    K -> 01001011
    E -> 01000101
    Y -> 01011001
    ```
    ```
    ? -> G      (00001100 XOR 01001011) = 01000111 -> G
    ? -> H      (00001101 XOR 01000101) = 01001000 -> H
    ? -> O      (00010110 XOR 01011001) = 01001111 -> O
    ? -> S      (00011000 XOR 01001011) = 01010011 -> S
    ? -> T      (00010001 XOR 01000101) = 01010100 -> T
    ```
