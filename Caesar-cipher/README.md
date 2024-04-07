# Caesar cipher

With this program, you can encrypt and decrypt text using the Caesar cipher.

## Content 
1. [How does the program work?](#how-does-the-program-work)
2. [How to install and run?](#how-to-install-and-run)
    - [Linux](#linux)
    - [Windows](#windows)
3. [How does Caesar's algorithm work?](#how-does-caesars-algorithm-work)
    - [Example encrypt](#example-encrypt)
    - [Example decrypt](#example-decrypt)


## How does the program work?


You need to have the **input.txt** file in the project folder.

In the program, select **Encrypt** or **Decrypt** and the program will encrypt or decrypt the contents of **input.txt** and create the corresponding file in which the result will be.

## How to install and run?
### Linux

1. **Open a terminal and navigate to the folder where your project is located using the `cd` command:** 

    ```bash
    cd Caesar-cipher
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

## How does Caesar's algorithm work?

Caesar's algorithm, also known as Caesar's cipher, is a simple substitution cipher technique where each letter in the plaintext is shifted a certain number of places left or right the alphabet.

- **Encryption formula (E)**: `E_m = (m + k) \mod 26`
- **Decryption formula (D)**: `D_c = (c - k) \mod 26`

Where:
- `E_m` represents the encrypted letter,
- `D_c` represents the decrypted letter,
- `m` represents the position of the original letter in the alphabet (0 for A, 1 for B, ..., 25 for Z),
- `c` represents the position of the encrypted letter in the alphabet,
- `k` represents the shift value (the number of positions to shift the letters).


### Example encrypt:

Let's take an example with a shift of 3:

- Plaintext: "GHOST"
- Shift: 3
- Encrypted text: "JKRUV"

    ```
    ABCDEFGHIJKLMNOPQRSTUVWXYZ

    ABCDEFGHI...
    ^^^^^^^^^
    |||||||||
    123456789...
    ```
    ```
    G -> J      7 + 3 = 10
    H -> K      8 + 3 = 11
    O -> R      15 + 3 = 18
    S -> U      19 + 3 = 22
    T -> V      20 + 3 = 23 
    ```
### Example decrypt:
To decrypt the text, reverse the process:

- Ciphertext: "EOHFN"
- Shift: 3
- Decrypted text: "BLACK"

    ```
    ABCDEFGHIJKLMNOPQRSTUVWXYZ

    ABCDEFGHI...
    ^^^^^^^^^
    |||||||||
    123456789...
    ```
    ```
    E -> B      5 - 3 = 2
    O -> L      15 - 3 = 12
    H -> A      8 - 3 = 5
    F -> C      6 - 3 = 3
    N -> K      14 - 3 = 11        
    ```