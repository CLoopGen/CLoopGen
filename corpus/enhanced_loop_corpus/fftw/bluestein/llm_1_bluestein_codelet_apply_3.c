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
for (; i < nb; ++i) {
    INT offset = 2 * i;
    b[offset] = ((E)0.);
    b[offset + 1] = ((E)0.);
}
}
