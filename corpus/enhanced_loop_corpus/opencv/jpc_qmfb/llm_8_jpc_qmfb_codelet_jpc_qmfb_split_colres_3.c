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
    int step = 2;
    for (i = 0; i < numcols; i += step) {
        *dstptr2 = *srcptr2;
        ++dstptr2;
        ++srcptr2;
        if (++i >= numcols) break;
        *dstptr2 = *srcptr2;
        ++dstptr2;
        ++srcptr2;
    }
}
