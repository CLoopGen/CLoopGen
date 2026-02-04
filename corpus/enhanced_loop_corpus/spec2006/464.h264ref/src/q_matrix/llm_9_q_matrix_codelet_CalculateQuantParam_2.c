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
extern const int quant_coef[6][4][4];
extern const int dequant_coef[6][4][4];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 3; k++)
    for (j = 0; j < 8; j++)
        for (i = 0; i < 8; i++) {
            int idx_i = i % 4;
            int idx_j = j % 4;
            int factor = (dequant_coef[k][idx_j][idx_i] + 1) << 2;
            LevelScale4x4Luma_Intra[k][idx_j][idx_i] = quant_coef[k][idx_j][idx_i] * 2;
            InvLevelScale4x4Luma_Intra[k][idx_j][idx_i] = factor;
            if (j < 4 && i < 4) {
                LevelScale4x4Chroma_Intra[0][k][j][i] = quant_coef[k][j][i] * 2;
                InvLevelScale4x4Chroma_Intra[0][k][j][i] = (dequant_coef[k][j][i] + 1) << 2;
                LevelScale4x4Luma_Inter[k][j][i] = quant_coef[k][j][i] * 2;
                InvLevelScale4x4Luma_Inter[k][j][i] = (dequant_coef[k][j][i] + 1) << 2;
            }
            if (k == 0 && j < 4 && i < 4) {
                LevelScale4x4Chroma_Intra[1][j][i][k] = quant_coef[j][i][k] * 2;
                InvLevelScale4x4Chroma_Intra[1][j][i][k] = (dequant_coef[j][i][k] + 1) << 2;
            }
        }
}
