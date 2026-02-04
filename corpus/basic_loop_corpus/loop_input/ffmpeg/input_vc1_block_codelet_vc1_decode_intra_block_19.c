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

static int16_t ac_val2_data[256 * 1024 * 1024 / sizeof(int16_t)]; 
int16_t *ac_val2 = ac_val2_data;

int q1 = 1;
int q2 = 1;
int k = 0;

void init_vars() {
    for (int i = 0; i < (int)(256 * 1024 * 1024 / sizeof(int16_t)); ++i) {
        ac_val2_data[i] = rand() % 1024 - 512;
    }
    q1 = 1 + rand() % 62;
    q2 = rand() % 100 + 1;
}