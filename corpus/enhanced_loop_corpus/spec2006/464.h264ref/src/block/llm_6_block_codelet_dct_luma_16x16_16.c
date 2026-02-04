#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern int InvLevelScale4x4Luma_Intra[6][4][4];
extern int i;
extern int j;
extern int _usr_j1;
extern int M4[4][4];
extern int M5[4];
extern int M6[4];
extern int M0[4][4][4][4];
extern int qp_per;
extern int qp_rem;
extern Boolean lossless_qpprime;

// Variable name mappings to avoid conflicts with system symbols
#define j1 _usr_j1



void loop(){
for (i = 0; i < 4 && !lossless_qpprime; i++) {
    int temp_M5[4];
    for (j = 0; j < 4; j++) {
        temp_M5[j] = M4[i][j]; // Eliminate WAW on M5 by using temporary
    }
    int temp_M6[4];
    temp_M6[0] = temp_M5[0] + temp_M5[2];
    temp_M6[1] = temp_M5[0] - temp_M5[2];
    temp_M6[2] = temp_M5[1] - temp_M5[3];
    temp_M6[3] = temp_M5[1] + temp_M5[3];
    for (j = 0; j < 2; j++) {
        j1 = 3 - j;
        int val1 = temp_M6[j] + temp_M6[j1];
        int val2 = temp_M6[j] - temp_M6[j1];
        if (qp_per < 6) {
            M0[0][i][0][j] = (val1 * InvLevelScale4x4Luma_Intra[qp_rem][0][0] + (1 << (5 - qp_per))) >> (6 - qp_per);
            M0[0][i][0][j1] = (val2 * InvLevelScale4x4Luma_Intra[qp_rem][0][0] + (1 << (5 - qp_per))) >> (6 - qp_per);
        } else {
            M0[0][i][0][j] = (val1 * InvLevelScale4x4Luma_Intra[qp_rem][0][0]) << (qp_per - 6);
            M0[0][i][0][j1] = (val2 * InvLevelScale4x4Luma_Intra[qp_rem][0][0]) << (qp_per - 6);
        }
    }
}
}
