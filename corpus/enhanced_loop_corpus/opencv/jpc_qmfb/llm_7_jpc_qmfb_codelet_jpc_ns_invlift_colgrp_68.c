#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern jpc_fix_t *lptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t accumulator = 0;
    for (i = 0; i < 16; ++i) {
        accumulator += lptr2[0]; // Introduce loop-carried RAW dependency
        lptr2[0] = ((jpc_fix_t)((((jpc_fix_big_t)(accumulator)) * ((jpc_fix_big_t)(((jpc_fix_t)(((1. / (1. / 1.23017410558578)) * ((double)(((jpc_fix_t)(1)) << (13))))))))) >> (13)));
        ++lptr2;
    }
    // Final write-back or side effect to maintain semantic validity
    lptr2 -= 16;
    lptr2[0] = accumulator; // Breaks independence across iterations
}
