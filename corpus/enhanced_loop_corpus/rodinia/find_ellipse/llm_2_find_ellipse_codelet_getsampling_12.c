#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *cindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then handle remainder)
    int stride = 2;
    int start;
    for (start = 0; start < stride; start++) {
        for (i = start; i < N - 1; i += stride) {
            cindex[i] = i + 1;
        }
    }
}
