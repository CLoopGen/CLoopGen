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
    jpc_fix_big_t scaled_factor = (jpc_fix_big_t)(2. * 0.443506852043971 * ((double)(((jpc_fix_t)(1)) << 13)));
    jpc_fix_big_t temp1 = scaled_factor * hptr2[0];
    jpc_fix_big_t temp2 = scaled_factor * hptr2[1];
    jpc_fix_big_t combined = (temp1 + temp2) >> 1;
    lptr2[0] = (jpc_fix_t)(lptr2[0] + (combined >> 13));
    ++lptr2;
    hptr2 += 2;
}
}
