#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const uint8_t ff_dv_quant_shifts[22][4] = {
    {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4},
    {5, 5, 5, 5}, {6, 6, 6, 6}, {7, 7, 7, 7}, {8, 8, 8, 8},
    {9, 9, 9, 9}, {10, 10, 10, 10}, {11, 11, 11, 11}, {12, 12, 12, 12},
    {13, 13, 13, 13}, {14, 14, 14, 14}, {15, 15, 15, 15}, {16, 16, 16, 16},
    {17, 17, 17, 17}, {18, 18, 18, 18}, {19, 19, 19, 19}, {20, 20, 20, 20},
    {21, 21, 21, 21}, {22, 22, 22, 22}
};

uint16_t dv_iweight_248[64];
uint8_t dv_quant_areas[4] = {16, 16, 16, 16};

uint32_t *factor1;
uint32_t *factor2;

int j;
int i;
int c;
int s;

uint16_t *iweight1;

void init_vars() {
    size_t total_size = 16 * 1024 * 1024; // ~16MB to target ~0.01s runtime
    size_t num_elements = total_size / sizeof(uint32_t);
    uint32_t *buffer = (uint32_t *)calloc(num_elements, sizeof(uint32_t));
    if (!buffer) exit(1);

    factor1 = buffer;
    factor2 = buffer + 1;

    for (int idx = 0; idx < 64; idx++) {
        dv_iweight_248[idx] = (uint16_t)(idx * 10 + 1);
    }

    i = 0;
    j = 0;
    c = 0;
    s = 0;
    iweight1 = &dv_iweight_248[0];
}