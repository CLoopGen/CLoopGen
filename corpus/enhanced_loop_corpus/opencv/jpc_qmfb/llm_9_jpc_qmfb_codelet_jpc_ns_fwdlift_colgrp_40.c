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
    jpc_fix_big_t temp1 = ((jpc_fix_big_t)(-3172)) * (jpc_fix_big_t)(lptr2[0]);
    jpc_fix_big_t temp2 = ((jpc_fix_big_t)( 2437)) * (jpc_fix_big_t)(lptr2[1]);
    jpc_fix_big_t temp3 = ((jpc_fix_big_t)(-1294)) * (jpc_fix_big_t)(lptr2[2]);
    jpc_fix_big_t temp4 = ((jpc_fix_big_t)(  561)) * (jpc_fix_big_t)(lptr2[3]);
    hptr2[0] = (jpc_fix_t)((temp1 + temp2 + temp3 + temp4) >> 13);
    hptr2[1] = (jpc_fix_t)((temp4 - temp3 + temp2 - temp1) >> 13);
    hptr2 += 2;
    lptr2 += 4;
}
}
