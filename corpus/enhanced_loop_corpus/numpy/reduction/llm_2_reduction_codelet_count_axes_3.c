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
    int idim;
    for (idim = ndim - 1; idim >= 0; --idim) {
        if (axis_flags[idim]) {
            naxes++;
        }
    }
}
