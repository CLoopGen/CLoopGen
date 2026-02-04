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
        jpc_fix_t temp_val = lptr2[0] + lptr2[stride];
        if (temp_val != 0) {
            hptr2[0] = hptr2[0] - (
                (jpc_fix_t)(
                    (((jpc_fix_big_t)((jpc_fix_t)(-1.5861343420599241 * (1LL << 13)))) *
                     (jpc_fix_big_t)temp_val
                    ) >> 13
                )
            );
        }
        ++lptr2;
        ++hptr2;
    }
}
