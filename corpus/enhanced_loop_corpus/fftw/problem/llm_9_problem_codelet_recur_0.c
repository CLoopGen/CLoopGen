#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *I;
extern INT i;
extern INT n;
extern INT is;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT stride = is * is;
    for (i = 0; i < n; ++i) {
        I[i * stride] = ((E)0.) + ((E)0.) + ((E)0.);
    }
}
