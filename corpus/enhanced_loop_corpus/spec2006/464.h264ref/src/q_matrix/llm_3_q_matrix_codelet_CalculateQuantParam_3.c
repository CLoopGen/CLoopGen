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
    // Variant 2: Strided memory access - reorder loops to iterate over spatial position first (i,j),
    // then over the outer dimension (k). This changes access from k-j-i to i-j-k order,
    // creating more regular and strided patterns across k-dimension for fixed (i,j).

    int i, j, k, temp;
    const int quant_shift = 1 << 4;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            temp = (i << 2) + j; // Compute once per (i,j)

            for (k = 0; k < 6; k++) {
                int q_coef = quant_coef[k][j][i];
                int dq_coef = dequant_coef[k][j][i];
                short default_intra_val = Quant_intra_default[temp];
                short default_inter_val = Quant_inter_default[temp];

                // Luma Intra
                if ((!present[0]) || UseDefaultScalingMatrix4x4Flag[0]) {
                    LevelScale4x4Luma_Intra[k][j][i] = (q_coef * quant_shift) / default_intra_val;
                    InvLevelScale4x4Luma_Intra[k][j][i] = dq_coef * default_intra_val;
                } else {
                    short scaling_val = ScalingList4x4[0][temp];
                    LevelScale4x4Luma_Intra[k][j][i] = (q_coef * quant_shift) / scaling_val;
                    InvLevelScale4x4Luma_Intra[k][j][i] = dq_coef * scaling_val;
                }

                // Chroma Intra 0
                if (!present[1]) {
                    LevelScale4x4Chroma_Intra[0][k][j][i] = LevelScale4x4Luma_Intra[k][j][i];
                    InvLevelScale4x4Chroma_Intra[0][k][j][i] = InvLevelScale4x4Luma_Intra[k][j][i];
                } else {
                    short divisor = UseDefaultScalingMatrix4x4Flag[1] ? default_intra_val : ScalingList4x4[1][temp];
                    LevelScale4x4Chroma_Intra[0][k][j][i] = (q_coef * quant_shift) / divisor;
                    InvLevelScale4x4Chroma_Intra[0][k][j][i] = dq_coef * divisor;
                }

                // Chroma Intra 1
                if (!present[2]) {
                    LevelScale4x4Chroma_Intra[1][k][j][i] = LevelScale4x4Chroma_Intra[0][k][j][i];
                    InvLevelScale4x4Chroma_Intra[1][k][j][i] = InvLevelScale4x4Chroma_Intra[0][k][j][i];
                } else {
                    short divisor = UseDefaultScalingMatrix4x4Flag[2] ? default_intra_val : ScalingList4x4[2][temp];
                    LevelScale4x4Chroma_Intra[1][k][j][i] = (q_coef * quant_shift) / divisor;
                    InvLevelScale4x4Chroma_Intra[1][k][j][i] = dq_coef * divisor;
                }

                // Luma Inter
                if ((!present[3]) || UseDefaultScalingMatrix4x4Flag[3]) {
                    LevelScale4x4Luma_Inter[k][j][i] = (q_coef * quant_shift) / default_inter_val;
                    InvLevelScale4x4Luma_Inter[k][j][i] = dq_coef * default_inter_val;
                } else {
                    short scaling_val = ScalingList4x4[3][temp];
                    LevelScale4x4Luma_Inter[k][j][i] = (q_coef * quant_shift) / scaling_val;
                    InvLevelScale4x4Luma_Inter[k][j][i] = dq_coef * scaling_val;
                }

                // Chroma Inter 0
                if (!present[4]) {
                    LevelScale4x4Chroma_Inter[0][k][j][i] = LevelScale4x4Luma_Inter[k][j][i];
                    InvLevelScale4x4Chroma_Inter[0][k][j][i] = InvLevelScale4x4Luma_Inter[k][j][i];
                } else {
                    short divisor = UseDefaultScalingMatrix4x4Flag[4] ? default_inter_val : ScalingList4x4[4][temp];
                    LevelScale4x4Chroma_Inter[0][k][j][i] = (q_coef * quant_shift) / divisor;
                    InvLevelScale4x4Chroma_Inter[0][k][j][i] = dq_coef * divisor;
                }

                // Chroma Inter 1
                if (!present[5]) {
                    LevelScale4x4Chroma_Inter[1][k][j][i] = LevelScale4x4Chroma_Inter[0][k][j][i];
                    InvLevelScale4x4Chroma_Inter[1][k][j][i] = InvLevelScale4x4Chroma_Inter[0][k][j][i];
                } else {
                    short divisor = UseDefaultScalingMatrix4x4Flag[5] ? default_inter_val : ScalingList4x4[5][temp];
                    LevelScale4x4Chroma_Inter[1][k][j][i] = (q_coef * quant_shift) / divisor;
                    InvLevelScale4x4Chroma_Inter[1][k][j][i] = dq_coef * divisor;
                }
            }
        }
    }
}
