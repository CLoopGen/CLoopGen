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
    if (numcols <= 0) return;
    jpc_fix_t prev_h = hptr2[0];
    for (i = 0; i < numcols; ++i) {
        jpc_fix_t new_val = prev_h + ((jpc_fix_t)(((
            (jpc_fix_big_t)(-1.5861343420599241 * (double)(((jpc_fix_t)1) << 13))
        ) * (jpc_fix_big_t)(lptr2[0] + lptr2[stride])) >> 13));
        hptr2[0] = new_val;
        prev_h = new_val;
        ++lptr2;
        ++hptr2;
    }
}
