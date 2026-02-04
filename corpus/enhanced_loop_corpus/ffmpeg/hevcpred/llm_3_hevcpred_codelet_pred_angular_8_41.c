#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int size;
extern int x;
extern int y;
extern uint8_t *src;
extern int angle;
extern  uint8_t *ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Access with Transposed Reference Indexing
    // Modify memory access pattern by transposing the indexing into 'ref'
    // to simulate a column-major-like access, increasing stride in reference array.
    // This increases cache line utilization across different rows depending on y.

    for (x = 0; x < size; x++) {
        int idx = ((x + 1) * angle) >> 5;
        int fact = ((x + 1) * angle) & 31;

        if (fact) {
            for (y = 0; y < size; y++) {
                // Access ref with fixed base per y, varying over x indirectly via idx
                // Now ref is accessed with large strides based on y-first indexing
                src[x + stride * y] = ((32 - fact) * ref[idx + 1 + y * size] + 
                                       fact * ref[idx + 2 + y * size] + 16) >> 5;
            }
        } else {
            for (y = 0; y < size; y++) {
                src[x + stride * y] = ref[idx + 1 + y * size];
            }
        }
    }
}
