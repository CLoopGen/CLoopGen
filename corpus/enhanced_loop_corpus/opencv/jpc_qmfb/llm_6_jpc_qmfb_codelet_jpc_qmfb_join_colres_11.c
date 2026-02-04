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
    jpc_fix_t *src = srcptr2;
    jpc_fix_t *dst = dstptr2;
    int n = numcols;
    for (i = 0; i < n; ++i) {
        dst[i] = src[i];
    }
    srcptr2 += n;
    dstptr2 += n;
}
