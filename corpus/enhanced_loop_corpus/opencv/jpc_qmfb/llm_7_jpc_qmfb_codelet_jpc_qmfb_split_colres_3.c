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
    jpc_fix_t *s = srcptr2;
    jpc_fix_t *d = dstptr2;
    for (i = 0; i < numcols; ++i) {
        d[i] = s[i];
    }
    srcptr2 += numcols;
    dstptr2 += numcols;
}
