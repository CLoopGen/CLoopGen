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
for (i = 0; i < 40; i++) {
    int outer = i / 8;
    int inner = i % 8;
    if (inner == 0)
        min_qlevel[outer] = 1;
    if (blks[i].min_qlevel > min_qlevel[outer])
        min_qlevel[outer] = blks[i].min_qlevel;
}
}
