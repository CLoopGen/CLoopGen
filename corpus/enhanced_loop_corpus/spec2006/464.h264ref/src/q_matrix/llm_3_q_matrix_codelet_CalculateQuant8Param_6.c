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
    // Variant 2: Memory Access Pattern Modification using consecutive linear indexing
    // Flatten the 3D array access into a single loop with linear index calculation
    // to improve spatial locality and enable better vectorization potential.
    int idx;
    const int J_SIZE = 8;
    const int I_SIZE = 8;
    const int TOTAL = 6 * J_SIZE * I_SIZE;

    for (idx = 0; idx < TOTAL; idx++) {
        int k = idx / (J_SIZE * I_SIZE);
        int rem = idx % (J_SIZE * I_SIZE);
        int j = rem / I_SIZE;
        int i = rem % I_SIZE;

        LevelScale8x8Luma_Intra[k][j][i] = quant_coef8[k][j][i];
        InvLevelScale8x8Luma_Intra[k][j][i] = dequant_coef8[k][j][i] << 4;
        LevelScale8x8Luma_Inter[k][j][i] = quant_coef8[k][j][i];
        InvLevelScale8x8Luma_Inter[k][j][i] = dequant_coef8[k][j][i] << 4;
    }
}
