#include <stdio.h>
#include <inttypes.h>

int LevelScale4x4Luma_Intra[6][4][4];
int LevelScale4x4Chroma_Intra[2][6][4][4];
int LevelScale4x4Luma_Inter[6][4][4];
int LevelScale4x4Chroma_Inter[2][6][4][4];
int InvLevelScale4x4Luma_Intra[6][4][4];
int InvLevelScale4x4Chroma_Intra[2][6][4][4];
int InvLevelScale4x4Luma_Inter[6][4][4];
int InvLevelScale4x4Chroma_Inter[2][6][4][4];
short ScalingList4x4[6][16];
short UseDefaultScalingMatrix4x4Flag[6];
const int quant_coef[6][4][4] = {
    { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} },
    { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} },
    { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} },
    { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} },
    { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} },
    { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} }
};
const int dequant_coef[6][4][4] = {
    { {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1} },
    { {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1} },
    { {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1} },
    { {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1} },
    { {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1} },
    { {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1} }
};
short Quant_intra_default[16] = {
    16, 16, 16, 16,
    16, 16, 16, 16,
    16, 16, 16, 16,
    16, 16, 16, 16
};
short Quant_inter_default[16] = {
    16, 16, 16, 16,
    16, 16, 16, 16,
    16, 16, 16, 16,
    16, 16, 16, 16
};
int i;
int j;
int k;
int temp;
int present[6];

void init_vars() {
    for (int idx = 0; idx < 6; idx++) {
        UseDefaultScalingMatrix4x4Flag[idx] = 0;
        present[idx] = 1;
        for (int idy = 0; idy < 16; idy++) {
            ScalingList4x4[idx][idy] = 16;
        }
    }
    present[0] = 0;
    present[3] = 0;
    UseDefaultScalingMatrix4x4Flag[1] = 1;
    UseDefaultScalingMatrix4x4Flag[4] = 1;
}