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
for (k = 0; k < 6; k++) {
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            temp = (i << 3) + j;
            int q_coef = quant_coef8[k][j][i];
            int dq_coef = dequant_coef8[k][j][i];
            int shift_val = 4;

            // Reduce redundant calculations by precomputing condition results
            int use_default_intra = (!present[0]) || UseDefaultScalingMatrix8x8Flag[0];
            int use_default_inter = (!present[1]) || UseDefaultScalingMatrix8x8Flag[1];

            short scale_intra = use_default_intra ? Quant8_intra_default[temp] : ScalingList8x8[0][temp];
            short scale_inter = use_default_inter ? Quant8_inter_default[temp] : ScalingList8x8[1][temp];

            LevelScale8x8Luma_Intra[k][j][i] = (q_coef << shift_val) / scale_intra;
            InvLevelScale8x8Luma_Intra[k][j][i] = dq_coef * scale_intra;

            LevelScale8x8Luma_Inter[k][j][i] = (q_coef << shift_val) / scale_inter;
            InvLevelScale8x8Luma_Inter[k][j][i] = dq_coef * scale_inter;
        }
    }
}
}
