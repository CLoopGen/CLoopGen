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
for (k = 0; k < 6; k++)
    for (j = 0; j < 4; j++)
        for (i = 0; i < 4; i++) {
            int idx = k * 16 + j * 4 + i;
            for (int c = 0; c < 2; c++) {
                LevelScale4x4Luma_Intra[k][j][i] = quant_coef[k][j][i];
                InvLevelScale4x4Luma_Intra[k][j][i] = dequant_coef[k][j][i] << 4;
                LevelScale4x4Chroma_Intra[c][k][j][i] = quant_coef[k][j][i];
                InvLevelScale4x4Chroma_Intra[c][k][j][i] = dequant_coef[k][j][i] << 4;
                LevelScale4x4Luma_Inter[k][j][i] = quant_coef[k][j][i];
                InvLevelScale4x4Luma_Inter[k][j][i] = dequant_coef[k][j][i] << 4;
                LevelScale4x4Chroma_Inter[c][k][j][i] = quant_coef[k][j][i];
                InvLevelScale4x4Chroma_Inter[c][k][j][i] = dequant_coef[k][j][i] << 4;
            }
        }
}
