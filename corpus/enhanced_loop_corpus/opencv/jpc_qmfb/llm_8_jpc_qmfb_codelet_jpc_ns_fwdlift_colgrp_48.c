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
    for (i = 0; i < 32; ++i) {
        jpc_fix_big_t temp1 = ((jpc_fix_big_t)(lptr2[0])) << 1;
        jpc_fix_big_t temp2 = ((jpc_fix_big_t)(lptr2[1])) << 1;
        hptr2[0] = (jpc_fix_t)((hptr2[0] + ((temp1 * (jpc_fix_big_t)(((jpc_fix_t)(2. * 0.88291107553093395 * ((double)(((jpc_fix_t)(1)) << 13)))))) >> 13)));
        hptr2[1] = (jpc_fix_t)((hptr2[1] + ((temp2 * (jpc_fix_big_t)(((jpc_fix_t)(2. * 0.88291107553093395 * ((double)(((jpc_fix_t)(1)) << 13)))))) >> 13)));
        lptr2 += 2;
        hptr2 += 2;
        if (i % 8 == 7) {
            hptr2[-16] = (jpc_fix_t)((hptr2[-16] + hptr2[-1]) >> 1);
        }
    }
}
