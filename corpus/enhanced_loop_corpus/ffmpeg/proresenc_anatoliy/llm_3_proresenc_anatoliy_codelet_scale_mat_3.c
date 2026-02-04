#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int *dst;
extern int scale;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (consecutive but in reverse order)
    for (i = 63; i >= 0; i--) {
        dst[i] = src[i] * scale;
    }
}
