#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern double **pointers_to_data;
extern double ***pointers_to_pointers;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of assigning each pointers_to_pointers[i] a block with step y,
    // we now access pointers_to_data in a strided manner across iterations,
    // where each i accesses a location with increasing offset, but stride remains y.
    // The base computation is preserved but expressed with stride applied differently.

    int stride = y;
    for (i = 0; i < x; i++) {
        pointers_to_pointers[i] = &pointers_to_data[i * stride];
    }
}
