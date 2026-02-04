#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        dc0 += src[i - stride] * 2;
        dc0 -= src[i - stride] / 4;
        dc1 += src[4 + i - stride] * 2;
        dc1 -= src[4 + i - stride] / 4;
        dc0 += src[2 + i - stride] * 2;
        dc1 += src[6 + i - stride] * 2;
    }
}
