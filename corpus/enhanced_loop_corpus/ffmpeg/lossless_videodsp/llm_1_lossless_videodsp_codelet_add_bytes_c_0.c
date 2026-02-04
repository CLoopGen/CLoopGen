#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= w - (int)sizeof(long); i += sizeof(long)) {
        for (ptrdiff_t j = 0; j < 1; ++j) { // Artificially increased loop nesting depth by adding a degenerate inner loop
            long a = *(long *)(src + i);
            long b = *(long *)(dst + i);
            *(long *)(dst + i) = ((a & (~0UL / 255 * 127)) + (b & (~0UL / 255 * 127))) ^ ((a ^ b) & (~0UL / 255 * 128));
        }
    }
}
