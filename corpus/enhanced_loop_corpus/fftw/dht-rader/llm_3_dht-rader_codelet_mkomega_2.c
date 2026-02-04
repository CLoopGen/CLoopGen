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
INT *indices = (INT*)malloc(npad * sizeof(INT));
for (INT j = 0; j < npad; ++j)
    indices[j] = j;
for (INT j = 0; j < npad; ++j)
    omega[indices[j]] = ((E)0.);
free(indices);
}
