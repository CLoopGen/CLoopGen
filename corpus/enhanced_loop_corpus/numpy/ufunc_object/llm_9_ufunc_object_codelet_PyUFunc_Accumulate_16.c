#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int op_axes_arrays[2][64];
extern int idim;
extern int ndim;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (idim = 0; idim < ndim * 2; idim += 2) {
        int temp1 = idim / 2;
        int temp2 = temp1 + 1;
        op_axes_arrays[0][temp1] = (temp1 % 2 == 0) ? temp1 : temp2;
        if (temp1 < 64) {
            op_axes_arrays[1][temp1] = temp1 * temp1;
        }
    }
}
