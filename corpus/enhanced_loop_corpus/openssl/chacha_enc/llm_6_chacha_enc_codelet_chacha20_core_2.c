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



void loop() {
    u32 temp[16];
    for (i = 0; i < 16; ++i) {
        temp[i] = x[i] + input[i];
        (output->c)[4 * i + 0] = (u8)(temp[i] >> 0);
        (output->c)[4 * i + 1] = (u8)(temp[i] >> 8);
        (output->c)[4 * i + 2] = (u8)(temp[i] >> 16);
        (output->c)[4 * i + 3] = (u8)(temp[i] >> 24);
    }
}
