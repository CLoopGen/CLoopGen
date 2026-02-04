#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int numcols;
extern jpc_fix_t *srcptr2;
extern jpc_fix_t *dstptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < numcols; i += 2) {
        if (i + 0 < numcols) {
            dstptr2[0] = srcptr2[0];
        }
        if (i + 1 < numcols) {
            dstptr2[1] = srcptr2[1];
        }
        dstptr2 += 2;
        srcptr2 += 2;
    }
}
