# Vigenere cipher

With this program, you can encrypt and decrypt text using the Vigenere cipher.

## Content 
1. [How does the program work?](#how-does-the-program-work)
2. [How to install and run?](#how-to-install-and-run)
    - [Linux](#linux)
    - [Windows](#windows)
3. [How does Vigenere's algorithm work?](#how-does-vigeneres-algorithm-work)
    - [Example encrypt](#example-encrypt)
    - [Example decrypt](#example-decrypt)

## How does the program work?

You need to have the **input.txt** file in the project folder.

In the program, select **Encrypt** or **Decrypt** and the program will encrypt or decrypt the contents of **input.txt** and create the corresponding file in which the result will be.

## How to install and run?
### Linux

1. **Open a terminal and navigate to the folder where your project is located using the `cd` command:** 

    ```bash
    cd Vigenere-cipher
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

## How does Vigenere's algorithm work?

Vigenere's algorithm, unlike Caesar's cipher, uses a keyword to shift letters in the plaintext by different amounts. Each letter in the keyword corresponds to a shift value.

- **Encryption formula (E)**: `E_i = (m_i + k_i) \mod 26`
- **Decryption formula (D)**: `D_i = (c_i - k_i) \mod 26`

Where:
- `E_i` represents the encrypted letter,
- `D_i` represents the decrypted letter,
- `m_i` represents the position of the original letter in the alphabet (0 for A, 1 for B, ..., 25 for Z),
- `c_i` represents the position of the encrypted letter in the alphabet,
- `k_i` represents the position of the corresponding letter in the keyword.

### Example encrypt:

Let's take an example with a keyword "KEY":

- Plaintext: "GHOST"
- Keyword: "KEY"
- Encrypted text: "QLMCX"

    ```
    ABCDEFGHIJKLMNOPQRSTUVWXYZ

    ABCDEFGHI...
    ^^^^^^^^^
    |||||||||
    012345678...


    G  H  O  S  T   <- text
    ^  ^  ^  ^  ^
    |  |  |  |  |
    6  7  14 18 19
    
    K  E  Y         <- key
    ^  ^  ^
    |  |  |
    10 4  24
    ```
    ```
    G -> Q      (6 + 10) mod 26 = 16
    H -> L      (7 + 4) mod 26 = 11
    O -> M      (14 + 24) mod 26 = 12
    S -> C      (18 + 10) mod 26 = 2
    T -> X      (19 + 4) mod 26 = 23
    ```
### Example decrypt:
To decrypt the text, reverse the process:

- Ciphertext: "QLMCX"
- Keyword: "KEY"
- Decrypted text: "GHOST"

    ```
    ABCDEFGHIJKLMNOPQRSTUVWXYZ

    ABCDEFGHI...
    ^^^^^^^^^
    |||||||||
    012345678...
    ```
    ```
    Q -> G      (16 - 10) mod 26 = 6
    L -> H      (11 - 4) mod 26 = 7
    M -> O      (12 - 24) mod 26 = 14
    C -> S      (2 - 10) mod 26 = 18
    X -> T      (23 - 4) mod 26 = 19
    ```