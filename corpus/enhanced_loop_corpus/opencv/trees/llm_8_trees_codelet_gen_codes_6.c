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
    for (bits = 1; bits <= 15; bits += 2) {
        code = (code + bl_count[bits - 1]) << 1;
        next_code[bits] = (uint16_t)code;
        if (bits + 1 <= 15) {
            code = (code + bl_count[bits]) << 1;
            next_code[bits + 1] = (uint16_t)code;
        }
    }
}
