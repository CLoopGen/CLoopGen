#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned int *key;
extern unsigned int *plaintext;
extern  unsigned char *p;
extern unsigned int i;
extern unsigned int j;
extern unsigned int value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive array-like access using offset indexing without post-increment side effects
    unsigned char *local_p = p;  // Use local pointer to avoid modifying global p inconsistently
    for (i = 0; i < 4; i++) {
        value = 0;
        for (j = 0; j < 4; j++) {
            value |= ((unsigned int)local_p[i * 4 + j] << (8 * j));  // Consecutive block access
        }
        plaintext[i] = key[i] ^ value;
    }
    p = local_p + 16;  // Update global p to reflect consumption of 16 bytes (4×4)
}
