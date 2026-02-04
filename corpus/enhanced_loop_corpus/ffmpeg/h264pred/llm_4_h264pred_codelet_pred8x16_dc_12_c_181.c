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
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        if (i % 2 == 0) {
            dc0 += src[-1 + i * stride] + src[i - stride];
            dc1 += src[4 + i - stride];
        } else {
            dc2 += src[-1 + (i + 4) * stride];
        }
        if (i >= 2) {
            dc3 += src[-1 + (i + 8) * stride];
            dc4 += src[-1 + (i + 12) * stride];
        }
    }
}
