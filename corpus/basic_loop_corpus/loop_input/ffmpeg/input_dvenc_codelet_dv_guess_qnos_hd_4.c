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

EncBlockInfo *blks;
int min_qlevel[5];
int i;
int j;

void init_vars() {
    const int num_blks = 40; // 5 * 8 = 40 blocks needed for 5 outer iterations with 8 inner each
    blks = (EncBlockInfo*)aligned_alloc(64, num_blks * sizeof(EncBlockInfo));
    if (!blks) exit(1);

    for (int idx = 0; idx < num_blks; idx++) {
        blks[idx].min_qlevel = (idx % 7) + 1; // values from 1 to 7
    }

    for (int k = 0; k < 5; k++) {
        min_qlevel[k] = 0;
    }
    i = 0;
    j = 0;
}