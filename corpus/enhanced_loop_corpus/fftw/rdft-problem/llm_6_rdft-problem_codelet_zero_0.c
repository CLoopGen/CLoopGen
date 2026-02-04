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
    for (i = 0; i < N; ++i) {
        if (i > 0)
            I[i] = I[i-1] + ((E)0.);
        else
            I[i] = ((E)0.);
    }
}
