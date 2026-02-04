#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with unrolled-like consecutive grouping
    // Increase stride impact by restructuring access to emphasize vertical traversal with larger jumps
    for (i = 0; i < 4; i++) {
        ptrdiff_t base1 = i * stride;
        ptrdiff_t base2 = (i + 4) * stride;
        dc0 += src[base1 - 1] + src[i - stride];
        dc1 += src[4 + i - stride];          // Keep one access with mixed stride
        dc2 += src[base2 - 1];               // Emphasize strided access for dc2
    }
}
