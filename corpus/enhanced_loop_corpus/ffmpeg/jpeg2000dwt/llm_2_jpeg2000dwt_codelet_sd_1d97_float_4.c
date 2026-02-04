#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset indexing
    // Original strided access (every other element) is transformed to consecutive
    // by reindexing the array using a new pointer that skips initial elements.
    float *base = p + 1; // Point to first odd index to enable consecutive access
    int start = (i0 >> 1) - 2;
    int end = (i1 >> 1) + 1;
    for (i = start; i < end; i++) {
        base[2 * i] -= 1.5861339999999999 * (p[2 * i] + p[2 * i + 2]);
    }
}
