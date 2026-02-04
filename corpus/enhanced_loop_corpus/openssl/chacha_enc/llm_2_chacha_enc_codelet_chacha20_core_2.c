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
    for (i = 0; i < 16; ++i) {
        u32 sum = x[i] + input[i];
        u8 *dest = &output->c[i * 4];
        dest[0] = (u8)(sum >> 0);
        dest[1] = (u8)(sum >> 8);
        dest[2] = (u8)(sum >> 16);
        dest[3] = (u8)(sum >> 24);
    }
}
