#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT i;
extern INT nb;
extern R *W;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and writing two elements in sequence
    INT idx;
    for (i = 0; i < nb; ++i) {
        idx = 2 * i;
        W[idx]     = ((E)0.);
        W[idx + 1] = ((E)0.);
    }
}
