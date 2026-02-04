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
    for (i = 0; i < 8; ++i) {
        u32 sum0 = x[i] + input[i];
        u32 sum1 = x[i + 8] + input[i + 8];

        output->c[4 * i + 0] = (u8)(sum0 >> 0);
        output->c[4 * i + 1] = (u8)(sum0 >> 8);
        output->c[4 * i + 2] = (u8)(sum0 >> 16);
        output->c[4 * i + 3] = (u8)(sum0 >> 24);

        output->c[4 * (i + 8) + 0] = (u8)(sum1 >> 0);
        output->c[4 * (i + 8) + 1] = (u8)(sum1 >> 8);
        output->c[4 * (i + 8) + 2] = (u8)(sum1 >> 16);
        output->c[4 * (i + 8) + 3] = (u8)(sum1 >> 24);
    }
}
