#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    int j;
    for (j = 0; j < 2; j++) {
        dc0 += src[-1 + (i * 2 + j) * stride] + src[i * 2 + j - stride];
    }
    dc1 += src[4 + i * 2 - stride];
    dc2 += src[-1 + (i * 2 + 4) * stride];
}
}
