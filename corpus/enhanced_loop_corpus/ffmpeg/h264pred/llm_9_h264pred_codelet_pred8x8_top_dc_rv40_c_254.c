#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern unsigned int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        dc0 += src[i * 2 - stride];
        dc0 += src[i * 2 - stride + 1];
        dc0 += src[i * 2 - stride + 2];
        dc0 += src[i * 2 - stride + 3];
    }
}
