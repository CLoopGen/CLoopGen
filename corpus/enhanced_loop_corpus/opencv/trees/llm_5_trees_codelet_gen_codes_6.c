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
    for (bits = 1; bits <= 15; bits++) {
        code += bl_count[bits - 1];
        code <<= 1;
        if ((code & 0xFFFF) != 0) {
            next_code[bits] = (uint16_t)code;
        } else {
            next_code[bits] = 1;
        }
    }
}
