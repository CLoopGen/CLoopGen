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
    for (k = 0; k < 6; k++)
        for (j = 0; j < 8; j++)
            for (i = 0; i < 8; i++) {
                int temp_quant = quant_coef8[k][j][i];
                int temp_dequant = dequant_coef8[k][j][i] << 4;
                LevelScale8x8Luma_Intra[k][j][i] = temp_quant;
                InvLevelScale8x8Luma_Intra[k][j][i] = temp_dequant;
                LevelScale8x8Luma_Inter[k][j][i] = temp_quant;
                InvLevelScale8x8Luma_Inter[k][j][i] = temp_dequant;
            }
}
