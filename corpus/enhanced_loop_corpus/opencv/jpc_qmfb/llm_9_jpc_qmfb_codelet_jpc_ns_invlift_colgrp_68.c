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
    for (i = 0; i < 8; ++i) {
        jpc_fix_big_t x0 = lptr2[0];
        jpc_fix_big_t x1 = lptr2[1];
        jpc_fix_t k = (jpc_fix_t)(((1.0 / (1.0 / 1.23017410558578)) * ((double)(((jpc_fix_t)(1)) << 13))));
        lptr2[0] = (jpc_fix_t)(((x0 * k) >> 13));
        lptr2[1] = (jpc_fix_t)(((x1 * k) >> 13));
        lptr2 += 2;
    }
}
