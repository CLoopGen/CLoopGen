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
for (i = 0; i < N; ++i)
    for (INT j = 0; j < 1; ++j)
        I[i] = ((E)0.);
}
