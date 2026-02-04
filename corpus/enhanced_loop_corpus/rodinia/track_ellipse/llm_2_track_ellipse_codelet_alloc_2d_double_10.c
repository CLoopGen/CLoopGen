#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern double *data;
extern double **pointers;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reversing the order of assignment
    // This accesses 'data' in a forward, consecutive pattern by adjusting index calculation
    int n = x * y;
    for (i = 0; i < x; i++) {
        pointers[i] = data + (n - (i + 1) * y);
    }
}
