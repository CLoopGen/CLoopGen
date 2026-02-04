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
for (; i < vl + 8; ++i) {
    for (j = 0; j < 4; ++j) {
        *ci += ((E)1.5) * ((E)2.5);
    }
    ci += ovs;
}
}
