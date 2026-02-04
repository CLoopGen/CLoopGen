#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

short b8mode[4];
short b8pdir[4];
int i;
Macroblock *currMB;

void init_vars() {
    currMB = (Macroblock*)malloc(sizeof(Macroblock));
    if (!currMB) {
        exit(1);
    }

    for (int j = 0; j < 4; j++) {
        currMB->b8mode[j] = j;
        currMB->b8pdir[j] = j * 2;
    }

    currMB->currSEnr = 1;
    currMB->slice_nr = 2;
    currMB->delta_qp = 3;
    currMB->qp = 28;
    currMB->qpsp = 4;
    for (int j = 0; j < 8; j++) {
        currMB->bitcounter[j] = j * 100;
    }
    currMB->mb_available_up = NULL;
    currMB->mb_available_left = NULL;
    currMB->mb_type = 5;
    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 4; b++)
            for (int c = 0; c < 4; c++)
                for (int d = 0; d < 2; d++)
                    currMB->mvd[a][b][c][d] = a + b + c + d;
    for (int j = 0; j < 16; j++) {
        currMB->intra_pred_modes[j] = j;
        currMB->intra_pred_modes8x8[j] = j + 1;
    }
    currMB->cbp = 0xF;
    currMB->cbp_blk = 0xFFFF;
    currMB->cbp_bits = 0xABCDEF;
    currMB->lf_disable = 0;
    currMB->lf_alpha_c0_offset = 1;
    currMB->lf_beta_offset = 2;
    currMB->c_ipred_mode = 3;
    currMB->IntraChromaPredModeFlag = 1;
    currMB->mb_field = 0;
    currMB->mbAddrA = 1;
    currMB->mbAddrB = 2;
    currMB->mbAddrC = 3;
    currMB->mbAddrD = 4;
    currMB->mbAvailA = 1;
    currMB->mbAvailB = 1;
    currMB->mbAvailC = 1;
    currMB->mbAvailD = 1;
    currMB->all_blk_8x8 = 1;
    currMB->luma_transform_size_8x8_flag = 0;
    currMB->NoMbPartLessThan8x8Flag = 1;
    currMB->bi_pred_me = 0;
    currMB->actj = 1.5;
    currMB->prev_qp = 27;
    currMB->prev_delta_qp = 2;
    currMB->prev_cbp = 0xE;
    currMB->predict_qp = 28;
    currMB->predict_error = 0;
    currMB->LFDisableIdc = 0;
    currMB->LFAlphaC0Offset = 1;
    currMB->LFBetaOffset = 1;
    currMB->skip_flag = 0;
}