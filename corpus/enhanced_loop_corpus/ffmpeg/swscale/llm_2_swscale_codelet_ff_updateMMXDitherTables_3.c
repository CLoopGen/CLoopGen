#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t **alpSrcPtr;
extern int neg;
extern int i;
extern  int16_t **tmpA;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset indexing
    // Instead of assigning the same source pointer to multiple destinations,
    // we now perform a strided read and consecutive write pattern.
    // Assume alpSrcPtr contains at least neg * 2 valid entries to avoid out-of-bounds.
    for (i = 0; i < neg; i++) {
        tmpA[i] = alpSrcPtr[i * 2];  // Strided access on alpSrcPtr with stride 2
    }
}
