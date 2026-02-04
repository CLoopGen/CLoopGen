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
        ptrdiff_t idx1 = i * 2 - stride;
        ptrdiff_t idx2 = 4 + i * 2 - stride;
        dc0 += src[idx1] + src[idx1 + 1];
        dc1 += src[idx2] + src[idx2 + 1];
        dc0 += src[idx1] * src[idx1 + 1];
        dc1 += src[idx2] * src[idx2 + 1];
    }
}
