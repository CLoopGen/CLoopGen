#include <stdio.h>

#include <inttypes.h>

extern int LevelScale4x4Luma_Intra[6][4][4];
extern int LevelScale4x4Chroma_Intra[2][6][4][4];
extern int LevelScale4x4Luma_Inter[6][4][4];
extern int LevelScale4x4Chroma_Inter[2][6][4][4];
extern int InvLevelScale4x4Luma_Intra[6][4][4];
extern int InvLevelScale4x4Chroma_Intra[2][6][4][4];
extern int InvLevelScale4x4Luma_Inter[6][4][4];
extern int InvLevelScale4x4Chroma_Inter[2][6][4][4];
extern short ScalingList4x4[6][16];
extern short UseDefaultScalingMatrix4x4Flag[6];
extern const int quant_coef[6][4][4];
extern const int dequant_coef[6][4][4];
extern  short Quant_intra_default[16];
extern  short Quant_inter_default[16];
extern int i;
extern int j;
extern int k;
extern int temp;
extern int present[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 6; k++)
    for (j = 0; j < 4; j++)
        for (i = 0; i < 4; i++) {
            temp = (i << 2) + j;
            int q_coef = quant_coef[k][j][i];
            int dq_coef = dequant_coef[k][j][i];
            int shift_val = 1 << 4;

            // Precompute divisors and multipliers to reduce redundant condition checks
            int luma_intra_div = UseDefaultScalingMatrix4x4Flag[0] ? Quant_intra_default[temp] : ScalingList4x4[0][temp];
            int chroma_intra_div_1 = UseDefaultScalingMatrix4x4Flag[1] ? Quant_intra_default[temp] : ScalingList4x4[1][temp];
            int chroma_intra_div_2 = UseDefaultScalingMatrix4x4Flag[2] ? Quant_intra_default[temp] : ScalingList4x4[2][temp];

            int luma_inter_div = UseDefaultScalingMatrix4x4Flag[3] ? Quant_inter_default[temp] : ScalingList4x4[3][temp];
            int chroma_inter_div_1 = UseDefaultScalingMatrix4x4Flag[4] ? Quant_inter_default[temp] : ScalingList4x4[4][temp];
            int chroma_inter_div_2 = UseDefaultScalingMatrix4x4Flag[5] ? Quant_inter_default[temp] : ScalingList4x4[5][temp];

            LevelScale4x4Luma_Intra[k][j][i] = (q_coef * shift_val) / (present[0] ? luma_intra_div : Quant_intra_default[temp]);
            InvLevelScale4x4Luma_Intra[k][j][i] = dq_coef * (present[0] ? luma_intra_div : Quant_intra_default[temp]);

            LevelScale4x4Chroma_Intra[0][k][j][i] = present[1] ? 
                (q_coef * shift_val) / chroma_intra_div_1 : LevelScale4x4Luma_Intra[k][j][i];
            InvLevelScale4x4Chroma_Intra[0][k][j][i] = present[1] ? 
                dq_coef * chroma_intra_div_1 : InvLevelScale4x4Luma_Intra[k][j][i];

            LevelScale4x4Chroma_Intra[1][k][j][i] = present[2] ? 
                (q_coef * shift_val) / chroma_intra_div_2 : LevelScale4x4Chroma_Intra[0][k][j][i];
            InvLevelScale4x4Chroma_Intra[1][k][j][i] = present[2] ? 
                dq_coef * chroma_intra_div_2 : InvLevelScale4x4Chroma_Intra[0][k][j][i];

            LevelScale4x4Luma_Inter[k][j][i] = (q_coef * shift_val) / (present[3] ? luma_inter_div : Quant_inter_default[temp]);
            InvLevelScale4x4Luma_Inter[k][j][i] = dq_coef * (present[3] ? luma_inter_div : Quant_inter_default[temp]);

            LevelScale4x4Chroma_Inter[0][k][j][i] = present[4] ? 
                (q_coef * shift_val) / chroma_inter_div_1 : LevelScale4x4Luma_Inter[k][j][i];
            InvLevelScale4x4Chroma_Inter[0][k][j][i] = present[4] ? 
                dq_coef * chroma_inter_div_1 : InvLevelScale4x4Luma_Inter[k][j][i];

            LevelScale4x4Chroma_Inter[1][k][j][i] = present[5] ? 
                (q_coef * shift_val) / chroma_inter_div_2 : LevelScale4x4Chroma_Inter[0][k][j][i];
            InvLevelScale4x4Chroma_Inter[1][k][j][i] = present[5] ? 
                dq_coef * chroma_inter_div_2 : InvLevelScale4x4Chroma_Inter[0][k][j][i];
        }
}
