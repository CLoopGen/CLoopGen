#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern ptrdiff_t stride;
extern uint16_t *src;
extern uint16_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = size * 2;
    for (i = 0; i < limit; i++) {
        int idx = i / 2;
        left[idx] = src[-1 + stride * idx] + 1;
    }
}
