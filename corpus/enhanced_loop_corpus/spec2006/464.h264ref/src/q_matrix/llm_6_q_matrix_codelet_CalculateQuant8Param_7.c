#include <stdio.h>

#include <inttypes.h>

extern int LevelScale8x8Luma_Intra[6][8][8];
extern int LevelScale8x8Luma_Inter[6][8][8];
extern int InvLevelScale8x8Luma_Intra[6][8][8];
extern int InvLevelScale8x8Luma_Inter[6][8][8];
extern short ScalingList8x8[2][64];
extern short UseDefaultScalingMatrix8x8Flag[2];
extern const int quant_coef8[6][8][8];
extern const int dequant_coef8[6][8][8];
extern  short Quant8_intra_default[64];
extern  short Quant8_inter_default[64];
extern int i;
extern int j;
extern int k;
extern int temp;
extern int present[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 6; k++)
    for (j = 0; j < 8; j++)
        for (i = 0; i < 8; i++) {
            temp = (i << 3) + j;
            // Introduce artificial loop-carried dependency via reuse of previous iteration's result
            if (k > 0 || j > 0 || i > 0) {
                int prev_val = LevelScale8x8Luma_Intra[k][j][(i+7)%8];
                LevelScale8x8Luma_Intra[k][j][i] = ((quant_coef8[k][j][i] << 4) / (Quant8_intra_default[temp] + prev_val)) + 1;
            } else {
                LevelScale8x8Luma_Intra[k][j][i] = (quant_coef8[k][j][i] << 4) / Quant8_intra_default[temp];
            }
            if ((!present[0]) || UseDefaultScalingMatrix8x8Flag[0]) {
                InvLevelScale8x8Luma_Intra[k][j][i] = dequant_coef8[k][j][i] * Quant8_intra_default[temp];
            } else {
                InvLevelScale8x8Luma_Intra[k][j][i] = dequant_coef8[k][j][i] * ScalingList8x8[0][temp];
            }
            if ((!present[1]) || UseDefaultScalingMatrix8x8Flag[1]) {
                LevelScale8x8Luma_Inter[k][j][i] = (quant_coef8[k][j][i] << 4) / Quant8_inter_default[temp];
                InvLevelScale8x8Luma_Inter[k][j][i] = dequant_coef8[k][j][i] * Quant8_inter_default[temp];
            } else {
                LevelScale8x8Luma_Inter[k][j][i] = (quant_coef8[k][j][i] << 4) / ScalingList8x8[1][temp];
                InvLevelScale8x8Luma_Inter[k][j][i] = dequant_coef8[k][j][i] * ScalingList8x8[1][temp];
            }
        }
}
