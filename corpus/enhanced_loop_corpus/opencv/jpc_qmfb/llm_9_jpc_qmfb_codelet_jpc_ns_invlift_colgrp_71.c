#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; ++i) {
    jpc_fix_t hsum1 = hptr2[0] + hptr2[stride];
    jpc_fix_t hsum2 = hptr2[1] + hptr2[stride + 1];
    jpc_fix_big_t scaled1 = ((jpc_fix_big_t)hsum1 * (jpc_fix_t)(0.443506852043971 * (1 << 13))) >> 13;
    jpc_fix_big_t scaled2 = ((jpc_fix_big_t)hsum2 * (jpc_fix_t)(0.443506852043971 * (1 << 13))) >> 13;
    lptr2[0] = lptr2[0] - scaled1;
    lptr2[1] = lptr2[1] - scaled2;
    lptr2 += 2;
    hptr2 += 2;
}
}
