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
    uint32_t temp_code = code;
    for (int bits_temp = 1; bits_temp <= 15; bits_temp++) {
        temp_code = (temp_code + bl_count[bits_temp - 1]) << 1;
        next_code[bits_temp] = (uint16_t)temp_code;
    }
    code = temp_code;
}
