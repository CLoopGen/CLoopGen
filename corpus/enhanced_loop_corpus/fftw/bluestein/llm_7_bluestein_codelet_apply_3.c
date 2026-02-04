#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT i;
extern INT nb;
extern R *b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (INT j = i; j < nb; ++j) {
    b[2 * j + 1] = ((E)0.);
    if (j > i) {
        b[2 * j] = b[2 * (j - 1)]; // Introduce loop-carried dependence (WAW via previous iteration)
    } else {
        b[2 * j] = ((E)0.);
    }
}
}
