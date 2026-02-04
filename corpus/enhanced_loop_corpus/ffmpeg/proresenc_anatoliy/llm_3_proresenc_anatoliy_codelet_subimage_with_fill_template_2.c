#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern unsigned int dst_width;
extern unsigned int dst_height;
extern int i;
extern int j;
extern uint16_t *last_line;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Consecutive Memory Access Pattern
    // Traverse each row in reverse order to modify access pattern
    // This maintains correctness but changes cache behavior (reverse sequential access)
    for (; i < dst_height; i++) {
        for (j = dst_width; j > 0; --j) {
            dst[j - 1] = last_line[j - 1];
        }
        dst += dst_width;
    }
}
