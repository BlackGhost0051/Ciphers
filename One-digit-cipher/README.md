#  One digit cipher

With this program, you can encrypt and decrypt text using the one digit cipher.

## Content 
1. [How does the program work?](#how-does-the-program-work)
2. [How to install and run?](#how-to-install-and-run)
    - [Linux](#linux)
    - [Windows](#windows)
3. [How does the one digit cipher work?](#how-does-the-one-digit-cipher-work)
    - [Example encrypt](#example-encrypt)
    - [Example decrypt](#example-decrypt)

## How does the program work?

You need to have the input.txt file in the project folder.

In the program, select Encrypt or Decrypt and the program will encrypt or decrypt the contents of input.txt and create the corresponding file (encrypted.txt or decrypted.txt) with the result.

## How to install and run?

### Linux

1. **Open a terminal and navigate to the folder where your project is located using the cd command:**

    ```bash
    cd one-digit-cipher
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

## How does the one digit cipher work?

The one digit cipher encrypts each letter of the alphabet by repeating a target symbol a number of times corresponding to the letter's position in the alphabet (A=1, B=2, ..., Z=26).

### Example encrypt:
Let's take an example with the target symbol "*":

- Plaintext: "ABC"
- Target symbol: "*"
- Encrypted text:

```
*
**
***
```
Each letter in the plaintext is replaced with a series of target symbols matching its position in the alphabet.

### Example decrypt:
To decrypt the text, the program counts the number of target symbols in each line and converts this number back to the corresponding letter of the alphabet.

- Ciphertext:
```
*
**
***
```
- Decrypted text: "ABC"

Each series of target symbols is replaced by the letter that corresponds to the number of symbols in the series.