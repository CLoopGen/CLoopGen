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
    for (i = 0; i < 8; ++i) {
        jpc_fix_big_t scale = (jpc_fix_big_t)(((jpc_fix_t)(2. * 0.88291107553093395 * ((double)(((jpc_fix_t)(1)) << 13)))));
        jpc_fix_big_t val0 = (jpc_fix_big_t)(lptr2[0]);
        jpc_fix_big_t val1 = (jpc_fix_big_t)(lptr2[1]);
        jpc_fix_big_t val2 = (jpc_fix_big_t)(lptr2[2]);
        jpc_fix_big_t val3 = (jpc_fix_big_t)(lptr2[3]);

        hptr2[0] = (jpc_fix_t)((hptr2[0] + ((val0 * scale) >> 13)));
        hptr2[1] = (jpc_fix_t)((hptr2[1] + ((val1 * scale) >> 13)));
        hptr2[2] = (jpc_fix_t)((hptr2[2] + ((val2 * scale) >> 13)));
        hptr2[3] = (jpc_fix_t)((hptr2[3] + ((val3 * scale) >> 13)));

        lptr2 += 4;
        hptr2 += 4;
    }
}
