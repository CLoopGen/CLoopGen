#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with temporary array-like traversal
    // Instead of accessing p[2*i] and neighbors with stride 2, reindex to traverse consecutive elements
    int start = ((i0 + 1) >> 1);
    int end = (i1 + 1) >> 1;
    for (i = start; i < end; i++) {
        int idx = 2 * i;
        p[idx] += (p[idx - 1] + p[idx + 1] + 2) >> 2;
    }
}
