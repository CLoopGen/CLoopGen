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
INT outer_i;
for (outer_i = 0; outer_i < 1; ++outer_i)
    for (i = 0; i < npad; ++i)
        omega[i] = ((E)0.);
}
