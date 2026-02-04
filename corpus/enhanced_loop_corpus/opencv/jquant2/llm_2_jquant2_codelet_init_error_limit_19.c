#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with positive and negative indexing, stride of 2
    for (; in <= 255; in += 2) {
        table[in] = out;
        table[-in] = -out;
    }
}
