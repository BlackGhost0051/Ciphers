# Rail fence cipher

With this program, you can encrypt and decrypt text using the Rail fence cipher.

# Content 
1. [How does the program work?](#how-does-the-program-work)
2. [How to install and run?](#how-to-install-and-run)
    - [Linux](#linux)
    - [Windows](#windows)
3. [How does Vigenere's algorithm work?](#how-does-rail-fence-algorithm-work)
    - [Example encrypt](#example-encrypt)
    - [Example decrypt](#example-decrypt)

## How does the program work?
You need to have the **input.txt** file in the project folder.

In the program, select **Encrypt** or **Decrypt** and the program will encrypt or decrypt the contents of **input.txt** and create the corresponding file in which the result will be.

## How to install and run?
### Linux
1. **Open a terminal and navigate to the folder where your project is located using the `cd` command:** 

    ```bash
    cd Rail-fence-cipher
    ```

2. **Use the GCC compiler to compile the program. Run the following command:** 

    ```bash
    gcc main.c -o main -lm
    ```

3. **After compiling, run the following command to run the program:** 

    ```bash
    ./main
    ```

### Windows
1. Install linux. ^._.^
2. [Run program.](#linux)
3. ...

## How does Rail fence algorithm work?

### Example encrypt:

- Plaintext: "BlackGhost"
- Key: 3

```
B . . . k . . . s .
. l . c . G . o . t
. . a . . . h . . .
```
```
BkslcGotah
```
### Example decrypt: