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
int M6_local[4][4]; // Introduce loop-carried dependency via aggregation
for (i = 0; i < 4 && !lossless_qpprime; i++) {
    for (j = 0; j < 4; j++) {
        M5[j] = M4[i][j];
    }
    M6_local[i][0] = M5[0] + M5[2];
    M6_local[i][1] = M5[0] - M5[2];
    M6_local[i][2] = M5[1] - M5[3];
    M6_local[i][3] = M5[1] + M5[3];
}
// Second loop introduces loop-carried dependence: uses results from all iterations
for (i = 0; i < 4 && !lossless_qpprime; i++) {
    for (j = 0; j < 2; j++) {
        j1 = 3 - j;
        int combined_M6_0 = 0, combined_M6_1 = 0;
        // Aggregate across all previous i (introduce artificial loop-carried RAW)
        for (int k = 0; k <= i; k++) {
            combined_M6_0 += M6_local[k][j];
            combined_M6_1 += M6_local[k][j1];
        }
        if (qp_per < 6) {
            M0[0][i][0][j] = ((combined_M6_0 + combined_M6_1) * InvLevelScale4x4Luma_Intra[qp_rem][0][0] + (1 << (5 - qp_per))) >> (6 - qp_per);
            M0[0][i][0][j1] = ((combined_M6_0 - combined_M6_1) * InvLevelScale4x4Luma_Intra[qp_rem][0][0] + (1 << (5 - qp_per))) >> (6 - qp_per);
        } else {
            M0[0][i][0][j] = ((combined_M6_0 + combined_M6_1) * InvLevelScale4x4Luma_Intra[qp_rem][0][0]) << (qp_per - 6);
            M0[0][i][0][j1] = ((combined_M6_0 - combined_M6_1) * InvLevelScale4x4Luma_Intra[qp_rem][0][0]) << (qp_per - 6);
        }
    }
}
}
