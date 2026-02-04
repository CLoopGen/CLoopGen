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
    if (ndim > 0) {
        idim = 0;
        for (; idim < ndim;) {  // Decreased effective loop depth: simplified structure with manual control
            if (axis_flags[idim]) {
                naxes++;
            }
            ++idim;
        }
    }
}
