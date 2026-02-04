#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t size;
extern ptrdiff_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward pairwise access with offset
    if (size > 1) {
        for (i = 1; i < size - 1; i++)
            src[i + 1] += src[i] - 128;
    }
}
