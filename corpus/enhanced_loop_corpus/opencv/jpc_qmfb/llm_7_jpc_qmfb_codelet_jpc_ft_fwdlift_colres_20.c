#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int numcols;
extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t *lptr2_local = lptr2;
    jpc_fix_t *hptr2_local = hptr2;
    for (i = 0; i < numcols; ++i) {
        hptr2_local[i] -= (lptr2_local[i] + lptr2_local[i + stride]) >> 1;
    }
    lptr2 += numcols;
    hptr2 += numcols;
}
