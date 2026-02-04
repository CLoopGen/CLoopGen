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
            // Eliminate nested conditionals by precomputing source values
            int* level_scale_intra = &LevelScale8x8Luma_Intra[k][j][i];
            int* inv_level_scale_intra = &InvLevelScale8x8Luma_Intra[k][j][i];
            int* level_scale_inter = &LevelScale8x8Luma_Inter[k][j][i];
            int* inv_level_scale_inter = &InvLevelScale8x8Luma_Inter[k][j][i];
            const int q_coef = quant_coef8[k][j][i];
            const int dq_coef = dequant_coef8[k][j][i];
            short scale_intra = (!present[0] || UseDefaultScalingMatrix8x8Flag[0]) ? 
                                Quant8_intra_default[temp] : ScalingList8x8[0][temp];
            short scale_inter = (!present[1] || UseDefaultScalingMatrix8x8Flag[1]) ? 
                                Quant8_inter_default[temp] : ScalingList8x8[1][temp];

            *level_scale_intra = (q_coef << 4) / scale_intra;
            *inv_level_scale_intra = dq_coef * scale_intra;
            *level_scale_inter = (q_coef << 4) / scale_inter;
            *inv_level_scale_inter = dq_coef * scale_inter;
        }

}
