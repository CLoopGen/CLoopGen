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
    if (numcols <= 0) return;
    jpc_fix_t* lptr_local = lptr2;
    jpc_fix_t* hptr_local = hptr2;
    const jpc_fix_big_t factor = ((jpc_fix_big_t)((jpc_fix_t)(2. * 0.44350685203971 * ((double)(((jpc_fix_t)(1)) << 13)))));
    jpc_fix_t prev_update = 0;
    for (i = 0; i < numcols; ++i) {
        jpc_fix_big_t product = ((jpc_fix_big_t)(hptr_local[0])) * factor;
        jpc_fix_t current_correction = ((jpc_fix_t)(product >> 13));
        lptr_local[0] = (i == 0) ? (lptr_local[0] - current_correction) : (lptr_local[0] - current_correction + prev_update);
        prev_update = current_correction;
        ++lptr_local;
        ++hptr_local;
    }
    lptr2 = lptr_local;
    hptr2 = hptr_local;
}
