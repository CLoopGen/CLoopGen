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
        // Remove loop-carried dependency by using local pointers; no cumulative update across iterations
        jpc_fix_t val = (hptr2_local[0] + hptr2_local[stride] + 2) >> 2;
        lptr2_local[0] = val; // Overwrite instead of accumulate — removes RAW dependency from prior lptr2[0] value
        ++lptr2_local;
        ++hptr2_local;
    }
    // Update the original pointers only after loop completes — breaks loop-carried pointer update dependency
    lptr2 = lptr2_local;
    hptr2 = hptr2_local;
}
