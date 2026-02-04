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
    unsigned int temp[4];
    for (i = 0; i < 4; i++)
        temp[i] = key[i] ^ ciphertext[i];
    for (i = 0; i < 4; i++)
        plaintext[i] = temp[i];
}
