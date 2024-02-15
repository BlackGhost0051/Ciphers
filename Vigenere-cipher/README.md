## Vigenere Cipher

The Vigenere cipher is a method of encrypting alphabetic text by using a simple form of polyalphabetic substitution. It is named after Blaise de Vigenere, a French diplomat, who described it in 1586.

### How it Works

1. **Key Expansion**: The key is repeated to match the length of the plaintext.

2. **Encryption**: Each letter of the plaintext is shifted cyclically according to the corresponding letter in the key. For example, if the plaintext letter is 'A' and the key letter is 'B', the resulting ciphertext letter will be 'B'.

3. **Decryption**: Decryption is achieved by shifting each letter of the ciphertext in the opposite direction.

### Code Overview

The provided C code demonstrates how to perform encryption and decryption using the Vigenere cipher. It includes functions for encryption (`encrypt`) and decryption (`decrypt`), as well as a menu-driven interface (`main`) for user interaction.

#### Usage
To use the code:
1. Compile the code using a C compiler.
2. Run the compiled program.
3. Choose between encryption, decryption, or exit, and provide the required inputs when prompted.
