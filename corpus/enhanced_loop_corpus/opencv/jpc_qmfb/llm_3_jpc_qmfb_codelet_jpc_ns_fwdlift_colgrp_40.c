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
    // Variant 2: Strided memory access
    // Access every 2nd element in both arrays (stride of 2), processing 8 iterations instead of 16
    // This changes spatial locality and may simulate filtering or downsampling patterns.
    const int stride = 2;
    for (i = 0; i < 8; ++i) {
        int idx = i * stride;
        ((hptr2[idx]) = ((hptr2[idx]) + (((jpc_fix_t)(
            (((jpc_fix_big_t)(
                (jpc_fix_t)(2. * (-1.5861343420599241) * ((double)(((jpc_fix_t)(1)) << 13))))
            ) * (jpc_fix_big_t)(lptr2[idx])) >> 13)
        ))));
    }
    // Advance global pointers by total spanned distance
    hptr2 += 16;  // Still advance by 16 total positions to maintain expected side effect
    lptr2 += 16;
}
