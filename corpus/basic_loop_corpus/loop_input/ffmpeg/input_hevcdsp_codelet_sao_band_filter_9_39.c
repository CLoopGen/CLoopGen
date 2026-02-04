#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *sao_offset_val;
int sao_left_class;
int offset_table[32];
int k;

void init_vars() {
    sao_offset_val = (int16_t*)aligned_alloc(32, 1024 * 1024);
    if (!sao_offset_val) exit(1);
    for (int i = 0; i < (1024 * 1024) / sizeof(int16_t); i++) {
        sao_offset_val[i] = (int16_t)(i & 0x7FFF);
    }
    sao_left_class = 16;
}