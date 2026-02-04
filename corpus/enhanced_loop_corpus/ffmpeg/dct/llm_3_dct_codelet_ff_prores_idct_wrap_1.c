#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access (iterate from end to start)
    for (i = 63; i >= 0; i--) {
        dst[i] -= 512;
    }
}
