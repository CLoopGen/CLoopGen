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
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    int j;
    dc0 += src[-1 + i * stride] + src[i - stride];
    dc1 += src[4 + i - stride];
    for (j = 0; j < 3; j++) {
        dc2 += src[-1 + (i + j + 4) * stride];
        dc3 += src[-1 + (i + j + 8) * stride];
        dc4 += src[-1 + (i + j + 12) * stride];
    }
}
}
