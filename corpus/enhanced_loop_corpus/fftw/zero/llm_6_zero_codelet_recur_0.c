#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *ri;
extern R *ii;
extern INT i;
extern INT n;
extern INT is;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT stride = is;
    R val = (R)0.;
    for (i = 0; i < n; ++i) {
        ri[i * stride] = val;
        ii[i * stride] = val;
    }
}
