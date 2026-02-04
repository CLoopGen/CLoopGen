#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int unroll_factor = 4;
    int limit = (numcols / unroll_factor) * unroll_factor;
    for (i = 0; i < limit; i += unroll_factor) {
        hptr2[0] = hptr2[0] + ((-((jpc_fix_t)((((jpc_fix_big_t)((-1027) * ((jpc_fix_big_t)(lptr2[0] + lptr2[stride])))) >> 13)))));
        hptr2[1] = hptr2[1] + ((-((jpc_fix_t)((((jpc_fix_big_t)((-1027) * ((jpc_fix_big_t)(lptr2[1] + lptr2[stride])))) >> 13)))));
        hptr2[2] = hptr2[2] + ((-((jpc_fix_t)((((jpc_fix_big_t)((-1027) * ((jpc_fix_big_t)(lptr2[2] + lptr2[stride])))) >> 13)))));
        hptr2[3] = hptr2[3] + ((-((jpc_fix_t)((((jpc_fix_big_t)((-1027) * ((jpc_fix_big_t)(lptr2[3] + lptr2[stride])))) >> 13)))));
        lptr2 += 4;
        hptr2 += 4;
    }
    for (; i < numcols; ++i) {
        hptr2[0] = hptr2[0] + ((-((jpc_fix_t)((((jpc_fix_big_t)((-1027) * ((jpc_fix_big_t)(lptr2[0] + lptr2[stride])))) >> 13)))));
        ++lptr2;
        ++hptr2;
    }
}
