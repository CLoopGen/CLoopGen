#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src1;
extern uint8_t *src2;
extern int w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access
    // Traverse from the end of the array toward the beginning
    for (; i >= 0 && (w - 1 - i) >= 0; i++)
        dst[w - 1 - i] = src1[w - 1 - i] + src2[w - 1 - i];
}
