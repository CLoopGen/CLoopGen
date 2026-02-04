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
    int offset1 = -1 + i * stride;
    int offset2 = i - stride;
    dc0 += src[offset1] + src[offset2];
    dc1 += src[4 + offset2];
    dc2 += src[-1 + (i + 4) * stride];
    
    offset1 = -1 + (i + 1) * stride;
    offset2 = (i + 1) - stride;
    dc0 += src[offset1] + src[offset2];
    dc1 += src[4 + offset2];
    dc2 += src[-1 + (i + 5) * stride];
}
}
