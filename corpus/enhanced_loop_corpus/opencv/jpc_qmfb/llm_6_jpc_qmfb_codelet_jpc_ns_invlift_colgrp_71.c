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
    jpc_fix_t temp_lptr[16];
    for (i = 0; i < 16; ++i) {
        temp_lptr[i] = lptr2[i] + ((-(((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)((((0.443506852043971)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)((hptr2[i] + hptr2[i + stride]))))) >> (13)))));
    }
    for (i = 0; i < 16; ++i) {
        lptr2[i] = temp_lptr[i];
    }
    lptr2 += 16;
    hptr2 += 16;
}
