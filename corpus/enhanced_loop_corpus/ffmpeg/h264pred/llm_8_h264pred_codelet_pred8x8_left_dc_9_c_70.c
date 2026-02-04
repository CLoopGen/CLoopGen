#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc2;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 8; i++) {
        dc0 += src[-1 + i * stride] + src[-1 + (i * stride) + 1];
        if (i >= 4) {
            dc2 += src[-1 + (i + 4) * stride] + src[-1 + (i + 4) * stride + 1];
        }
    }
}
