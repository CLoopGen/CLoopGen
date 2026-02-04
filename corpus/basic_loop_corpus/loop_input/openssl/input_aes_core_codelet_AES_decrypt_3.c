#include <stdint.h>
#include <string.h>

typedef unsigned int u32;

u32 Td0[256];
u32 Td1[256];
u32 Td2[256];
u32 Td3[256];

static u32 rk_data[32768];  // Large enough to support many rounds and rk += 8 steps
u32 *rk = rk_data;

u32 s0 = 0x12345678;
u32 s1 = 0x9abcdef0;
u32 s2 = 0xfedcba98;
u32 s3 = 0x76543210;

u32 t0, t1, t2, t3;

int r = 4096;  // Number of iterations to achieve ~0.01 sec runtime

void init_vars() {
    for (int i = 0; i < 256; ++i) {
        Td0[i] = ((u32)i << 24) ^ 0x1010101;
        Td1[i] = ((u32)i << 16) ^ 0x2020202;
        Td2[i] = ((u32)i <<  8) ^ 0x3030303;
        Td3[i] = ((u32)i      ) ^ 0x4040404;
    }

    for (int i = 0; i < 32768; ++i) {
        rk_data[i] = 0xdeadbeef ^ i * 0x9e3779b9;
    }
}