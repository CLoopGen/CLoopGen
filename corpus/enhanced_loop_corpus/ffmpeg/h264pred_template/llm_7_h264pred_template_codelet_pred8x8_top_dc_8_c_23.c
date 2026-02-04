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
    dc0 = 0;
    dc1 = 0;
    for (i = 0; i < 4; i++) {
        dc0 += src[i - stride] * (i + 1);
        dc1 += src[4 + i - stride] * (5 - i);
    }
}
