#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct ScalingList {
    uint8_t sl[4][6][64];
    uint8_t sl_dc[2][6];
} ScalingList;

ScalingList *sl;
int i;

void init_vars() {
    sl = (ScalingList*)calloc(1, sizeof(ScalingList));
    if (!sl) {
        exit(1);
    }
    
    for (int idx0 = 0; idx0 < 4; idx0++) {
        for (int idx1 = 0; idx1 < 6; idx1++) {
            for (int idx2 = 0; idx2 < 64; idx2++) {
                sl->sl[idx0][idx1][idx2] = (uint8_t)(idx0 * 6 * 64 + idx1 * 64 + idx2);
            }
        }
    }
    
    for (int idx0 = 0; idx0 < 2; idx0++) {
        for (int idx1 = 0; idx1 < 6; idx1++) {
            sl->sl_dc[idx0][idx1] = (uint8_t)(idx0 * 6 + idx1);
        }
    }
}