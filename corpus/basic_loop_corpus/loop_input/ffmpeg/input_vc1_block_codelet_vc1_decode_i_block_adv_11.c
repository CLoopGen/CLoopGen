#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const int32_t ff_vc1_dqscale[63] = {
    8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
    18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
    28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
    38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
    58, 59, 60, 61, 62, 63, 64, 65, 66, 67,
    68, 69, 70
};

static int16_t *ac_val2_internal;
int16_t *ac_val2;
int q1 = 10;
int q2 = 5;
int k;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256MB of total data
    const size_t num_elements = data_size / sizeof(int16_t);
    
    ac_val2_internal = (int16_t*)aligned_alloc(32, num_elements * sizeof(int16_t));
    if (!ac_val2_internal) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < num_elements; i++) {
        ac_val2_internal[i] = (int16_t)(i % 32768);
    }

    ac_val2 = ac_val2_internal;

    q1 = 10;
    q2 = 5;
}