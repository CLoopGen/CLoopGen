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
    uint32_t local_code = code;
    ush local_next_code[16] = {0};
    for (int i = 1; i <= 15; i++) {
        local_code = (local_code + bl_count[i - 1]);
        local_next_code[i] = (ush)(local_code << 1);
        local_code <<= 1;
    }
    for (int i = 1; i <= 15; i++) {
        next_code[i] = local_next_code[i];
    }
    bits = 15;
}
