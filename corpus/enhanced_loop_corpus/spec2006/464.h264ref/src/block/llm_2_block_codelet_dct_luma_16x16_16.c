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
    for (j = 0; j < 4; j++)
        M5[j] = M4[i][j];
    M6[0] = M5[0] + M5[2];
    M6[1] = M5[0] - M5[2];
    M6[2] = M5[1] - M5[3];
    M6[3] = M5[1] + M5[3];
    for (j = 0; j < 2; j++) {
        j1 = 3 - j;
        if (qp_per < 6) {
            int temp_sum = M6[j] + M6[j1];
            int temp_diff = M6[j] - M6[j1];
            int scale = InvLevelScale4x4Luma_Intra[qp_rem][0][0];
            int shift_val = 6 - qp_per;
            int round_term = 1 << (5 - qp_per);
            M0[0][i][0][j] = (temp_sum * scale + round_term) >> shift_val;
            M0[0][i][0][j1] = (temp_diff * scale + round_term) >> shift_val;
        } else {
            int temp_sum = M6[j] + M6[j1];
            int temp_diff = M6[j] - M6[j1];
            int scale = InvLevelScale4x4Luma_Intra[qp_rem][0][0];
            int shift_val = qp_per - 6;
            M0[0][i][0][j] = (temp_sum * scale) << shift_val;
            M0[0][i][0][j1] = (temp_diff * scale) << shift_val;
        }
    }
}
}
