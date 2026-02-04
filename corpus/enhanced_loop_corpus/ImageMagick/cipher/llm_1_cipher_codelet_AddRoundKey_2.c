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
    for (i = 0; i < 2; i++) {
        plaintext[i] = key[i] ^ ciphertext[i];
        plaintext[i + 2] = key[i + 2] ^ ciphertext[i + 2];
    }
}
