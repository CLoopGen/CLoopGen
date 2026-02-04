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
for (i = 0; i < N; i += stride) {
    if (i + 1 < N) {
        I[i] = ((E)0.);
        I[i+1] = ((E)0.);
    } else {
        I[i] = ((E)0.);
    }
}
}
