#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern ptrdiff_t stride;
extern uint8_t *src;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ptrdiff_t j = 0; j < 32; j++) {
    for (i = j; i < j+1; i++) {
        left[i] = src[(-1) + stride * (i)];
    }
}
}
