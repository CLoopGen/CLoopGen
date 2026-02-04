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
    for (bi->cno = 0; bi->cno < max; bi->cno++) {
        if (classes[bi->cno] >= max) {
            break;
        }
        bi->prev[bi->cno % 5] = bi->cno; // Introduce WAW dependency on prev and loop-carried dependency via index mod
        bi->area_q[bi->cno % 4] += bi->bit_size[bi->cno % 4]; // RAW dependency: use bit_size before update to area_q
    }
}
