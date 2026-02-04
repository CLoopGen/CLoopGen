#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int lag;
extern int i;
extern int16_t *vector_ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive backward traversal with reversed indexing
    // Access vector_ptr consecutively from the end, avoiding negative offsets by reversing index
    for (i = 0; i < lag; i++)
        out[i] = vector_ptr[lag - 1 - i] * 3 >> 2;
}
