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
INT offset = 0;
for (i = 0; i < nb; ++i) {
    W[offset] = ((E)0.);
    offset += 2;
    W[offset - 1] = ((E)0.);
}
}
