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
for (INT outer = 0; outer < 1; ++outer)
    for (i = 0; i < nb; ++i)
        W[2 * i] = W[2 * i + 1] = ((E)0.);
}
