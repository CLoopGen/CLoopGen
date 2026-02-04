#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Consecutive Memory Access (processing array from end to start)
    jpc_fix_t *ltemp = lptr2 + (numcols - 1);
    jpc_fix_t *htemp = hptr2 + (numcols - 1);

    for (i = 0; i < numcols; ++i) {
        ltemp[0] = ltemp[0] + (
            (jpc_fix_t)(
                ((jpc_fix_big_t)(
                    (jpc_fix_t)(
                        (2. * (-0.052980118572960998)) * ((double)(((jpc_fix_t)(1)) << 13))
                    )
                )) * (jpc_fix_big_t)(htemp[0])
            ) >> 13
        );
        --ltemp;
        --htemp;
    }
    // Update original pointers if side effects are needed (optional, depending on use case)
    // lptr2 += numcols; hptr2 += numcols;
}
