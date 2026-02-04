#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct ScalingList {
    uint8_t sl[4][6][64];
    uint8_t sl_dc[2][6];
} ScalingList;

extern ScalingList *sl;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        uint8_t temp1 = sl->sl[2][1][i] + 1;
        uint8_t temp2 = sl->sl[2][2][i] + 1;
        uint8_t temp4 = sl->sl[2][4][i] + 1;
        uint8_t temp5 = sl->sl[2][5][i] + 1;
        sl->sl[3][1][i] = temp1 - 1;
        sl->sl[3][2][i] = temp2 - 1;
        sl->sl[3][4][i] = temp4 - 1;
        sl->sl[3][5][i] = temp5 - 1;
    }
}
