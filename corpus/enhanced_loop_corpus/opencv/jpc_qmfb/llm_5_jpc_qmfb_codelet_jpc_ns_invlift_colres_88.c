#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < numcols; ++i) {
        jpc_fix_t temp_sum = lptr2[0] + lptr2[stride];
        jpc_fix_big_t scaled_val = ((jpc_fix_big_t)((jpc_fix_t)(0.88291107553093395 * (1LL << 13)))) * temp_sum;
        jpc_fix_t correction = (jpc_fix_t)(scaled_val >> 13);
        
        if (correction != 0) {
            hptr2[0] = hptr2[0] - correction;
        }
        ++lptr2;
        ++hptr2;
    }
}
