#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint8_t *data[4];
int size[4];

static uint8_t *allocated_data[4];

void init_vars() {
    const size_t total_size = 64 << 20; // 64 MB to target ~0.01 sec runtime

    for (int idx = 0; idx < 4; idx++) {
        allocated_data[idx] = (uint8_t *)calloc(total_size, sizeof(uint8_t));
        if (!allocated_data[idx]) {
            exit(1);
        }
        data[idx] = allocated_data[idx];
    }

    // Ensure data[3] is NULL to satisfy loop condition: i < 3 && data[i + 1]
    data[3] = NULL;

    // Initialize sizes safely: only compute for i=0 and i=1 since i<3 and data[i+1] must be non-null
    // But we set data[1] and data[2] as valid, data[3] as NULL so loop stops at i=2
    // So for i=0: size[0] = data[1]-data[0]
    //     for i=1: size[1] = data[2]-data[1]
    //     for i=2: data[3] is NULL -> loop exits without writing size[2]
    // Therefore, ensure data pointers are ordered
    data[0] = allocated_data[0];
    data[1] = allocated_data[1];
    data[2] = allocated_data[2];
    data[3] = NULL;

    i = 0;
}