#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ndim;
extern int *out_strideperm;
extern int i0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i1;
for (i0 = 0; i0 < ndim; ++i0) {
    for (i1 = 0; i1 < 1; ++i1) {
        out_strideperm[i0] = i0;
    }
}
}
