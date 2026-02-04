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

EncBlockInfo *bi;
int classes[1000000];  // Large enough to control loop duration
int max;

void init_vars() {
    bi = (EncBlockInfo *)calloc(1, sizeof(EncBlockInfo));
    if (!bi) exit(1);

    bi->cno = 0;
    bi->cur_ac = 0;
    bi->dct_mode = 0;
    bi->partial_bit_count = 0;
    bi->partial_bit_buffer = 0;
    bi->min_qlevel = 0;

    for (int i = 0; i < 4; i++) {
        bi->area_q[i] = 0;
        bi->bit_size[i] = 0;
    }
    for (int i = 0; i < 5; i++) {
        bi->prev[i] = 0;
    }
    for (int i = 0; i < 64; i++) {
        bi->mb[i] = 0;
        bi->next[i] = 0;
        bi->sign[i] = 0;
        bi->save[i] = 0;
    }

    max = 999990;

    for (int i = 0; i < 1000000; i++) {
        classes[i] = i;
    }
}