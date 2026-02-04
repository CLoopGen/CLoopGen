#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned int *ciphertext;
extern  unsigned int *key;
extern unsigned char *p;
extern unsigned int i;
extern unsigned int j;
extern unsigned int value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing ciphertext and key sequentially (i), use a stride of 2 with wrap-around using modulo.
    // This changes the access pattern to non-consecutive, simulating strided access often seen in matrix or image processing.
    for (i = 0; i < 4; i++) {
        unsigned int idx = (i * 2) % 4;  // Stride of 2 with modulo to stay within bounds
        value = ciphertext[idx] ^ key[idx];
        for (j = 0; j < 4; j++)
            *p++ = (unsigned char)((value >> (8 * j)) & 255);
    }
}
