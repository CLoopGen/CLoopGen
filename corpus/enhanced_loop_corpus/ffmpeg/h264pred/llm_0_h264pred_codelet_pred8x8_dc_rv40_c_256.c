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
for (int j = 0; j < 2; j++) {
    for (i = 0; i < 4; i++) {
        dc0 += src[-1 + i * stride] + src[i - stride];
        dc0 += src[4 + i - stride];
        dc0 += src[-1 + (i + 4) * stride];
    }
}
}
