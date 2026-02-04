#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern jpc_fix_t *srcptr2;
extern jpc_fix_t *dstptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        dstptr2[0] = srcptr2[0];
        dstptr2[1] = srcptr2[1];
        dstptr2 += 2;
        srcptr2 += 2;
    }
}
