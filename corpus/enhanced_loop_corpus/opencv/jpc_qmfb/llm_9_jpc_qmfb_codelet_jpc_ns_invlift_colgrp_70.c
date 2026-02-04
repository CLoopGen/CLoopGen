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
    jpc_fix_big_t hval = hptr2[0];
    jpc_fix_big_t scaled = ((jpc_fix_big_t)(0.443506852043971 * (1 << 13))) * hval;
    jpc_fix_t correction = (jpc_fix_t)(scaled >> 13);
    lptr2[0] = lptr2[0] - correction;
    lptr2[1] = lptr2[1] - correction;  // Process two elements
    hptr2 += 2;
    lptr2 += 2;
    ++i; // Increment again to maintain trip count effect
}
}
