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
    // Variant 1: Strided memory access pattern
    // Instead of sequential increment, we step through classes with a stride of 2
    // and adjust loop condition accordingly to stay within bounds.
    int stride = 2;
    bi->cno = 0;
    for (; bi->cno < 32 && max > classes[bi->cno]; bi->cno += stride) {
        // Empty body - original logic is in the loop condition and increment
    }
    // Ensure cno is not beyond valid index range; if needed, revert to last valid
    if (bi->cno >= 32 || max <= classes[bi->cno]) {
        bi->cno -= (bi->cno > 0 ? 1 : 0);
    }
}
