#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc2;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    dc0 += src[-1 + (2*i) * stride];
    dc0 += src[-1 + (2*i + 1) * stride];
    dc2 += src[-1 + (2*i + 4) * stride];
    dc2 += src[-1 + (2*i + 5) * stride];
}
}
