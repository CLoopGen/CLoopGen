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
for (i = 0; i <= w - (int)sizeof(long); i += sizeof(long)*2) {
    long a1 = *(long *)(src + i);
    long b1 = *(long *)(dst + i);
    long a2 = *(long *)(src + i + sizeof(long));
    long b2 = *(long *)(dst + i + sizeof(long));
    *(long *)(dst + i) = ((a1 & (~0UL / 255 * 127)) + (b1 & (~0UL / 255 * 127))) ^ ((a1 ^ b1) & (~0UL / 255 * 128));
    *(long *)(dst + i + sizeof(long)) = ((a2 & (~0UL / 255 * 127)) + (b2 & (~0UL / 255 * 127))) ^ ((a2 ^ b2) & (~0UL / 255 * 128));
}
}
