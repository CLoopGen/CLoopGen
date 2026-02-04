#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const int32_t ff_vc1_dqscale[63] = {
    8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
    24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55,
    56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70
};

static int16_t *ac_val2_data;
int16_t *ac_val2;
int q1 = 10;
int q2 = 256;
int k;

void init_vars() {
    size_t data_size = 16 * 1024 * 1024; // ~32 MB of int16_t data to ensure sufficient runtime
    ac_val2_data = (int16_t*)calloc(data_size, sizeof(int16_t));
    if (!ac_val2_data) {
        exit(1);
    }
    for (size_t i = 0; i < data_size; i++) {
        ac_val2_data[i] = (int16_t)(i % 512);
    }
    ac_val2 = ac_val2_data;
    q1 = 10;
    q2 = 256;
}