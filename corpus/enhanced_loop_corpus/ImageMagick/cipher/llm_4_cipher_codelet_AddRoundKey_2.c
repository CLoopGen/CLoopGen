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
    for (i = 0; i < 4; i++) {
        if (!(key[i] == 0 && ciphertext[i] == 0)) {
            plaintext[i] = key[i] ^ ciphertext[i];
        } else {
            plaintext[i] = 0;
        }
    }
}
