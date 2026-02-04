#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with fixed stride > 1
    // Access every 4th element first, then cover remaining offsets (loop tiling by stride)
    int stride = 4;
    int offset, i;
    for (offset = 0; offset < stride; ++offset) {
        for (i = offset; i < numcols; i += stride) {
            hptr2[i] = hptr2[i] + (-(jpc_fix_t)((((jpc_fix_big_t)(
                (-1.5861343420599241) * 2. * ((double)(((jpc_fix_t)(1)) << 13)))
                * (jpc_fix_big_t)(lptr2[i])
            ) >> 13)));
        }
    }
}
