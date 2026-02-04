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
for (i = 0; i < 32; i += 4) {
    left[i] = src[-1 + stride * (i)];
    if (i + 1 < 32) left[i + 1] = src[-1 + stride * (i + 1)];
    if (i + 2 < 32) left[i + 2] = src[-1 + stride * (i + 2)];
    if (i + 3 < 32) left[i + 3] = src[-1 + stride * (i + 3)];
}
}
