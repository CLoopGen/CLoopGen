#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT i;
extern INT nb;
extern R *W;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT j;
for (j = 0; j < nb; ++j) {
    INT idx = 2 * j;
    W[idx] = ((E)0.);
    W[idx + 1] = W[idx];
}
}
