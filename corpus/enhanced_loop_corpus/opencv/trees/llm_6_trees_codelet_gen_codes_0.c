#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned short ush;

typedef ush ushf;

extern ushf *bl_count;
extern ush next_code[16];
extern unsigned int code;
extern int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ush temp_next_code;
    uint32_t temp_code = code;
    for (int bits_temp = 1; bits_temp <= 15; bits_temp++) {
        temp_code = (temp_code + bl_count[bits_temp - 1]) << 1;
        temp_next_code = (ush)temp_code;
        next_code[bits_temp] = temp_next_code;
    }
    bits = 15;
}
