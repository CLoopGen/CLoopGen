#include <stdio.h>

#include <inttypes.h>

typedef unsigned int u32;

typedef unsigned char u8;

typedef union {
    u32 u[16];
    u8 c[64];
} chacha_buf;

extern chacha_buf *output;
extern  u32 input[16];
extern u32 x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; ++i) {
        u32 temp1 = x[i] + input[i];
        u32 temp2 = temp1 ^ (temp1 << 1);
        u32 temp3 = temp2 + (temp1 >> 1);
        output->u[i] = temp3 ^ input[i];
    }
}
