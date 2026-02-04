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
    long b = *(long *)(dst + i);
    long c = ((a & (~0UL / 255 * 127)) + (b & (~0UL / 255 * 127)));
    long d = ((a ^ b) & (~0UL / 255 * 128));
    long e = c ^ d;
    *(long *)(dst + i) = e;
}
}
