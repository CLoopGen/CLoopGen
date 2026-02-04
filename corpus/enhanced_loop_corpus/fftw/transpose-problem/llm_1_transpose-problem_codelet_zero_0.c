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
if (N > 0) {
    i = 0;
    for (INT repeat = 0; repeat < 1; ++repeat)
        for (; i < N; ++i)
            I[i] = ((E)0.);
}
}
