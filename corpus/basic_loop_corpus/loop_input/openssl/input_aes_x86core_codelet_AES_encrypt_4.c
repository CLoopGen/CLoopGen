#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef unsigned int u32;

u32 *rk;
u32 t[4];
int i;
u32 r0;
u32 r1;
u32 r2;

static u32 *rk_storage;

void init_vars() {
    const size_t data_size = 1024 * 256; // 256KB of input data
    rk_storage = (u32*)calloc((data_size / sizeof(u32)) + 8, sizeof(u32));
    if (!rk_storage) {
        exit(1);
    }

    rk = rk_storage + 4; // Allow rk[4+i] access with i from 0 to 3

    for (size_t idx = 0; idx < (data_size / sizeof(u32)); ++idx) {
        rk_storage[idx] = (u32)(idx * 0x9E3779B1U); 
    }

    t[0] = 0x12345678U;
    t[1] = 0x23456789U;
    t[2] = 0x3456789AU;
    t[3] = 0x456789ABU;

    r0 = 0;
    r1 = 0;
    r2 = 0;
    i = 0;
}