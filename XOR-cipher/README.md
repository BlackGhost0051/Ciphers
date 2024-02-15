## XOR Cipher

The XOR cipher is a simple symmetric encryption algorithm that operates on binary data. It stands for "exclusive or", where two bits are compared, and the result is 1 if the bits are different and 0 if they are the same.

### How it Works

1. **Encryption**: In XOR encryption, each character of the plaintext is bitwise XORed with a corresponding character from the key. This process generates the ciphertext.

2. **Decryption**: Decryption is achieved by applying the same key and XOR operation to the ciphertext, which retrieves the original plaintext.

### Code Overview

The provided C code demonstrates how to perform encryption and decryption using the XOR cipher. It consists of three main functions:
- `encrypt`: Encrypts the content of a file using a given key.
- `decrypt`: Decrypts the content of an encrypted file using the same key.
- `main`: Implements a simple menu-driven interface allowing the user to encrypt, decrypt, or exit the program.

#### Usage
To use the code:
1. Compile the code using a C compiler.
2. Run the compiled program.
3. Choose between encryption, decryption, or exit, and provide the required inputs when prompted.
