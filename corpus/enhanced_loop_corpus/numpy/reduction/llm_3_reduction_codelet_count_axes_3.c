#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char npy_bool;

extern int ndim;
extern  npy_bool *axis_flags;
extern int idim;
extern int naxes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)alloca(ndim * sizeof(int));
    for (int i = 0; i < ndim; ++i) {
        indices[i] = i;
    }
    for (int i = 0; i < ndim; ++i) {
        int idx = indices[i];
        if (axis_flags[idx]) {
            naxes++;
        }
    }
}
