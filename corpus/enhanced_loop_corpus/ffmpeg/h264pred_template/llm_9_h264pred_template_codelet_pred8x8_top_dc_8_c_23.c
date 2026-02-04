#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        dc0 += src[i * 2 - stride] + src[i * 2 + 1 - stride];
        dc1 += src[4 + i * 2 - stride] + src[5 + i * 2 - stride];
        dc0 -= (src[i * 2 - stride] >> 1);
        dc1 -= (src[4 + i * 2 - stride] >> 1);
    }
}
