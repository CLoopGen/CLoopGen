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
    jpc_fix_t h_sum_0 = hptr2[0] + hptr2[stride];
    jpc_fix_t h_sum_1 = hptr2[1] + hptr2[stride + 1];
    jpc_fix_big_t scale = (jpc_fix_big_t)(0.443506852043971 * (1LL << 13));
    lptr2[0] = lptr2[0] + (jpc_fix_t)((scale * h_sum_0) >> 13);
    lptr2[1] = lptr2[1] + (jpc_fix_t)((scale * h_sum_1) >> 13);
    lptr2 += 2;
    hptr2 += 2;
}
}
