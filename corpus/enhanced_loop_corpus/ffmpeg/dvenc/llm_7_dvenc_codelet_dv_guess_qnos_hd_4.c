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
        int local_max = min_qlevel[i];
        for (j = 7; j >= 0; j--) {
            int current_val = blks[8 * i + j].min_qlevel;
            if (current_val > local_max) {
                local_max = current_val;
            }
        }
        min_qlevel[i] = local_max;
    }
}
