#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *ri;
extern R *ii;
extern INT i;
extern INT n;
extern INT is;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computation and using local stride accumulation
    INT idx = 0;
    for (i = 0; i < n; ++i) {
        ri[idx] = ii[idx] = ((E)0.);
        idx += is;
    }
}
