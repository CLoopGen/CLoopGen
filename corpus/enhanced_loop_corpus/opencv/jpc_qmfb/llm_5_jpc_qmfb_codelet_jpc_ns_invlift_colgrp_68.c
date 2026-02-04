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
    for (i = 0; i < 16; ++i) {
        if (i >= 4 && i < 12) {
            continue;
        }
        lptr2[0] = ((jpc_fix_t)((((jpc_fix_big_t)(lptr2[0])) * ((jpc_fix_big_t)(((jpc_fix_t)(((1. / (1. / 1.23017410558578)) * ((double)(((jpc_fix_t)(1)) << (13))))))))) >> (13)));
        ++lptr2;
    }
}
