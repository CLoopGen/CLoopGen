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
    // Variant 1: Strided memory access with stride of 2
    // Arrays are accessed with a fixed stride, skipping every other element
    for (i = 0; i < numcols; i += 1) {
        int idx = i * 2; // Stride of 2
        if (idx < numcols) { // Safe bound check to avoid overflow
            hptr2[idx] = hptr2[idx] + (
                -(jpc_fix_t)(
                    ((jpc_fix_big_t)(
                        (jpc_fix_t)(
                            (2. * (0.88291107553093395)) * ((double)(((jpc_fix_t)(1)) << 13))
                        )
                    ) * (jpc_fix_big_t)(lptr2[idx])
                ) >> 13)
            );
        }
    }
    // Note: Pointers hptr2 and lptr2 are not incremented as we use indexed access instead
}
