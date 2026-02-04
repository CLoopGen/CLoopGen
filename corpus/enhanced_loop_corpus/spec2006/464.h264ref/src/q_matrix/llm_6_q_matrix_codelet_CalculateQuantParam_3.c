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
    // Introduce local accumulators to create artificial WAW and WAR dependencies
    int acc_Luma_Intra[6][4][4] = {0};
    int acc_Chroma_Intra[2][6][4][4] = {0};
    int acc_Luma_Inter[6][4][4] = {0};
    int acc_Chroma_Inter[2][6][4][4] = {0};

    for (k = 0; k < 6; k++)
        for (j = 0; j < 4; j++)
            for (i = 0; i < 4; i++) {
                temp = (i << 2) + j;

                // Simulate write-after-write (WAW) dependency by using accumulator
                acc_Luma_Intra[k][j][i] = (quant_coef[k][j][i] << 4);
                if ((!present[0]) || UseDefaultScalingMatrix4x4Flag[0]) {
                    acc_Luma_Intra[k][j][i] /= Quant_intra_default[temp];
                } else {
                    acc_Luma_Intra[k][j][i] /= ScalingList4x4[0][temp];
                }
                LevelScale4x4Luma_Intra[k][j][i] = acc_Luma_Intra[k][j][i];
                InvLevelScale4x4Luma_Intra[k][j][i] = dequant_coef[k][j][i] * 
                    ((UseDefaultScalingMatrix4x4Flag[0] || !present[0]) ? 
                     Quant_intra_default[temp] : ScalingList4x4[0][temp]);

                // Chroma Intra: introduce WAR by reusing updated Luma values before full commit
                if (!present[1]) {
                    acc_Chroma_Intra[0][k][j][i] = LevelScale4x4Luma_Intra[k][j][i]; // RAW on Luma_Intra
                } else {
                    acc_Chroma_Intra[0][k][j][i] = (quant_coef[k][j][i] << 4) / 
                        (UseDefaultScalingMatrix4x4Flag[1] ? Quant_intra_default[temp] : ScalingList4x4[1][temp]);
                }
                LevelScale4x4Chroma_Intra[0][k][j][i] = acc_Chroma_Intra[0][k][j][i];
                InvLevelScale4x4Chroma_Intra[0][k][j][i] = dequant_coef[k][j][i] * 
                    (UseDefaultScalingMatrix4x4Flag[1] ? Quant_intra_default[temp] : ScalingList4x4[1][temp]);

                if (!present[2]) {
                    LevelScale4x4Chroma_Intra[1][k][j][i] = LevelScale4x4Chroma_Intra[0][k][j][i]; // WAR dependency
                } else {
                    LevelScale4x4Chroma_Intra[1][k][j][i] = (quant_coef[k][j][i] << 4) / 
                        (UseDefaultScalingMatrix4x4Flag[2] ? Quant_intra_default[temp] : ScalingList4x4[2][temp]);
                }
                InvLevelScale4x4Chroma_Intra[1][k][j][i] = dequant_coef[k][j][i] * 
                    (UseDefaultScalingMatrix4x4Flag[2] ? Quant_intra_default[temp] : ScalingList4x4[2][temp]);

                acc_Luma_Inter[k][j][i] = (quant_coef[k][j][i] << 4);
                if ((!present[3]) || UseDefaultScalingMatrix4x4Flag[3]) {
                    acc_Luma_Inter[k][j][i] /= Quant_inter_default[temp];
                } else {
                    acc_Luma_Inter[k][j][i] /= ScalingList4x4[3][temp];
                }
                LevelScale4x4Luma_Inter[k][j][i] = acc_Luma_Inter[k][j][i];
                InvLevelScale4x4Luma_Inter[k][j][i] = dequant_coef[k][j][i] * 
                    ((UseDefaultScalingMatrix4x4Flag[3] || !present[3]) ? 
                     Quant_inter_default[temp] : ScalingList4x4[3][temp]);

                if (!present[4]) {
                    acc_Chroma_Inter[0][k][j][i] = LevelScale4x4Luma_Inter[k][j][i]; // RAW dependency
                } else {
                    acc_Chroma_Inter[0][k][j][i] = (quant_coef[k][j][i] << 4) / 
                        (UseDefaultScalingMatrix4x4Flag[4] ? Quant_inter_default[temp] : ScalingList4x4[4][temp]);
                }
                LevelScale4x4Chroma_Inter[0][k][j][i] = acc_Chroma_Inter[0][k][j][i];
                InvLevelScale4x4Chroma_Inter[0][k][j][i] = dequant_coef[k][j][i] * 
                    (UseDefaultScalingMatrix4x4Flag[4] ? Quant_inter_default[temp] : ScalingList4x4[4][temp]);

                if (!present[5]) {
                    LevelScale4x4Chroma_Inter[1][k][j][i] = LevelScale4x4Chroma_Inter[0][k][j][i]; // WAR
                } else {
                    LevelScale4x4Chroma_Inter[1][k][j][i] = (quant_coef[k][j][i] << 4) / 
                        (UseDefaultScalingMatrix4x4Flag[5] ? Quant_inter_default[temp] : ScalingList4x4[5][temp]);
                }
                InvLevelScale4x4Chroma_Inter[1][k][j][i] = dequant_coef[k][j][i] * 
                    (UseDefaultScalingMatrix4x4Flag[5] ? Quant_inter_default[temp] : ScalingList4x4[5][temp]);
            }
}
