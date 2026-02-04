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
    uint8_t temp1[64], temp2[64], temp3[64], temp4[64];
    for (i = 0; i < 64; i++) {
        temp1[i] = sl->sl[2][1][i];
        temp2[i] = sl->sl[2][2][i];
        temp3[i] = sl->sl[2][4][i];
        temp4[i] = sl->sl[2][5][i];
    }
    for (i = 0; i < 64; i++) {
        sl->sl[3][1][i] = temp1[i];
        sl->sl[3][2][i] = temp2[i];
        sl->sl[3][4][i] = temp3[i];
        sl->sl[3][5][i] = temp4[i];
    }
}
