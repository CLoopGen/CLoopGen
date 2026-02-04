#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int width;
extern int height;
extern uint64_t *counts;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing row by row, access elements with a stride equal to height,
    // simulating a transposed traversal (column-major like), assuming `src` is originally row-major.
    // We reinterpret the 2D image as being accessed column-wise by adjusting indexing.
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            counts[src[i + j * width]]++;
        }
    }
}
