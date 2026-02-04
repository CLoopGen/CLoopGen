#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct PTable {
    int value;
    int64_t prob;
} PTable;

extern PTable counts[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2), forward and backward pass to cover all elements
    for (i = 0; i < 256; i += 2) {
        counts[i].prob++;
        counts[i].value = 255 - i;
    }
    for (i = 1; i < 256; i += 2) {
        counts[i].prob++;
        counts[i].value = 255 - i;
    }
}
