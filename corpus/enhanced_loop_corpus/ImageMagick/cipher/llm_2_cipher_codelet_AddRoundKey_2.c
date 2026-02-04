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
    // Variant 1: Strided memory access with stride of 1 but in reverse order (reverse sequential access)
    for (i = 3; i >= 0; i--)
        plaintext[i] = key[i] ^ ciphertext[i];
}
