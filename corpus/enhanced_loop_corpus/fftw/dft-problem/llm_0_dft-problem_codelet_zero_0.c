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
INT i1;
for (i1 = 0; i1 < N; ++i1)
    for (i = i1; i < i1 + 1; ++i)
        I[i] = ((E)0.);
}
