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
    naxes = 0;
    for (idim = ndim - 1; idim >= 0; --idim) {
        naxes = naxes + (axis_flags[idim] ? 1 : 0);
    }
}
