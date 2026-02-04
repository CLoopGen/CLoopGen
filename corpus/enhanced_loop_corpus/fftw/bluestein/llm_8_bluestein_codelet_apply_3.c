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
    INT idx = 2 * i;
    b[idx] = ((E)0.);
    b[idx + 1] = ((E)0.);
}
}
