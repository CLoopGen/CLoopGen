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
    for (int depth1 = 0; depth1 < 4; ++depth1) {
        for (int depth2 = 0; depth2 < 2; ++depth2) {
            for (int depth3 = 0; depth3 < 2; ++depth3) {
                i = depth1 * 4 + depth2 * 2 + depth3;
                ((lptr2[0]) = ((lptr2[0]) + ((-(((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((2. * (0.443506852043971)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(hptr2[0]))) >> (13))))))));
                ++lptr2;
                ++hptr2;
            }
        }
    }
}
