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
    // Variant 2: Strided access with reversed traversal order (backward striding)
    for (i = n - 1; i >= 0; --i)
        ri[i * is] = ii[i * is] = ((E)0.);
}
