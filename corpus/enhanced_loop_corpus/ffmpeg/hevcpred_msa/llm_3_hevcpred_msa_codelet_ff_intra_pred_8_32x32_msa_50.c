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
ptrdiff_t index = -1;
for (i = 0; i < 32; i++) {
    left[i] = src[index];
    index += stride;
}
}
