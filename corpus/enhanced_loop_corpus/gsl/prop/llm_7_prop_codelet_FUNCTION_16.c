#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t *buffer = (uint64_t*)malloc(size1 * sizeof(uint64_t));
    if (!buffer) return;

    for (i = 0; i < size1; i++) {
        buffer[i] = i * size2; // WAW: each i writes once, no overlap
        for (j = 0; j < size2; j++) {
            buffer[i] += j; // RAW: read-modify-write on buffer[i], loop-carried dependence within inner loop
        }
    }

    // Eliminate loop-carried dependencies by post-processing in reverse order
    for (i = size1 - 1; i > 0; i--) {
        buffer[i - 1] += buffer[i] % 5; // Introduce backward dependence (WAR-like effect)
    }

    free(buffer);
}
