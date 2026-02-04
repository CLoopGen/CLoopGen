#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern intptr_t w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i <= w - (int)sizeof(long); i += sizeof(long)) {
    long a = *(long *)(src1 + i);
    long b = *(long *)(src2 + i);
    *(long *)(dst + i) = ((a | (~0UL / 255 * 128)) - (b & (~0UL / 255 * 127))) ^ ((a ^ b ^ (~0UL / 255 * 128)) & (~0UL / 255 * 128));
}

}
