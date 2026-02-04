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
for (i = 0; i < 32; ++i) {
    jpc_fix_big_t temp1 = ((jpc_fix_big_t)(hptr2[0]) + hptr2[stride]);
    jpc_fix_big_t temp2 = (((jpc_fix_big_t)(((jpc_fix_t)((((0.443506852043971)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * temp1);
    jpc_fix_t result = (jpc_fix_t)(temp2 >> 13);
    lptr2[0] = lptr2[0] - result;
    ++lptr2;
    ++hptr2;
}
}
