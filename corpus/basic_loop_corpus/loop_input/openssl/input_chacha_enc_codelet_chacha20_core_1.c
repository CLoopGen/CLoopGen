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

static chacha_buf output_buf;
static chacha_buf input_array[2048];
static chacha_buf x_array[2048];

void init_vars() {
    output = &output_buf;
    
    for (int idx = 0; idx < 16; ++idx) {
        input[idx] = idx * 0x12345678u + 0xCAFEBEEFu;
        x[idx] = idx * 0xABCDEF01u + 0xDEADBEEFu;
    }
    
    for (int idx = 0; idx < 2048; ++idx) {
        for (int j = 0; j < 16; ++j) {
            input_array[idx].u[j] = (idx + j) * 0x11223344u + 0xCAFEBABEu;
            x_array[idx].u[j] = (idx + j) * 0x55667788u + 0xDEADBEADu;
        }
    }
}