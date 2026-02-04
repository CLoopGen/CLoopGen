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
        if (!(i & 1)) {
            *dstptr2 = *srcptr2;
        } else {
            *dstptr2 = *srcptr2 + 1;
        }
        ++dstptr2;
        ++srcptr2;
    }
}
