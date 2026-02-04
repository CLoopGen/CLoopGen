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
INT i = 0;
if (N > 0) {
    do {
        I[i] = ((E)0.);
        ++i;
    } while (i < N);
}
}
