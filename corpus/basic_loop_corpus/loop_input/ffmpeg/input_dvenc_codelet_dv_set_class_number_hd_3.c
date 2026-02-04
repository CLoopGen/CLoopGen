#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct EncBlockInfo {
    int area_q[4];
    int bit_size[4];
    int prev[5];
    int cur_ac;
    int cno;
    int dct_mode;
    int16_t mb[64];
    uint8_t next[64];
    uint8_t sign[64];
    uint8_t partial_bit_count;
    uint32_t partial_bit_buffer;
    int16_t save[64];
    int min_qlevel;
} EncBlockInfo;

int16_t *blk;
EncBlockInfo *bi;
uint8_t *zigzag_scan;
int *weight;
int i;
int max;

void init_vars() {
    blk = (int16_t*)aligned_alloc(16, sizeof(int16_t) * 64);
    zigzag_scan = (uint8_t*)aligned_alloc(16, sizeof(uint8_t) * 64);
    weight = (int*)aligned_alloc(16, sizeof(int) * 64);
    bi = (EncBlockInfo*)aligned_alloc(16, sizeof(EncBlockInfo));

    for (int idx = 0; idx < 64; idx++) {
        blk[idx] = (int16_t)(idx * 7 - 128);
        zigzag_scan[idx] = (uint8_t)(idx);
        weight[idx] = 1 << 10;
    }

    for (int idx = 0; idx < 64; idx++) {
        bi->sign[idx] = 0;
        bi->save[idx] = 0;
    }

    max = 0;
}