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
        u32 sum = x[i] + input[i];
        if ((sum & 1) == 0) {  // Only process if sum is even
            (output->c + 4 * i)[0] = (u8)(sum >> 0);
            (output->c + 4 * i)[1] = (u8)(sum >> 8);
            (output->c + 4 * i)[2] = (u8)(sum >> 16);
            (output->c + 4 * i)[3] = (u8)(sum >> 24);
        }
    }
}
