#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    int temp0 = src[-1 + i * stride] + src[i - stride];
    int temp1 = src[-1 + (i + 1) * stride] + src[(i + 1) - stride];
    dc0 += temp0 + temp1;
    dc1 += src[4 + i - stride];
    dc2 += src[-1 + (i + 4) * stride];
}
}
