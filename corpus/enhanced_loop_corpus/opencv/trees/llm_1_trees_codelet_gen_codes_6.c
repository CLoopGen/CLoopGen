#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *bl_count;
extern uint16_t next_code[16];
extern unsigned int code;
extern int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective loop depth by unrolling the first few iterations and combining with original loop
    // Manually unroll bits = 1, then continue with loop from bits = 2
    if (1 <= 15) {
        code = (code + bl_count[0]) << 1;
        next_code[1] = (uint16_t)code;
    }
    for (bits = 2; bits <= 15; bits++) {
        code = (code + bl_count[bits - 1]) << 1;
        next_code[bits] = (uint16_t)code;
    }
}
