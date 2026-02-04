#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *I;
extern INT i;
extern INT N;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT stride = 2;
    for (i = 0; i < N; i += stride)
        I[i] = ((E)0.);
    for (i = 1; i < N; i += stride)
        I[i] = ((E)0.);
}
