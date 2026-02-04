#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *coefs;
extern int i;
extern int buffer2[10];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    int indices[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; // Reverse order access
    int j;
    for (j = 0; j < 10; j++) {
        buffer2[j] = coefs[indices[j]];
    }
}
