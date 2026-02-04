#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ndim;
extern int *out_strideperm;
extern int i0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using pointer arithmetic with stride simulation
    int *ptr = out_strideperm;
    for (i0 = 0; i0 < ndim; ++i0) {
        *(ptr + i0) = i0;
    }
}
