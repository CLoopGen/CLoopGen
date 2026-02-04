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

                // Eliminate all conditional branching by precomputing effective scaling factors
                int scale_intra_luma = (!present[0] || UseDefaultScalingMatrix4x4Flag[0]) ? Quant_intra_default[temp] : ScalingList4x4[0][temp];
                int scale_chroma_intra_0 = !present[1] ? scale_intra_luma : (UseDefaultScalingMatrix4x4Flag[1] ? Quant_intra_default[temp] : ScalingList4x4[1][temp]);
                int scale_chroma_intra_1 = !present[2] ? scale_chroma_intra_0 : (UseDefaultScalingMatrix4x4Flag[2] ? Quant_intra_default[temp] : ScalingList4x4[2][temp]);

                int scale_inter_luma = (!present[3] || UseDefaultScalingMatrix4x4Flag[3]) ? Quant_inter_default[temp] : ScalingList4x4[3][temp];
                int scale_chroma_inter_0 = !present[4] ? scale_inter_luma : (UseDefaultScalingMatrix4x4Flag[4] ? Quant_inter_default[temp] : ScalingList4x4[4][temp]);
                int scale_chroma_inter_1 = !present[5] ? scale_chroma_inter_0 : (UseDefaultScalingMatrix4x4Flag[5] ? Quant_inter_default[temp] : ScalingList4x4[5][temp]);

                // All assignments now use direct computation without branching inside
                LevelScale4x4Luma_Intra[k][j][i] = (quant_coef[k][j][i] << 4) / scale_intra_luma;
                InvLevelScale4x4Luma_Intra[k][j][i] = dequant_coef[k][j][i] * scale_intra_luma;

                LevelScale4x4Chroma_Intra[0][k][j][i] = (quant_coef[k][j][i] << 4) / scale_chroma_intra_0;
                InvLevelScale4x4Chroma_Intra[0][k][j][i] = dequant_coef[k][j][i] * scale_chroma_intra_0;

                LevelScale4x4Chroma_Intra[1][k][j][i] = (quant_coef[k][j][i] << 4) / scale_chroma_intra_1;
                InvLevelScale4x4Chroma_Intra[1][k][j][i] = dequant_coef[k][j][i] * scale_chroma_intra_1;

                LevelScale4x4Luma_Inter[k][j][i] = (quant_coef[k][j][i] << 4) / scale_inter_luma;
                InvLevelScale4x4Luma_Inter[k][j][i] = dequant_coef[k][j][i] * scale_inter_luma;

                LevelScale4x4Chroma_Inter[0][k][j][i] = (quant_coef[k][j][i] << 4) / scale_chroma_inter_0;
                InvLevelScale4x4Chroma_Inter[0][k][j][i] = dequant_coef[k][j][i] * scale_chroma_inter_0;

                LevelScale4x4Chroma_Inter[1][k][j][i] = (quant_coef[k][j][i] << 4) / scale_chroma_inter_1;
                InvLevelScale4x4Chroma_Inter[1][k][j][i] = dequant_coef[k][j][i] * scale_chroma_inter_1;
            }
}
