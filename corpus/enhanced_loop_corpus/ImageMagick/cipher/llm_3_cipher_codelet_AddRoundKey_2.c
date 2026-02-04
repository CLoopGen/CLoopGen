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
    // Variant 2: Indirect memory access using an index array to simulate non-sequential access
    ssize_t indices[4] = {0, 2, 1, 3}; // Custom access pattern
    for (i = 0; i < 4; i++) {
        ssize_t idx = indices[i];
        plaintext[idx] = key[idx] ^ ciphertext[idx];
    }
}
