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
        jpc_fix_big_t sum_low = (jpc_fix_big_t)(lptr2[0] + lptr2[stride]);
        jpc_fix_big_t scaled = (((jpc_fix_big_t)((-1.5861343420599241 * (1LL << 13)))) * sum_low) >> 13;
        hptr2[0] = (jpc_fix_t)(hptr2[0] + scaled);
        // Unroll one additional step manually to reduce loop overhead
        ++lptr2; ++hptr2;
        if (i < 8) { // Prevent over-increment on last iteration
            sum_low = (jpc_fix_big_t)(lptr2[0] + lptr2[stride]);
            scaled = (((jpc_fix_big_t)((-1.5861343420599241 * (1LL << 13)))) * sum_low) >> 13;
            hptr2[0] = (jpc_fix_t)(hptr2[0] + scaled);
            ++lptr2; ++hptr2;
        }
    }
}
