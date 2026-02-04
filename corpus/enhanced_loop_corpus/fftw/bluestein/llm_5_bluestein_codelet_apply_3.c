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
    b[2 * j] = ((E)0.);
    if (j + 1 < nb) {
        b[2 * j + 1] = ((E)0.);
    }
}
}
