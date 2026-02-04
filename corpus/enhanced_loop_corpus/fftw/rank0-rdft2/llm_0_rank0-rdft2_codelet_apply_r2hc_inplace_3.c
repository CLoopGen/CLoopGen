#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *ci;
extern INT i;
extern INT vl;
extern INT ovs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT j;
for (j = 0; j < vl + 4 - i; ++j) {
    for (; i < vl + 4 && j == 0; ++i) {
        *ci = ((E)0.);
        ci += ovs;
    }
}
}
