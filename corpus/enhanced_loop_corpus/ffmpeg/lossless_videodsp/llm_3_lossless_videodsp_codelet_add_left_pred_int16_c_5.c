#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern unsigned int mask;
extern ptrdiff_t w;
extern unsigned int acc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access from the end
    // Process elements starting from the last index down to 0
    for (; i >= 0 && (w - 1 - i) >= 0; i++) {
        ptrdiff_t idx = w - 1 - i;
        acc += src[idx];
        dst[idx] = acc &= mask;
    }
}
