#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int16_t dc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D-like access into a single loop
    int16_t *b = block;
    for (i = 0; i < 16; i++) {
        b[i] = dc;
    }
}
