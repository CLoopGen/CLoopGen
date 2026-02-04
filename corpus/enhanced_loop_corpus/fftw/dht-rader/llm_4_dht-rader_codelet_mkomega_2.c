#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT npad;
extern R *omega;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < npad; ++i) {
    if (i >= 0)
        omega[i] = ((E)0.);
}
}
