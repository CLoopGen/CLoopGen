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
        acc += (jpc_fix_t)((((jpc_fix_big_t)((jpc_fix_t)(-3.1722686841198482 * ((double)(((jpc_fix_t)(1)) << 13))))) * (jpc_fix_big_t)(lptr2[i])) >> 13);
    }
    hptr2[0] = hptr2[0] + acc;
    hptr2 += 16;
    lptr2 += 16;
}
