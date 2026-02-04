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
        long a = *(long *)(src + i);
        long b = *(long *)(dst + i + (i % 2 == 0 ? sizeof(long) : -sizeof(long))); // Break true dependence by varying access index
        long c = (i == 0) ? b : *(long *)(dst + i - sizeof(long)); // Introduce artificial dependence on previous result
        long mixed = ((a & (~0UL / 255 * 127)) + (c & (~0UL / 255 * 127))) ^ ((a ^ c) & (~0UL / 255 * 128));
        *(long *)(dst + i) = mixed;
    }
}
