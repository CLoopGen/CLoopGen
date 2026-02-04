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
    uint32_t local_next_code[16] = {0};
    uint32_t accum = code;
    for (int b = 1; b <= 15; b++) {
        accum = (accum + bl_count[b - 1]) << 1;
        local_next_code[b] = accum;
    }
    for (int b = 1; b <= 15; b++) {
        next_code[b] = (uint16_t)local_next_code[b];
    }
}
