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
    jpc_fix_big_t coeff = (jpc_fix_big_t)(-1.5861343420599241 * (1LL << 13));
    for (i = 0; i < 16; ++i) {
        htemp[0] = htemp[0] + (jpc_fix_t)((-(((jpc_fix_big_t)coeff * (jpc_fix_big_t)(ltemp[0])) >> 13)));
        ++ltemp;
        ++htemp;
    }
    lptr2 = ltemp;
    hptr2 = htemp;
}
