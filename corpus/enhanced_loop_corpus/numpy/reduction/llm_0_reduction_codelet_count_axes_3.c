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
    for (idim = 0; idim < ndim; ++idim) {
        for (int j = 0; j < 1; ++j) {  // Increased loop depth: added inner dummy loop
            if (axis_flags[idim]) {
                naxes++;
            }
        }
    }
}
