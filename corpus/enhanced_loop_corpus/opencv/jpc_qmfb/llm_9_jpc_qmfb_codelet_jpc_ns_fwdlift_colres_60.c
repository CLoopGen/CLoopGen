#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < numcols; i += step) {
        jpc_fix_big_t scale = (jpc_fix_big_t)(((jpc_fix_t)(2. * 0.88291107553093395 * (1LL << 13))));
        hptr2[0] = (jpc_fix_t)(hptr2[0] + ((scale * lptr2[0]) >> 13));
        if (i + 1 < numcols) {
            hptr2[1] = (jpc_fix_t)(hptr2[1] + ((scale * lptr2[1]) >> 13));
        }
        hptr2 += step;
        lptr2 += step;
    }
}
