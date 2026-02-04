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
    // Variant 2: Indirect Access via Pointer Arithmetic
    // Use pointer arithmetic instead of array indexing to simulate indirect memory access.
    // This variant dereferences through incremented pointers rather than using [i].
    unsigned int *ct_ptr = ciphertext;
    unsigned int *k_ptr = key;
    for (i = 0; i < 4; i++) {
        value = (*ct_ptr++) ^ (*k_ptr++);
        for (j = 0; j < 4; j++)
            *p++ = (unsigned char)((value >> (8 * j)) & 255);
    }
}
