#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t **chrUSrcPtr;
extern  int16_t **tmpU;
extern int neg;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of assigning the same source row (chrUSrcPtr[neg]) to consecutive tmpU rows,
    // we stride through both source and destination with a fixed step (e.g., every 2nd row)
    int stride = 2;
    for (i = 0; i < neg; i += stride) {
        if (i < neg) {
            tmpU[i] = chrUSrcPtr[(neg - i) % neg];  // Indirect-like indexing with wrap-around
        }
    }
}
