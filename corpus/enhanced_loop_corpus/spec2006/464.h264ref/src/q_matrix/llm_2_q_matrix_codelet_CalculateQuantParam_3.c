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



void loop() {
    // Variant 1: Change memory access pattern to use linear indexing with consecutive access
    // Instead of [k][j][i], we flatten the 3D iteration into a single loop with stride calculation.
    // This improves spatial locality and enables better vectorization opportunities.

    int idx, k, j, i, temp;
    const int quant_shift = 1 << 4; // Precompute shift value

    for (idx = 0; idx < 6 * 4 * 4; idx++) {
        k = idx / 16;
        j = (idx / 4) % 4;
        i = idx % 4;
        temp = (i << 2) + j;

        int q_coef = quant_coef[k][j][i];
        int dq_coef = dequant_coef[k][j][i];

        if ((!present[0]) || UseDefaultScalingMatrix4x4Flag[0]) {
            LevelScale4x4Luma_Intra[k][j][i] = (q_coef * quant_shift) / Quant_intra_default[temp];
            InvLevelScale4x4Luma_Intra[k][j][i] = dq_coef * Quant_intra_default[temp];
        } else {
            LevelScale4x4Luma_Intra[k][j][i] = (q_coef * quant_shift) / ScalingList4x4[0][temp];
            InvLevelScale4x4Luma_Intra[k][j][i] = dq_coef * ScalingList4x4[0][temp];
        }

        if (!present[1]) {
            LevelScale4x4Chroma_Intra[0][k][j][i] = LevelScale4x4Luma_Intra[k][j][i];
            InvLevelScale4x4Chroma_Intra[0][k][j][i] = InvLevelScale4x4Luma_Intra[k][j][i];
        } else {
            short divisor = UseDefaultScalingMatrix4x4Flag[1] ? Quant_intra_default[temp] : ScalingList4x4[1][temp];
            LevelScale4x4Chroma_Intra[0][k][j][i] = (q_coef * quant_shift) / divisor;
            InvLevelScale4x4Chroma_Intra[0][k][j][i] = dq_coef * divisor;
        }

        if (!present[2]) {
            LevelScale4x4Chroma_Intra[1][k][j][i] = LevelScale4x4Chroma_Intra[0][k][j][i];
            InvLevelScale4x4Chroma_Intra[1][k][j][i] = InvLevelScale4x4Chroma_Intra[0][k][j][i];
        } else {
            short divisor = UseDefaultScalingMatrix4x4Flag[2] ? Quant_intra_default[temp] : ScalingList4x4[2][temp];
            LevelScale4x4Chroma_Intra[1][k][j][i] = (q_coef * quant_shift) / divisor;
            InvLevelScale4x4Chroma_Intra[1][k][j][i] = dq_coef * divisor;
        }

        if ((!present[3]) || UseDefaultScalingMatrix4x4Flag[3]) {
            LevelScale4x4Luma_Inter[k][j][i] = (q_coef * quant_shift) / Quant_inter_default[temp];
            InvLevelScale4x4Luma_Inter[k][j][i] = dq_coef * Quant_inter_default[temp];
        } else {
            LevelScale4x4Luma_Inter[k][j][i] = (q_coef * quant_shift) / ScalingList4x4[3][temp];
            InvLevelScale4x4Luma_Inter[k][j][i] = dq_coef * ScalingList4x4[3][temp];
        }

        if (!present[4]) {
            LevelScale4x4Chroma_Inter[0][k][j][i] = LevelScale4x4Luma_Inter[k][j][i];
            InvLevelScale4x4Chroma_Inter[0][k][j][i] = InvLevelScale4x4Luma_Inter[k][j][i];
        } else {
            short divisor = UseDefaultScalingMatrix4x4Flag[4] ? Quant_inter_default[temp] : ScalingList4x4[4][temp];
            LevelScale4x4Chroma_Inter[0][k][j][i] = (q_coef * quant_shift) / divisor;
            InvLevelScale4x4Chroma_Inter[0][k][j][i] = dq_coef * divisor;
        }

        if (!present[5]) {
            LevelScale4x4Chroma_Inter[1][k][j][i] = LevelScale4x4Chroma_Inter[0][k][j][i];
            InvLevelScale4x4Chroma_Inter[1][k][j][i] = InvLevelScale4x4Chroma_Inter[0][k][j][i];
        } else {
            short divisor = UseDefaultScalingMatrix4x4Flag[5] ? Quant_inter_default[temp] : ScalingList4x4[5][temp];
            LevelScale4x4Chroma_Inter[1][k][j][i] = (q_coef * quant_shift) / divisor;
            InvLevelScale4x4Chroma_Inter[1][k][j][i] = dq_coef * divisor;
        }
    }
}
