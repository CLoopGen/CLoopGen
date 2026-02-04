#include <stdio.h>
#include <inttypes.h>

typedef unsigned int u32;
typedef unsigned char u8;

typedef union {
    u32 u[16];
    u8 c[64];
} chacha_buf;

chacha_buf *output;
u32 input[16];
u32 x[16];
int i;

void init_vars() {
    static chacha_buf output_buf;
    output = &output_buf;

    for (int j = 0; j < 16; ++j) {
        input[j] = j * 0x1234567U;
        x[j] = j * 0x9876543U;
    }
}