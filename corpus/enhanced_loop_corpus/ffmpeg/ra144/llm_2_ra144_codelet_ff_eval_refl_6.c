#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *coefs;
extern int i;
extern int buffer2[10];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element, then handle remainder)
    int j;
    for (j = 0; j < 10; j += 2) {
        if (j < 10) buffer2[j] = coefs[j];
        if (j + 1 < 10) buffer2[j + 1] = coefs[j + 1];
    }
}
