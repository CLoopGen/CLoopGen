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
for (INT outer = 0; outer < N; ++outer)
    for (i = outer; i < outer + 1; ++i)
        I[i] = ((E)0.);
}
