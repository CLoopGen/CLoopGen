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
        u32 val = x[i] + input[i];
        u8* dst = &output->c[4 * i];

        dst[0] = (u8)(val);
        dst[1] = (u8)(val >> 8);
        dst[2] = (u8)(val >> 16);
        dst[3] = (u8)(val >> 24);

        // Add extra arithmetic to increase computational intensity
        val ^= input[i];
        val = (val << 3) | (val >> 29); // Rotate left by 3
        dst[0] ^= (u8)(val);
    }
}
