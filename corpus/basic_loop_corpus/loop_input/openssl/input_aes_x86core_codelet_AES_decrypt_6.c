#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef unsigned int u32;

u32 *rk;
u32 t[4];
int i;
u32 tp1;
u32 tp2;
u32 tp4;
u32 tp8;
u32 tp9;
u32 tpb;
u32 tpd;
u32 tpe;
u32 m;

void init_vars() {
    const size_t data_size = 1024 * 256; // 256KB of data to target ~0.01 sec runtime
    rk = (u32*)aligned_alloc(16, data_size);
    if (!rk) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize rk with non-zero predictable pattern
    for (size_t j = 0; j < (data_size / sizeof(u32)); ++j) {
        rk[j] = (u32)(j * 0x9E3779B9U + 0xC7C7C7C7U);
    }

    // Initialize t with known values to ensure defined behavior
    t[0] = 0x636F6D70U;
    t[1] = 0x75746572U;
    t[2] = 0x64617461U;
    t[3] = 0x776F726BU;

    // Initialize scalar temporaries to zero (they are overwritten in loop anyway)
    tp1 = tp2 = tp4 = tp8 = tp9 = tpb = tpd = tpe = m = 0;
    i = 0;
}