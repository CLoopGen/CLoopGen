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
    for (i = 0; i < numcols; ++i) {
        jpc_fix_t val = *srcptr2;
        *dstptr2 = (val << 1) - val; // Equivalent to val * 1, but with higher arithmetic intensity
        ++dstptr2;
        ++srcptr2;
    }
}
