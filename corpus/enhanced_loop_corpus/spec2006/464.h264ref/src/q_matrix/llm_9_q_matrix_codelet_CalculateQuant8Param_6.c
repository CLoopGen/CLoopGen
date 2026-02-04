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
for (k = 0; k < 3; k++)
    for (j = 0; j < 8; j++)
        for (i = 0; i < 8; i += 2) {
            LevelScale8x8Luma_Intra[k][j][i] = quant_coef8[k][j][i];
            InvLevelScale8x8Luma_Intra[k][j][i] = dequant_coef8[k][j][i] << 4;
            if (i + 1 < 8) {
                LevelScale8x8Luma_Intra[k][j][i+1] = quant_coef8[k][j][i+1];
                InvLevelScale8x8Luma_Intra[k][j][i+1] = dequant_coef8[k][j][i+1] << 4;
            }
            LevelScale8x8Luma_Inter[k][j][i] = quant_coef8[k][j][i];
            InvLevelScale8x8Luma_Inter[k][j][i] = dequant_coef8[k][j][i] << 4;
            if (i + 1 < 8) {
                LevelScale8x8Luma_Inter[k][j][i+1] = quant_coef8[k][j][i+1];
                InvLevelScale8x8Luma_Inter[k][j][i+1] = dequant_coef8[k][j][i+1] << 4;
            }
        }
}
