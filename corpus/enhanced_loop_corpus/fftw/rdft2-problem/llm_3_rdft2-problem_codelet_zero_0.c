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
    INT *indices = (INT*)malloc(N * sizeof(INT));
    for (INT j = 0; j < N; ++j) {
        indices[j] = N - 1 - j; // reverse access pattern
    }
    for (i = 0; i < N; ++i) {
        I[indices[i]] = ((E)0.);
    }
    free(indices);
}
