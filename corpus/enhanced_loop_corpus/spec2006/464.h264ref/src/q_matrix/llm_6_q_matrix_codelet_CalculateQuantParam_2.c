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
                int temp_quant = quant_coef[k][j][i];
                int temp_dequant = dequant_coef[k][j][i] << 4;
                
                LevelScale4x4Luma_Intra[k][j][i] = temp_quant;
                InvLevelScale4x4Luma_Intra[k][j][i] = temp_dequant;
                LevelScale4x4Chroma_Intra[0][k][j][i] = temp_quant;
                InvLevelScale4x4Chroma_Intra[0][k][j][i] = temp_dequant;
                LevelScale4x4Chroma_Intra[1][k][j][i] = temp_quant;
                InvLevelScale4x4Chroma_Intra[1][k][j][i] = temp_dequant;
                LevelScale4x4Luma_Inter[k][j][i] = temp_quant;
                InvLevelScale4x4Luma_Inter[k][j][i] = temp_dequant;
                LevelScale4x4Chroma_Inter[0][k][j][i] = temp_quant;
                InvLevelScale4x4Chroma_Inter[0][k][j][i] = temp_dequant;
                LevelScale4x4Chroma_Inter[1][k][j][i] = temp_quant;
                InvLevelScale4x4Chroma_Inter[1][k][j][i] = temp_dequant;
            }
}
