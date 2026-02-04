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
for (i = 0; i < nb; ++i) {
    if (i % 2 == 0) {
        W[2 * i] = ((E)0.);
    } else {
        W[2 * i] = ((E)0.);
        W[2 * i + 1] = ((E)0.);
    }
    if (i % 2 == 0) {
        W[2 * i + 1] = ((E)0.);
    }
}
}
