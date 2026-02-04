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

extern EncBlockInfo *blks;
extern int min_qlevel[5];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 5; i++) {
    min_qlevel[i] = 1;
    for (j = 0; j < 8; j++) {
        int current_min = blks[8 * i + j].min_qlevel;
        if (current_min > min_qlevel[i]) {
            min_qlevel[i] = current_min;
        } else {
            continue;
        }
    }
}
}
