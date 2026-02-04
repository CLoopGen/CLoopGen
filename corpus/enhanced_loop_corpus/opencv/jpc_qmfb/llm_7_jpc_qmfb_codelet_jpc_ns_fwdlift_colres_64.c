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
    jpc_fix_t* lptr2_local = lptr2;
    jpc_fix_t* hptr2_local = hptr2;
    jpc_fix_big_t factor = (jpc_fix_big_t)(((jpc_fix_t)((((0.443506852043971)) * ((double)(((jpc_fix_t)(1)) << (13)))))));
    for (i = 0; i < numcols; ++i) {
        jpc_fix_big_t h_sum = (jpc_fix_big_t)(hptr2_local[0] + hptr2_local[stride]);
        lptr2_local[0] = (jpc_fix_t)(lptr2_local[0] + ((factor * h_sum) >> 13));
        ++lptr2_local;
        ++hptr2_local;
    }
    // Update original pointers if needed by side effect (though not visible outside without globals update)
}
