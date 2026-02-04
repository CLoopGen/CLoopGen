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
        plaintext[i] = 0;
        if (i % 2 == 0) {
            plaintext[i] = key[i] ^ ciphertext[i];
        } else {
            plaintext[i] = ciphertext[i] ^ key[i]; // Same operation, different order for clarity of control path
        }
    }
}
