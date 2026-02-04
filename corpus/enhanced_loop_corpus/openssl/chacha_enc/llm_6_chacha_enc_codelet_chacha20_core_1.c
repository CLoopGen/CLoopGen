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
    u32 temp[16];
    for (i = 0; i < 16; ++i) {
        temp[i] = x[i] + input[i];
    }
    for (i = 0; i < 16; ++i) {
        output->u[i] = temp[i];
    }
}
