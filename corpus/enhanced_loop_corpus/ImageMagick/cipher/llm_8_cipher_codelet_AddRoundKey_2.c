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
    for (i = 0; i < 8; i += 2) {
        plaintext[i] = key[i] ^ ciphertext[i];
        if (i + 1 < 4) {
            plaintext[i + 1] = key[i + 1] ^ ciphertext[i + 1];
        }
    }
}
