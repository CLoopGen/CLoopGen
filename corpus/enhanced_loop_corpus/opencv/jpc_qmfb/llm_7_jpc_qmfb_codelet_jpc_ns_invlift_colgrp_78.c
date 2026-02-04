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
    jpc_fix_t acc = 0;
    for (i = 0; i < 16; ++i) {
        acc = (jpc_fix_t)((-(((jpc_fix_big_t)(((jpc_fix_t)(((2. * (-0.052980118572960998)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(hptr2[i])))) >> (13));
        lptr2[i] = lptr2[i] + acc;
    }
    // Introduce a final write to break potential WAW with future calls
    if (16 > 0) {
        lptr2[-1] = lptr2[-1]; // WAR hazard introduced via artificial dependency
    }
}
