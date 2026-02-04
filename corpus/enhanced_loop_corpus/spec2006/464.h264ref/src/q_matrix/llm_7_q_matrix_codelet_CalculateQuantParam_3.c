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



void loop(){
    int k, j, i;
    int temp;

    // Eliminate all loop-carried dependencies by unrolling and privatizing intermediate calculations
    // All operations are now independent across iterations

    for (k = 0; k < 6; k++) {
        for (j = 0; j < 4; j++) {
            for (i = 0; i < 4; i++) {
                temp = (i << 2) + j;

                // Fully independent computation per iteration with no cross-iteration state
                const int q_coef = quant_coef[k][j][i];
                const int dq_coef = dequant_coef[k][j][i];

                // Luma Intra
                if ((!present[0]) || UseDefaultScalingMatrix4x4Flag[0]) {
                    LevelScale4x4Luma_Intra[k][j][i] = (q_coef << 4) / Quant_intra_default[temp];
                    InvLevelScale4x4Luma_Intra[k][j][i] = dq_coef * Quant_intra_default[temp];
                } else {
                    LevelScale4x4Luma_Intra[k][j][i] = (q_coef << 4) / ScalingList4x4[0][temp];
                    InvLevelScale4x4Luma_Intra[k][j][i] = dq_coef * ScalingList4x4[0][temp];
                }

                // Chroma Intra 0
                if (!present[1]) {
                    LevelScale4x4Chroma_Intra[0][k][j][i] = LevelScale4x4Luma_Intra[k][j][i];
                    InvLevelScale4x4Chroma_Intra[0][k][j][i] = InvLevelScale4x4Luma_Intra[k][j][i];
                } else {
                    short divisor1 = UseDefaultScalingMatrix4x4Flag[1] ? Quant_intra_default[temp] : ScalingList4x4[1][temp];
                    LevelScale4x4Chroma_Intra[0][k][j][i] = (q_coef << 4) / divisor1;
                    InvLevelScale4x4Chroma_Intra[0][k][j][i] = dq_coef * divisor1;
                }

                // Chroma Intra 1
                if (!present[2]) {
                    LevelScale4x4Chroma_Intra[1][k][j][i] = LevelScale4x4Chroma_Intra[0][k][j][i];
                    InvLevelScale4x4Chroma_Intra[1][k][j][i] = InvLevelScale4x4Chroma_Intra[0][k][j][i];
                } else {
                    short divisor2 = UseDefaultScalingMatrix4x4Flag[2] ? Quant_intra_default[temp] : ScalingList4x4[2][temp];
                    LevelScale4x4Chroma_Intra[1][k][j][i] = (q_coef << 4) / divisor2;
                    InvLevelScale4x4Chroma_Intra[1][k][j][i] = dq_coef * divisor2;
                }

                // Luma Inter
                if ((!present[3]) || UseDefaultScalingMatrix4x4Flag[3]) {
                    LevelScale4x4Luma_Inter[k][j][i] = (q_coef << 4) / Quant_inter_default[temp];
                    InvLevelScale4x4Luma_Inter[k][j][i] = dq_coef * Quant_inter_default[temp];
                } else {
                    LevelScale4x4Luma_Inter[k][j][i] = (q_coef << 4) / ScalingList4x4[3][temp];
                    InvLevelScale4x4Luma_Inter[k][j][i] = dq_coef * ScalingList4x4[3][temp];
                }

                // Chroma Inter 0
                if (!present[4]) {
                    LevelScale4x4Chroma_Inter[0][k][j][i] = LevelScale4x4Luma_Inter[k][j][i];
                    InvLevelScale4x4Chroma_Inter[0][k][j][i] = InvLevelScale4x4Luma_Inter[k][j][i];
                } else {
                    short divisor4 = UseDefaultScalingMatrix4x4Flag[4] ? Quant_inter_default[temp] : ScalingList4x4[4][temp];
                    LevelScale4x4Chroma_Inter[0][k][j][i] = (q_coef << 4) / divisor4;
                    InvLevelScale4x4Chroma_Inter[0][k][j][i] = dq_coef * divisor4;
                }

                // Chroma Inter 1
                if (!present[5]) {
                    LevelScale4x4Chroma_Inter[1][k][j][i] = LevelScale4x4Chroma_Inter[0][k][j][i];
                    InvLevelScale4x4Chroma_Inter[1][k][j][i] = InvLevelScale4x4Chroma_Inter[0][k][j][i];
                } else {
                    short divisor5 = UseDefaultScalingMatrix4x4Flag[5] ? Quant_inter_default[temp] : ScalingList4x4[5][temp];
                    LevelScale4x4Chroma_Inter[1][k][j][i] = (q_coef << 4) / divisor5;
                    InvLevelScale4x4Chroma_Inter[1][k][j][i] = dq_coef * divisor5;
                }
            }
        }
    }
}
