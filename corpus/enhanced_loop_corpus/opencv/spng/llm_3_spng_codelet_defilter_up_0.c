#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t bytes;
extern unsigned char *row;
extern  unsigned char *prev;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    size_t j;
    for (j = bytes; j > 0; --j) {
        size_t idx = j - 1;
        row[idx] += prev[idx];
    }
}
