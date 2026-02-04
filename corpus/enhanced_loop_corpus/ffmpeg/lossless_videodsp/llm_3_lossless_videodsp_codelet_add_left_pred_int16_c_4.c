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
    // Variant 2: Reverse sequential access
    // Processes the arrays from near the end towards the beginning,
    // maintaining two updates per iteration but in reverse order.
    for (i = w - 2; i >= 0; i--) {
        acc += src[i];
        dst[i] = acc &= mask;
        i--;
        if (i >= 0) {
            acc += src[i];
            dst[i] = acc &= mask;
        }
    }
}
