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
            int cond_luma_intra = (!present[0]) || UseDefaultScalingMatrix4x4Flag[0];
            int div_luma_intra = cond_luma_intra ? Quant_intra_default[temp] : ScalingList4x4[0][temp];
            LevelScale4x4Luma_Intra[k][j][i] = (quant_coef[k][j][i] << 4) / div_luma_intra;
            InvLevelScale4x4Luma_Intra[k][j][i] = dequant_coef[k][j][i] * div_luma_intra;

            int use_chroma_intra_0 = !present[1];
            if (use_chroma_intra_0) {
                LevelScale4x4Chroma_Intra[0][k][j][i] = LevelScale4x4Luma_Intra[k][j][i];
                InvLevelScale4x4Chroma_Intra[0][k][j][i] = InvLevelScale4x4Luma_Intra[k][j][i];
            } else {
                int div_chroma_intra_0 = UseDefaultScalingMatrix4x4Flag[1] ? Quant_intra_default[temp] : ScalingList4x4[1][temp];
                LevelScale4x4Chroma_Intra[0][k][j][i] = (quant_coef[k][j][i] << 4) / div_chroma_intra_0;
                InvLevelScale4x4Chroma_Intra[0][k][j][i] = dequant_coef[k][j][i] * div_chroma_intra_0;
            }

            int use_chroma_intra_1 = !present[2];
            if (use_chroma_intra_1) {
                LevelScale4x4Chroma_Intra[1][k][j][i] = LevelScale4x4Chroma_Intra[0][k][j][i];
                InvLevelScale4x4Chroma_Intra[1][k][j][i] = InvLevelScale4x4Chroma_Intra[0][k][j][i];
            } else {
                int div_chroma_intra_1 = UseDefaultScalingMatrix4x4Flag[2] ? Quant_intra_default[temp] : ScalingList4x4[2][temp];
                LevelScale4x4Chroma_Intra[1][k][j][i] = (quant_coef[k][j][i] << 4) / div_chroma_intra_1;
                InvLevelScale4x4Chroma_Intra[1][k][j][i] = dequant_coef[k][j][i] * div_chroma_intra_1;
            }

            int cond_luma_inter = (!present[3]) || UseDefaultScalingMatrix4x4Flag[3];
            int div_luma_inter = cond_luma_inter ? Quant_inter_default[temp] : ScalingList4x4[3][temp];
            LevelScale4x4Luma_Inter[k][j][i] = (quant_coef[k][j][i] << 4) / div_luma_inter;
            InvLevelScale4x4Luma_Inter[k][j][i] = dequant_coef[k][j][i] * div_luma_inter;

            int use_chroma_inter_0 = !present[4];
            if (use_chroma_inter_0) {
                LevelScale4x4Chroma_Inter[0][k][j][i] = LevelScale4x4Luma_Inter[k][j][i];
                InvLevelScale4x4Chroma_Inter[0][k][j][i] = InvLevelScale4x4Luma_Inter[k][j][i];
            } else {
                int div_chroma_inter_0 = UseDefaultScalingMatrix4x4Flag[4] ? Quant_inter_default[temp] : ScalingList4x4[4][temp];
                LevelScale4x4Chroma_Inter[0][k][j][i] = (quant_coef[k][j][i] << 4) / div_chroma_inter_0;
                InvLevelScale4x4Chroma_Inter[0][k][j][i] = dequant_coef[k][j][i] * div_chroma_inter_0;
            }

            int use_chroma_inter_1 = !present[5];
            if (use_chroma_inter_1) {
                LevelScale4x4Chroma_Inter[1][k][j][i] = LevelScale4x4Chroma_Inter[0][k][j][i];
                InvLevelScale4x4Chroma_Inter[1][k][j][i] = InvLevelScale4x4Chroma_Inter[0][k][j][i];
            } else {
                int div_chroma_inter_1 = UseDefaultScalingMatrix4x4Flag[5] ? Quant_inter_default[temp] : ScalingList4x4[5][temp];
                LevelScale4x4Chroma_Inter[1][k][j][i] = (quant_coef[k][j][i] << 4) / div_chroma_inter_1;
                InvLevelScale4x4Chroma_Inter[1][k][j][i] = dequant_coef[k][j][i] * div_chroma_inter_1;
            }
        }
}
