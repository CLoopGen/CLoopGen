#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *sao_offset_val;
int sao_left_class;
int offset_table[32];
int k;

void init_vars() {
    sao_offset_val = (int16_t*)aligned_alloc(32, 8 * sizeof(int16_t));
    if (!sao_offset_val) exit(1);
    for (int i = 0; i < 8; i++) {
        sao_offset_val[i] = (int16_t)(i * 10 + 1);
    }
    sao_left_class = 5;
    for (int i = 0; i < 32; i++) {
        offset_table[i] = 0;
    }
    k = 0;
}