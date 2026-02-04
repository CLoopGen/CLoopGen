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
INT step = 2;
for (; i < nb; i += step) {
    if (i + 1 < nb) {
        b[2 * i] = b[2 * i + 1] = ((E)0.);
        b[2 * (i + 1)] = b[2 * (i + 1) + 1] = ((E)0.);
    } else {
        b[2 * i] = b[2 * i + 1] = ((E)0.);
    }
}
}
