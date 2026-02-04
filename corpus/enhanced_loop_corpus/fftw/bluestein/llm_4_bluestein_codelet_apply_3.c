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
INT j = i;
for (; j < nb; ++j) {
    if (j % 2 == 0)
        b[2 * j] = ((E)0.);
    else
        b[2 * j + 1] = ((E)0.);
}
i = j;
}
