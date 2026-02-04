#include <stdio.h>

#include <inttypes.h>

extern int LevelScale8x8Luma_Intra[6][8][8];
extern int LevelScale8x8Luma_Inter[6][8][8];
extern int InvLevelScale8x8Luma_Intra[6][8][8];
extern int InvLevelScale8x8Luma_Inter[6][8][8];
extern const int quant_coef8[6][8][8];
extern const int dequant_coef8[6][8][8];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification using strided access with step size 2, unrolled by factor 2
    // This variant accesses elements in a strided manner, skipping every other element in each dimension,
    // then fills in the remaining elements in a second pass to maintain correctness.
    for (k = 0; k < 6; k++)
        for (j = 0; j < 8; j += 2)
            for (i = 0; i < 8; i += 2) {
                // Stride-2 access: process (j,i), (j,i+1), (j+1,i), (j+1,i+1) in block fashion
                int j1 = j + 1;
                int i1 = i + 1;

                LevelScale8x8Luma_Intra[k][j][i] = quant_coef8[k][j][i];
                InvLevelScale8x8Luma_Intra[k][j][i] = dequant_coef8[k][j][i] << 4;
                LevelScale8x8Luma_Inter[k][j][i] = quant_coef8[k][j][i];
                InvLevelScale8x8Luma_Inter[k][j][i] = dequant_coef8[k][j][i] << 4;

                if (i1 < 8) {
                    LevelScale8x8Luma_Intra[k][j][i1] = quant_coef8[k][j][i1];
                    InvLevelScale8x8Luma_Intra[k][j][i1] = dequant_coef8[k][j][i1] << 4;
                    LevelScale8x8Luma_Inter[k][j][i1] = quant_coef8[k][j][i1];
                    InvLevelScale8x8Luma_Inter[k][j][i1] = dequant_coef8[k][j][i1] << 4;
                }

                if (j1 < 8) {
                    LevelScale8x8Luma_Intra[k][j1][i] = quant_coef8[k][j1][i];
                    InvLevelScale8x8Luma_Intra[k][j1][i] = dequant_coef8[k][j1][i] << 4;
                    LevelScale8x8Luma_Inter[k][j1][i] = quant_coef8[k][j1][i];
                    InvLevelScale8x8Luma_Inter[k][j1][i] = dequant_coef8[k][j1][i] << 4;

                    if (i1 < 8) {
                        LevelScale8x8Luma_Intra[k][j1][i1] = quant_coef8[k][j1][i1];
                        InvLevelScale8x8Luma_Intra[k][j1][i1] = dequant_coef8[k][j1][i1] << 4;
                        LevelScale8x8Luma_Inter[k][j1][i1] = quant_coef8[k][j1][i1];
                        InvLevelScale8x8Luma_Inter[k][j1][i1] = dequant_coef8[k][j1][i1] << 4;
                    }
                }
            }
}
