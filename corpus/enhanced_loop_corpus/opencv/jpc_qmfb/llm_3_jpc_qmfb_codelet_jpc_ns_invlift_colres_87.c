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
    // Variant 2: Consecutive reverse traversal
    // Access arrays from the end to the beginning consecutively
    jpc_fix_t *h_temp = hptr2 + (numcols - 1);
    jpc_fix_t *l_temp = lptr2 + (numcols - 1);

    for (i = numcols - 1; i >= 0; --i) {
        h_temp[0] = h_temp[0] + (
            -(jpc_fix_t)(
                ((jpc_fix_big_t)(
                    (jpc_fix_t)(
                        (2. * (0.88291107553093395)) * ((double)(((jpc_fix_t)(1)) << 13))
                    )
                ) * (jpc_fix_big_t)(l_temp[0])
            ) >> 13)
        );
        --h_temp;
        --l_temp;
    }
    // Update original pointers if side effects are expected (optional based on context)
    // Here we do not modify hptr2/lptr2 globally since mutation is local
}
