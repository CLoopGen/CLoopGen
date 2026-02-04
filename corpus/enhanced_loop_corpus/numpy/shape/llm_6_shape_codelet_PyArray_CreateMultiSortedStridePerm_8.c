#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ndim;
extern int *out_strideperm;
extern int i0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[ndim];
    for (i0 = 0; i0 < ndim; ++i0) {
        temp[i0] = i0;
    }
    for (i0 = 0; i0 < ndim; ++i0) {
        out_strideperm[i0] = temp[i0];
    }
}
