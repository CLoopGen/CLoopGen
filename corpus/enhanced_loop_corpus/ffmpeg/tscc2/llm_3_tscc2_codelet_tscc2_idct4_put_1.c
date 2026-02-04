#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int i;
extern int tblk[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using index mapping array
    static const int index_map[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; // identity map for clarity
    for (i = 0; i < 4; i++) {
        int idx0 = index_map[i * 4 + 0];
        int idx1 = index_map[i * 4 + 1];
        int idx2 = index_map[i * 4 + 2];
        int idx3 = index_map[i * 4 + 3];
        dst[0] = ((5 * (tblk[idx0] + tblk[idx1] + tblk[idx2]) + 2 * tblk[idx3]) + 32) >> 6;
        dst[1] = ((5 * (tblk[idx0] - tblk[idx2] - tblk[idx3]) + 2 * tblk[idx1]) + 32) >> 6;
        dst[2] = ((5 * (tblk[idx0] - tblk[idx2] + tblk[idx3]) - 2 * tblk[idx1]) + 32) >> 6;
        dst[3] = ((5 * (tblk[idx0] - tblk[idx1] + tblk[idx2]) - 2 * tblk[idx3]) + 32) >> 6;
        dst += stride;
    }
}
