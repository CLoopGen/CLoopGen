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

extern EncBlockInfo *bi;
extern  int classes[];
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (max > classes[0]) {
        bi->cno = 0;
        for (;;) {
            bi->cno++;
            if (max <= classes[bi->cno]) break;
        }
    } else {
        bi->cno = 0;
    }
}
