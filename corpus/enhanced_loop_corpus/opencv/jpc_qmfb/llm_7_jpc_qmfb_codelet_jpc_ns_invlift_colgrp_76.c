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
    jpc_fix_t *ltemp = lptr2;
    jpc_fix_t *htemp = hptr2;
    jpc_fix_big_t acc = 0;
    for (i = 0; i < 16; ++i) {
        acc += ((jpc_fix_big_t)(-0.052980118572960998 * 2 * (1LL << 13)) * (jpc_fix_big_t)(htemp[i])) >> 13;
        ltemp[i] = ltemp[i] + (jpc_fix_t)(acc);
    }
    lptr2 += 16;
    hptr2 += 16;
}
