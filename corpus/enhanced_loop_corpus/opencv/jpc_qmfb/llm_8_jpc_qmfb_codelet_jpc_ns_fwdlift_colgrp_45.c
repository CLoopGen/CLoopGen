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
    jpc_fix_big_t temp1 = ((jpc_fix_big_t)(((jpc_fix_t)(2. * (-0.052980118572960998) * ((double)(((jpc_fix_t)(1)) << 13))))));
    jpc_fix_big_t temp2 = hptr2[0];
    jpc_fix_big_t product = temp1 * temp2;
    jpc_fix_t result = (jpc_fix_t)(product >> 13);
    lptr2[0] = lptr2[0] + result;
    ++lptr2;
    ++hptr2;
}
}
