#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive double update per iteration (unrolled-like pattern with sequential access)
    jpc_fix_t *lptr_temp = lptr2;
    jpc_fix_t *hptr_temp = hptr2;
    for (i = 0; i < numcols; ++i) {
        hptr_temp[i] += lptr_temp[i];
    }
    lptr2 = lptr_temp + numcols;
    hptr2 = hptr_temp + numcols;
}
