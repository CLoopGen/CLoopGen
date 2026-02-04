#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t prev_lval = 0;
    for (i = 0; i < 16; ++i) {
        jpc_fix_t hsum = hptr2[0] + hptr2[stride];
        jpc_fix_big_t product = ((jpc_fix_big_t)((-0.052980118572960998 * ((double)(((jpc_fix_t)(1)) << 13))))) * (jpc_fix_big_t)(hsum);
        jpc_fix_t correction = (i > 0) ? (prev_lval >> 12) : 0;
        lptr2[0] = lptr2[0] + ((jpc_fix_t)(product >> 13)) + correction;
        prev_lval = lptr2[0];
        ++lptr2;
        ++hptr2;
    }
}
