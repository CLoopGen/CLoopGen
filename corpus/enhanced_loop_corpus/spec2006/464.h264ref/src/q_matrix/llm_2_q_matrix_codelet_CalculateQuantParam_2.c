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
    // Variant 1: Consecutive Memory Access via Flattened Indexing
    // We flatten the 3D iteration into a single loop for better spatial locality.
    int idx;
    for (idx = 0; idx < 6 * 4 * 4; idx++) {
        int k = idx / (4 * 4);
        int j = (idx % (4 * 4)) / 4;
        int i = idx % 4;

        LevelScale4x4Luma_Intra[k][j][i] = quant_coef[k][j][i];
        InvLevelScale4x4Luma_Intra[k][j][i] = dequant_coef[k][j][i] << 4;
        LevelScale4x4Chroma_Intra[0][k][j][i] = quant_coef[k][j][i];
        InvLevelScale4x4Chroma_Intra[0][k][j][i] = dequant_coef[k][j][i] << 4;
        LevelScale4x4Chroma_Intra[1][k][j][i] = quant_coef[k][j][i];
        InvLevelScale4x4Chroma_Intra[1][k][j][i] = dequant_coef[k][j][i] << 4;
        LevelScale4x4Luma_Inter[k][j][i] = quant_coef[k][j][i];
        InvLevelScale4x4Luma_Inter[k][j][i] = dequant_coef[k][j][i] << 4;
        LevelScale4x4Chroma_Inter[0][k][j][i] = quant_coef[k][j][i];
        InvLevelScale4x4Chroma_Inter[0][k][j][i] = dequant_coef[k][j][i] << 4;
        LevelScale4x4Chroma_Inter[1][k][j][i] = quant_coef[k][j][i];
        InvLevelScale4x4Chroma_Inter[1][k][j][i] = dequant_coef[k][j][i] << 4;
    }
}
