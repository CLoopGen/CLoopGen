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
for (i = 0; i < numcols; ++i) {
    jpc_fix_big_t temp = ((jpc_fix_big_t)(2 * -0.052980118572960998 * (1LL << 13)));
    jpc_fix_t scaled_h = (jpc_fix_t)((temp * hptr2[0]) >> 13);
    lptr2[0] += scaled_h;
    ++lptr2;
    ++hptr2;
}
}
