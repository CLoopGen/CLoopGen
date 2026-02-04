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
    for (i = 0; i < 4; ++i) {
        const ptrdiff_t idx1 = i - stride;
        const ptrdiff_t idx2 = 4 + i - stride;
        if (src[idx1] >= 128) {
            dc0 += src[idx1];
        }
        if (src[idx2] < 128) {
            dc1 += src[idx2];
        }
    }
}
