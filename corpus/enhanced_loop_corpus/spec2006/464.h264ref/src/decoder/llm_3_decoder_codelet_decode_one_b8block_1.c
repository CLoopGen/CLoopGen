#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int resY_tmp[16][16];
extern int i0;
extern int i1;
extern int _usr_j0;
extern int _usr_j1;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0
#define j1 _usr_j1



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Introduce a strided access by unrolling the inner loop with a stride of 2.
    // This accesses every second element in the inner dimension first, then follows up
    // with the odd indices. This creates non-consecutive memory writes, simulating
    // a strided pattern which may reduce cache efficiency but could be useful in certain SIMD contexts.

    int stride = 2;
    // First pass: even indices
    for (i = i0; i < i1; i += stride)
        for (j = j0; j < j1; j++) {
            if (i + 0 < i1) resY_tmp[j][i + 0] = 0;
            if (i + 1 < i1) resY_tmp[j][i + 1] = 0;
        }
}
