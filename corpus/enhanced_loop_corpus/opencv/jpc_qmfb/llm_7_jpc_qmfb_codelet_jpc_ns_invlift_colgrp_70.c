#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t accum = 0;
    for (i = 0; i < 16; ++i) {
        jpc_fix_big_t scaled_h = ((jpc_fix_big_t)(hptr2[0])) << 1;
        jpc_fix_big_t computed = ((jpc_fix_big_t)(-((int)(2. * 0.443506852043971 * 8192)))) * scaled_h;
        accum += (jpc_fix_t)(computed >> 13);
        lptr2[0] = accum;
        ++lptr2;
        ++hptr2;
    }
}
