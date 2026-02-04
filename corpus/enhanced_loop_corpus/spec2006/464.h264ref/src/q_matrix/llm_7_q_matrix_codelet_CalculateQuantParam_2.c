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
    // Introduce loop-carried dependence by splitting initialization across iterations
    // Simulate WAW and WAR dependencies via ordered updates across arrays
    for (k = 0; k < 6; k++)
        for (j = 0; j < 4; j++)
            for (i = 0; i < 4; i++) {
                // First, write to Luma arrays
                LevelScale4x4Luma_Intra[k][j][i] = quant_coef[k][j][i];
                LevelScale4x4Luma_Inter[k][j][i] = quant_coef[k][j][i];

                // WAR-like: reuse updated Luma values to influence Chroma initialization (artificial dependence)
                if (k > 0) {
                    // Create loop-carried dependence: current iteration depends on previous k-1
                    LevelScale4x4Chroma_Intra[0][k][j][i] = LevelScale4x4Luma_Intra[k-1][j][i];
                    LevelScale4x4Chroma_Inter[0][k][j][i] = LevelScale4x4Luma_Inter[k-1][j][i];
                } else {
                    LevelScale4x4Chroma_Intra[0][k][j][i] = quant_coef[k][j][i];
                    LevelScale4x4Chroma_Inter[0][k][j][i] = quant_coef[k][j][i];
                }

                // Independent but reordered: dequant-based assignments
                InvLevelScale4x4Luma_Intra[k][j][i] = dequant_coef[k][j][i] << 4;
                InvLevelScale4x4Luma_Inter[k][j][i] = dequant_coef[k][j][i] << 4;

                // WAW: overwrite same index in chroma with possibly different source
                LevelScale4x4Chroma_Intra[1][k][j][i] = quant_coef[k][j][i];
                LevelScale4x4Chroma_Inter[1][k][j][i] = quant_coef[k][j][i];

                InvLevelScale4x4Chroma_Intra[0][k][j][i] = dequant_coef[k][j][i] << 4;
                InvLevelScale4x4Chroma_Intra[1][k][j][i] = dequant_coef[k][j][i] << 4;
                InvLevelScale4x4Chroma_Inter[0][k][j][i] = dequant_coef[k][j][i] << 4;
                InvLevelScale4x4Chroma_Inter[1][k][j][i] = dequant_coef[k][j][i] << 4;
            }
}
