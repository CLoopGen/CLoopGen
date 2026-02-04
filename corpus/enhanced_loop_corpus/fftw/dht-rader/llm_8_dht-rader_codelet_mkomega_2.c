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
INT j;
for (; i < npad; ++i) {
    omega[i] = ((E)0.);
    for (j = 1; j < 5; ++j) {
        omega[i] += ((E)j) * ((E)0.2);
    }
}
}
