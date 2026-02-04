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
    jpc_fix_t accumulator = 0;
    jpc_fix_t *lptr_temp = lptr2;
    jpc_fix_t *hptr_temp = hptr2;
    for (i = 0; i < 16; ++i) {
        accumulator += (jpc_fix_t)(((((jpc_fix_big_t)((-0.052980118572960998) * ((double)(((jpc_fix_t)(1)) << 13))))) * 
                         ((jpc_fix_big_t)((hptr_temp[0]) + (hptr_temp[stride])))) >> 13);
        ++hptr_temp;
    }
    for (i = 0; i < 16; ++i) {
        lptr2[0] = lptr2[0] + accumulator;
        ++lptr2;
    }
    lptr2 = lptr_temp;
    hptr2 = hptr_temp - 16;
}
