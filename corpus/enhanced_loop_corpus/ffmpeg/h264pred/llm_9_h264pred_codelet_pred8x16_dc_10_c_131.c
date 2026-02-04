#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern int dc3;
extern int dc4;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    int temp0 = src[-1 + i * stride] + src[i - stride];
    int temp1 = src[4 + i - stride];
    dc0 += temp0;
    dc1 += temp1;
    dc2 += src[-1 + (i + 4) * stride];
    // Combine two iterations’ worth of work for dc3 and dc4 with manual unrolling
    dc3 += src[-1 + (i*2 + 8) * stride] + src[-1 + (i*2 + 9) * stride];
    dc4 += src[-1 + (i*2 + 12) * stride] + src[-1 + (i*2 + 13) * stride];
}
}
