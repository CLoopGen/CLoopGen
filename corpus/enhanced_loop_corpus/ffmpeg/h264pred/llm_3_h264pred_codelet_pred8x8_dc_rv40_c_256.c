#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern unsigned int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with fixed offset expansion
    // Unroll the effective access pattern into a more regular strided form using pointer arithmetic
    ptrdiff_t s = stride;
    uint8_t *p = src;

    for (i = 0; i < 4; i++) {
        dc0 += p[-1 + i * s] + p[i - s];          // Original terms
        dc0 += p[4 + i - s];
        dc0 += p[-1 + i * s + 4 * s];            // Rearranged last term for clarity in striding
    }
}
