#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        jpc_fix_t x = hptr2[0];
        jpc_fix_big_t scaled_val = (jpc_fix_big_t)x;
        jpc_fix_big_t factor = (jpc_fix_big_t)(((jpc_fix_t)(1. / (1. / 1.62578613134411) * (1 << 13))));
        hptr2[0] = (jpc_fix_t)((scaled_val * factor + (1 << 12)) >> 13); // Add rounding
        hptr2[1] = (jpc_fix_t)((scaled_val * factor * 3) >> 13);
        hptr2 += 2;
    }
}
