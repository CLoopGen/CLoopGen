#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned int *ciphertext;
extern  unsigned int *key;
extern unsigned int *plaintext;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    plaintext[0] = key[0] ^ ciphertext[0];
    for (i = 1; i < 4; i++) {
        plaintext[i] = key[i] ^ ciphertext[i] ^ plaintext[i-1];
    }
}
