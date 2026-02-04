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
    int temp_naxes = 0;
    for (idim = 0; idim < ndim; ++idim) {
        temp_naxes += axis_flags[idim] ? 1 : 0;
    }
    naxes += temp_naxes;
}
