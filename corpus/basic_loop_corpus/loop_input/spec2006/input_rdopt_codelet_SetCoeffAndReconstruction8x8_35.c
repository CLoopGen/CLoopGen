#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef int64_t int64;

typedef struct macroblock {
    int currSEnr;
    int slice_nr;
    int delta_qp;
    int qp;
    int qpsp;
    int bitcounter[8];
    struct macroblock *mb_available_up;
    struct macroblock *mb_available_left;
    int mb_type;
    int mvd[2][4][4][2];
    int intra_pred_modes[16];
    int intra_pred_modes8x8[16];
    int cbp;
    int64 cbp_blk;
    int b8mode[4];
    int b8pdir[4];
    unsigned long cbp_bits;
    int lf_disable;
    int lf_alpha_c0_offset;
    int lf_beta_offset;
    int c_ipred_mode;
    int IntraChromaPredModeFlag;
    int mb_field;
    int mbAddrA;
    int mbAddrB;
    int mbAddrC;
    int mbAddrD;
    int mbAvailA;
    int mbAvailB;
    int mbAvailC;
    int mbAvailD;
    int all_blk_8x8;
    int luma_transform_size_8x8_flag;
    int NoMbPartLessThan8x8Flag;
    int bi_pred_me;
    double actj;
    int prev_qp;
    int prev_delta_qp;
    int prev_cbp;
    int predict_qp;
    int predict_error;
    int LFDisableIdc;
    int LFAlphaC0Offset;
    int LFBetaOffset;
    int skip_flag;
} Macroblock;

short part8x8pdir[4] = {0, 0, 0, 0};
int part8x8mode[4] = {0, 0, 0, 0};
Macroblock *currMB;
int i;

void init_vars() {
    currMB = (Macroblock*)malloc(sizeof(Macroblock));
    if (!currMB) exit(1);
    currMB->mb_available_up = NULL;
    currMB->mb_available_left = NULL;
    currMB->cbp_blk = 0LL;
    currMB->cbp_bits = 0UL;
    currMB->actj = 0.0;
    currMB->predict_error = 0;
    for (int j = 0; j < 8; j++) {
        currMB->bitcounter[j] = 0;
    }
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 4; k++) {
            for (int l = 0; l < 4; l++) {
                currMB->mvd[j][k][l][0] = 0;
                currMB->mvd[j][k][l][1] = 0;
            }
        }
    }
    for (int j = 0; j < 16; j++) {
        currMB->intra_pred_modes[j] = 0;
        currMB->intra_pred_modes8x8[j] = 0;
    }
    for (int j = 0; j < 4; j++) {
        currMB->b8mode[j] = 0;
        currMB->b8pdir[j] = 0;
    }
}