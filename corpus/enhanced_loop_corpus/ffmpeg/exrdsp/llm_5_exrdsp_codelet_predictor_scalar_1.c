#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t size;
extern ptrdiff_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < size; i++) {
    ptrdiff_t prev_index = i - 1;
    if (prev_index >= 0) {
        src[i] += src[prev_index] - 128;
    }
}
}
