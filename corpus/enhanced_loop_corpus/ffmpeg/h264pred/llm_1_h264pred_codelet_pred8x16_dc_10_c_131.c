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
    for (i = 0; i < 1; i++) {
        for (int j = 0; j < 4; j++) {
            dc0 += src[-1 + j * stride] + src[j - stride];
            dc1 += src[4 + j - stride];
            dc2 += src[-1 + (j + 4) * stride];
            dc3 += src[-1 + (j + 8) * stride];
            dc4 += src[-1 + (j + 12) * stride];
        }
    }
}
