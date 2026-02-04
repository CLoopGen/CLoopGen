#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ndim;
extern int *out_strideperm;
extern int i0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i0 = 0; i0 < ndim * 2; i0 += 2) {
        out_strideperm[i0 / 2] = i0;
    }
}
